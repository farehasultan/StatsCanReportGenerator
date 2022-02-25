#include <iostream>
#include <string>
using namespace std;
#include "Record.h"

Record::Record(int y,string r,string sr ,string at, int nf, int na){ //<year region subRegion animalType numFarms numAnimals>
	year = y;
	region = r; //province or territory
	subRegion = sr;
	animalType = at;
	numFarms = nf;
	numAnimals = na;
}

Record::~Record(){
}


int Record::getYear(){
	return year;
}

string Record::getRegion(){ 
	return region; 
}

string Record::getSubRegion(){ return subRegion;  }
string Record:: getAnimalType(){ return animalType;}
int Record:: getNumFarms(){ return numFarms;}
int Record::getNumAnimals(){return numAnimals;}

ostream& operator<<(ostream& output, Record& record) //global function friend of Record
{
  output<< record.year <<" "<<record.region<<" "<<record.subRegion<<" "<<record.animalType<<" "<<record.numFarms<<" "<< record.numAnimals << endl;

  return output; //cout reference
}
