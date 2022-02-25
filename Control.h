#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include "View.h"
#include "ReportGenerator.h"
#include "ReportOne.h"
#include "ReportTwo.h"
#include "ReportThree.h"


class Control{
  public:
      Control(); 
	  ~Control();
	  void launch(); 
	  void initData();

  private:
	  View view; 
	  void initReports();
	  vector<ReportGenerator*> reports; 
};

#endif
