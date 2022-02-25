fp:	main.o Record.o View.o ReportGenerator.o ReportOne.o ReportTwo.o ReportThree.o Control.o
	g++ -o fp main.o Record.o View.o ReportGenerator.o ReportOne.o ReportTwo.o ReportThree.o Control.o

main.o:	main.cc Control.h
	g++ -g -c main.cc

Record.o:	Record.cc Record.h
	g++ -g -c Record.cc
	
View.o: View.cc View.h
	g++ -g -c View.cc
	
ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Map.h Record.h
	g++ -g -c ReportGenerator.cc
	
ReportOne.o: ReportOne.cc ReportOne.h Record.h ReportData.h CompareBehaviour.h DescBehaviour.h
	g++ -g -c ReportOne.cc
	
ReportTwo.o:	ReportTwo.cc ReportTwo.h Record.h ReportData.h CompareBehaviour.h AscBehaviour.h
	g++ -g -c ReportTwo.cc
	
ReportThree.o:	ReportThree.cc ReportThree.h Record.h ReportData.h CompareBehaviour.h DescBehaviour.h
	g++ -g -c ReportThree.cc

Control.o:	Control.cc Control.h Map.h Record.h View.h ReportOne.h ReportTwo.h
	g++ -g -c Control.cc

clean:
	rm -f *.o *.txt *.h~ *.cc~ fp 

