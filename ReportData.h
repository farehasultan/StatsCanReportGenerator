#ifndef REPORTDATA_H
#define REPORTDATA_H
#include <iostream>
using namespace std;
#include <cstdlib>
#include<vector>
#include<iterator>
#include<string>
#include <iomanip>
#include "CompareBehaviour.h"


template <class T>
class ReportData{
	template <class E>
	friend ostream& operator<<(ostream&,ReportData<E>&);
	
	template <class Q>
	class ReportRow{  //a nested class
		public:
			Q key;
			string row;
			ReportRow(Q k,string r){ key=k; row=r;}
	};
	
	public:
		ReportData(CompareBehaviour<T>*);
		~ReportData();
		void add(T,string);
	private:
		vector<ReportRow<T>> rowsCollection; //collection of report rows
		CompareBehaviour<T>* comp; 
};


template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* cb){
	comp=cb;
}


template <class T>
ReportData<T>::~ReportData(){
	rowsCollection.clear();
}

template <class T>
void ReportData<T>::add(T k, string row){	
		//https://stackoverflow.com/questions/5192874/question-about-vector-iterator-in-template-functions 	
		typename vector<ReportRow<T>>::iterator itr;
		
		if(rowsCollection.size()==0){
			rowsCollection.push_back(ReportRow<T>(k,row));
			return;
		}else
			itr = rowsCollection.begin();
			for(itr=rowsCollection.begin();itr!=rowsCollection.end();itr++){
				if(!comp->compare(itr->key, k)){
					break;}
			}
					
			
			rowsCollection.insert(itr,ReportRow<T>(k,row));		
}


template <class T>
ostream& operator<<(ostream& out,ReportData<T>& rd){
	for(int i =0; i<rd.rowsCollection.size(); i++){
		out << rd.rowsCollection[i].row <<endl;
	}
	return out;
}

#endif
















