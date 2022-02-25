using namespace std;
#include <vector>
#include <algorithm>
#include "ReportTwo.h"

ReportTwo::ReportTwo(){
	behaviour = new AscBehaviour<float>();
	reportData = new ReportData<float>(behaviour);
}


ReportTwo::~ReportTwo(){
	delete behaviour;
    	delete reportData;
}


void ReportTwo::compute(){
	//total animals because the first and second cols = 100%
	int totalAnimals2011 = 0;
	int totalAnimals2016 = 0;
	//number of rows = type of animals
	int rows = animalMap.getKeySize();
	//an array that will store the numAnimals for each year
	int numAnimalArr2011[rows];
	int numAnimalArr2016[rows];
	vector <string> animalTypeRows;

	for (int i=0; i< regionMap.getKeySize(); i++){
	string anim = animalMap.getKeyAt(i);
	if(! (find(animalTypeRows.begin(), animalTypeRows.end(), anim )!= animalTypeRows.end()) )
		animalTypeRows.push_back(animalMap.getKeyAt(i));
	}
	
	
	vector<Record*> yearData;
	yearData = yearMap[2011];
	for(int i = 0; i < yearData.size(); i++){
		Record* tmpRec; //temporary record
		tmpRec = yearData[i];
		if(tmpRec->getRegion()=="CAN"){
			for(int j=0; j<animalTypeRows.size();j++){
				if(tmpRec->getAnimalType()==animalTypeRows[j]){
					numAnimalArr2011[j] += tmpRec->getNumAnimals();
					totalAnimals2011 += tmpRec->getNumAnimals();
				}
			}
		}
	}
	
	yearData = yearMap[2016];
	for(int i = 0; i < yearData.size(); i++){
		Record* tmpRec; //temporary record
		tmpRec = yearData[i];
		if(tmpRec->getRegion()=="CAN"){
			for(int j=0; j<animalTypeRows.size();j++){
				if(tmpRec->getAnimalType()==animalTypeRows[j]){
					numAnimalArr2016[j] += tmpRec->getNumAnimals();
					totalAnimals2016 += tmpRec->getNumAnimals();
				}
			}
		}
	}
	
	//now formatting the data
	for(int i = 0; i< animalTypeRows.size(); i++){
	float percent2011;
	float percent2016;
	float percentChange;
	percent2011 = ((float)numAnimalArr2011[i] / (float)totalAnimals2011)*100;
	percent2016 = ((float)numAnimalArr2016[i] / (float)totalAnimals2016)*100;
	percentChange = percent2016 - percent2011; //2.2.3
	formatData(animalTypeRows[i], percent2011, percent2016, percentChange);
		
	}
		
}

//https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
void ReportTwo::formatData(string type , float eleven , float sixteen , float change){
	stringstream ss;
  	ss << setw(15)<<type << setw(30) << fixed<< setprecision(1)<<eleven << setw(30) << fixed << setprecision(1)<< sixteen << setw(30)<< fixed << setprecision(1)<< change ;

  	reportData->add(change,ss.str());
}

void ReportTwo::printReport(){
	ofstream outfile("ReportTwo.txt", ios::out);
	if (!outfile) {
    		cout << "Error:  could not open file" << endl;
    		exit(1);
  	}

	stringstream ss;
	ss<<'\n';
	ss<<setw(60)<<"PERCENTAGE CHANGE OF ANIMALS (2011-2016)"<<setw(30)<<'\n';
	ss<<setw(60)<<"------------------------------------------"<<'\n';
	ss<<setw(45)<<"2011"<<setw(30)<<"2016"<<setw(30)<<"Change"<<endl;
	outfile << ss.str();
	cout <<ss.str();
  	cout<<*(reportData);
  	outfile<<*(reportData);
}

