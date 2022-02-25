using namespace std;
#include <vector>
#include <algorithm>
#include "ReportOne.h"

ReportOne::ReportOne(){
	behaviour = new DescBehaviour<float>();
	reportData = new ReportData<float>(behaviour);
}


ReportOne::~ReportOne(){
	delete behaviour;
    	delete reportData;
}


void ReportOne::compute(){
	int totalCanFarms = 0;
	vector <string> animaltypes;
	for (int i=0; i< animalMap.getKeySize(); i++){
		string anim = animalMap.getKeyAt(i);
		if(! (find(animaltypes.begin(), animaltypes.end(), anim )!= animaltypes.end()) )
			animaltypes.push_back(animalMap.getKeyAt(i));
	}

	int allCanFarms[animaltypes.size()]; 
	
	vector<Record*> allFarms;
	allFarms = yearMap[2016];
	
	for(int i = 0; i < allFarms.size(); i++){
		Record* tmpRec; //temporary record
		tmpRec = allFarms[i];
		if(tmpRec->getRegion()=="CAN" && tmpRec->getSubRegion()== "All" ){
			for(int j=0; j<animaltypes.size();j++){
				if(tmpRec->getAnimalType()==animaltypes[j]){
					allCanFarms[j]=tmpRec->getNumFarms();
					totalCanFarms += tmpRec->getNumFarms();
				}
			}
		}
	}
	
	//now for the provinces...
	vector <string> provinces;
	for (int i=0; i< regionMap.getKeySize(); i++){
		string regi = regionMap.getKeyAt(i);
		if(! (find(provinces.begin(), provinces.end(), regi )!= provinces.end()) && regi != "CAN")
			provinces.push_back(regionMap.getKeyAt(i));
	}
	
	for (int x = 0; x< provinces.size(); x++){
	vector<Record*> allPro;
	allPro = regionMap[provinces[x]];
	int totalRegionalFarms = 0;
	float regionalFarms[animaltypes.size()]={0};
	for(int i = 0; i < allPro.size(); i++){
	Record* tmpRec; //temporary record
	tmpRec = allPro[i];
		if(tmpRec->getSubRegion()== "All" && tmpRec->getYear() ==2016){
			for(int j=0; j<animaltypes.size();j++){
				if(tmpRec->getAnimalType()==animaltypes[j]){
					regionalFarms[j]= (((float)tmpRec->getNumFarms()/(float)allCanFarms[j])*100);
					totalRegionalFarms += tmpRec->getNumFarms();
				}
			}
		}
		
	}
	float totals = (((float)totalRegionalFarms/(float)totalCanFarms)*100);
formatData(provinces[x],regionalFarms[0],regionalFarms[1],regionalFarms[2],regionalFarms[3],regionalFarms[4],regionalFarms[5],regionalFarms[6],
		regionalFarms[7],regionalFarms[8], totals);
		
}	
}


void ReportOne::formatData(string reg,float a,float b,float c,float d,float e,float f,float g,float h,float i,float t){
	stringstream ss;
  	ss << setw(15)<<reg<<setw(15)<<fixed<<setprecision(1)<<a
  				    <<setw(15) << fixed<< setprecision(1)<<b
  				    <<setw(15) << fixed<< setprecision(1)<<c
  				    <<setw(15)<< fixed<< setprecision(1)<<d
  				    <<setw(15) << fixed<< setprecision(1)<<e
  				    <<setw(15) << fixed<< setprecision(1)<<f
  				    <<setw(15)<< fixed<< setprecision(1)<<g
  				    <<setw(15) << fixed<< setprecision(1)<<h
  				    <<setw(15) << fixed<< setprecision(1)<<i
  				    <<setw(15)<<fixed<< setprecision(1)<<t ;

  	reportData->add(t,ss.str());

}
void ReportOne::printReport(){
	ofstream outfile("ReportOne.txt", ios::out);
	if (!outfile) {
    		cout << "Error:  could not open file" << endl;
    		exit(1);
  	}
	//print to the screen:
	stringstream ss;
	ss<<'\n';
	ss<<setw(60)<<"PERCENTAGE OF FARMS BY REGION IN 2016"<<setw(30)<<'\n';
	ss<<setw(60)<<"------------------------------------------"<<'\n';
	ss<<setw(30)<<"Horses/Ponies"<<setw(15)<<"Goats"<<setw(15)<<"Llamas/Alpacas"<<setw(15)<<"Rabbits"<<setw(15)<<"Bison/Buffalo"<<setw(15)<<"Elk/Wapiti"<<setw(15)<<"Domestic Deer"<<setw(15)<<"Wile Boars" << setw(15)<<"Mink"<<setw(15) << "Totals"<<endl;
	outfile << ss.str();
	cout <<ss.str();
  	cout<<*(reportData);
  	outfile<<*(reportData);
}
