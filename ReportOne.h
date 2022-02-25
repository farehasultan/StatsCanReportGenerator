/**
	Fareha Sultan - 100968491 
	COMP2404 - Professor Laurendeau - Final Project
	ReportOne- a report listing the regional percentage breakdown of farms that hosted animals of each type in 2016.
	Each row represents a province or territory and each column represents a type of animal. Last column shows the region's percentage over all animals.
	Each cell represents that specific type of animal in that region over all regions.
**/

#ifndef REPORTONE_H
#define REPORTONE_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "ReportGenerator.h"
#include "Record.h"
#include "ReportData.h"
#include "CompareBehaviour.h"
#include "DescBehaviour.h"

class ReportOne : public ReportGenerator{
	public:
		ReportOne();
		~ReportOne();
		virtual void compute();
		void printReport(); //uses the ReportData member to both print the report results to the screen and save them as a txt file.

	protected:
		void formatData(string,float,float,float,float,float,float,float,float,float,float); //takes the computed stats and uses them to populate the ReportData member
		ReportData<float>* reportData; //a data member to store the report results  in a specific order...
		CompareBehaviour<float>* behaviour;
};
#endif



