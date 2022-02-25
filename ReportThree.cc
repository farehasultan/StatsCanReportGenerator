using namespace std;
#include <vector>
#include "ReportThree.h"
#include <algorithm>


ReportThree::ReportThree(){
	behaviour = new DescBehaviour<int>();
	reportData = new ReportData<int>(behaviour);
}


ReportThree::~ReportThree(){
	delete behaviour;
    	delete reportData;
}


void ReportThree::compute(){
	vector <string> provinces;
	for (int i=0; i< regionMap.getKeySize(); i++){
		string regi = regionMap.getKeyAt(i);
		if(! (find(provinces.begin(), provinces.end(), regi )!= provinces.end()) && regi != "CAN")
			provinces.push_back(regionMap.getKeyAt(i));
	}
	string maxSubregion[provinces.size()] = {};
	int maxHorses[provinces.size()] = {0};
	vector<Record*> horseData;
	horseData = animalMap["Horses-Ponies"];
	
	for(int i = 0; i < horseData.size(); i++){
		Record* tmpRec; //temporary record
		tmpRec = horseData[i];
		if(tmpRec->getRegion()!="CAN" && tmpRec->getSubRegion()!= "All" && tmpRec->getYear()!=2011){
			for(int j=0; j<provinces.size();j++){
				if(tmpRec->getRegion()==provinces[j]){ //for ex . it is ON
					if(tmpRec->getNumAnimals() > maxHorses[j]){
						maxHorses[j] = tmpRec->getNumAnimals();
						maxSubregion[j] = tmpRec->getSubRegion();
						}
				}
			}
		}
	}
	
	//now formatting the data
	for(int i = 0; i< provinces.size(); i++){
		formatData(provinces[i], maxSubregion[i],maxHorses[i]);
	}
		
}

//https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
void ReportThree::formatData(string reg , string subreg, int hp){
	stringstream ss;
  	ss << setw(15)<<reg << setw(60) << subreg << setw(30) << hp ;

  	reportData->add(hp,ss.str());
}

void ReportThree::printReport(){
	ofstream outfile("ReportThree.txt", ios::out);
	if (!outfile) {
    		cout << "Error:  could not open file" << endl;
    		exit(1);
  	}
	//print to the screen:
	stringstream ss;
	ss<<'\n';
	ss<<setw(60)<<"SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016"<<setw(30)<<'\n';
	ss<<setw(60)<<"------------------------------------------"<<endl;
	outfile << ss.str();
	cout <<ss.str();
  	cout<<*(reportData);
  	outfile<<*(reportData);
}

