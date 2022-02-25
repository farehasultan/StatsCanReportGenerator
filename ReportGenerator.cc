#include <iostream>
using namespace std;
#include "ReportGenerator.h"

//initialize static vector
vector<Record*> ReportGenerator::primaryCollection; 
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap; 
Map<string> ReportGenerator::animalMap; 

ReportGenerator::ReportGenerator(){}
ReportGenerator::~ReportGenerator(){
	for(int i=0; i<primaryCollection.size(); i++){
		delete primaryCollection[i];
	}
	primaryCollection.clear();
}

void ReportGenerator::populateData(){
	//variables for the 6 fields in the in the input file : farms.dat
	int year;
	string region;
	string subRegion;
	string animalType;
	int numFarms;
	int numAnimals;
	Record* rec;
	
	ifstream infile("farms.dat", ios::in);
	
	if (!infile) {
		cout << "Error: could not open file" << endl;
		exit(1);
  	}
  	while(infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals ){
  		rec = new Record(year, region, subRegion, animalType, numFarms, numAnimals);
  		primaryCollection.push_back(rec);
  		
  		//Now , populating the Maps (3.4.2 b)
  		yearMap.add(rec->getYear(), rec);
  		regionMap.add(rec->getRegion(), rec);
  		animalMap.add(rec->getAnimalType(),rec);
  	}	
	infile.close(); //close file
}



