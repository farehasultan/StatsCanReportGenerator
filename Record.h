#ifndef RECORD_H
#define RECORD_H


class Record{
	friend ostream& operator<<(ostream&, Record&);
  	public:
     	Record(int,string,string,string, int, int); //<year region subRegion animalType numFarms numAnimals>
  	 	~Record();
  	 	int getYear();
  	 	string getRegion();
  	 	string getSubRegion();
  	 	string getAnimalType();
  	 	int getNumFarms();
  	 	int getNumAnimals();
  	  
 	  
	private:
		int year;
		string region; //province or territory
		string subRegion;
		string animalType;
		int numFarms;
		int numAnimals;
};
#endif
