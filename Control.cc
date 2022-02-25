#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Control.h"

Control::Control(){
  
}

Control::~Control(){
 for(int i=0; i < reports.size(); i++){
    delete reports[i];
  }
  reports.clear();
}

void Control::launch(){
  initReports();
  initData();
  int choice;
 
  while (1) {
    view.showMenu(choice);
    if(choice == 0){
		break;
	}

   if (choice == 1) {
   	 ReportOne* tempOne;
   	 reports.at(0)->compute();
   	 tempOne = (ReportOne*)reports[0];
   	 tempOne->printReport();
  
    }

    if (choice == 2) {
    	 ReportTwo* tempTwo;
    	 reports.at(1)->compute();
    	 tempTwo = (ReportTwo*)reports[1];
    	 tempTwo->printReport();
    }

    if (choice == 3) {
       ReportThree* tempThree;
    	 reports.at(2)->compute();
    	 tempThree = (ReportThree*)reports[2];
    	 tempThree->printReport();
    }

  }
}

void Control::initData(){

  ReportGenerator::populateData();
 
}

void Control::initReports(){
	ReportOne* one = new ReportOne();
	ReportTwo* two = new ReportTwo();
	ReportThree* three = new ReportThree();
	reports.push_back(one);
	reports.push_back(two);
	reports.push_back(three);
	
	
}


