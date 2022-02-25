/**
	Fareha Sultan - 100968491 
	COMP2404 - Professor Laurendeau - Final Project
	ReportGenerator Class - an abstract base class. 
**/

#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Record.h"
#include "Map.h"



class ReportGenerator{
	public:
		ReportGenerator();
		~ReportGenerator();
		static void populateData(); //member function loads all the records from the census data file and populates the primary collection + maps
		virtual void compute() = 0; //pure virtual void function
		//void cleanup();
	protected:
		static vector<Record*> primaryCollection; //a static data member that stores the collection of all the records read in from the census data file
		static Map<int> yearMap; //year map to organize records for each census year
		static Map<string> regionMap; //region map to organize records by records
		static Map<string> animalMap; //animal map to organize records by animal type
};

#endif
