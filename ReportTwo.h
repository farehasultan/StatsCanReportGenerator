/**
	Fareha Sultan - 100968491 
	COMP2404 - Professor Laurendeau - Final Project
	ReportTwo- Lists the animal type percentage breakdown for Canada as a whole. And lists the percentage change from 2011 to 2016.
	
**/

#ifndef REPORTTWO_H
#define REPORTTWO_H
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
#include "AscBehaviour.h"

class ReportTwo : public ReportGenerator{
	public:
		ReportTwo();
		~ReportTwo();
		virtual void compute();
		void printReport(); //uses the ReportData member to both print the report results to the screen and save them as a txt file.

	protected:
		void formatData(string, float, float, float); //takes the computed stats and uses them to populate the ReportData member
		
		ReportData<float>* reportData; //a data member to store the report results in a specific order...
		CompareBehaviour<float>* behaviour;
};
#endif



