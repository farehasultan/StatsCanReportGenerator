/**
	Fareha Sultan - 100968491 
	COMP2404 - Professor Laurendeau - Final Project
	Report Three: lists the subregion within each region hosting the highest number of horses/ponies in the year 2016.
**/

#ifndef REPORTTHREE_H
#define REPORTTHREE_H
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

class ReportThree : public ReportGenerator{
	public:
		ReportThree();
		~ReportThree();
		virtual void compute();
		void printReport(); //uses the ReportData member to both print the report results to the screen and save them as a txt file.

	protected:
		void formatData(string, string, int); //takes the computed stats and uses them to populate the ReportData member
		
		ReportData<int>* reportData; //a data member to store the report results  in a specific order...
		CompareBehaviour<int>* behaviour;
};
#endif



