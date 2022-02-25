#ifndef DESCBEHAVIOUR_H
#define DESCBEHAVIOUR_H
#include <iostream>
using namespace std;
#include <cstdlib>
#include<string>
#include <iomanip>
#include "CompareBehaviour.h"

template <class T>
class DescBehaviour:public CompareBehaviour<T>{
	public:
		DescBehaviour();
		virtual bool compare(T,T);
};

template <class T>
DescBehaviour<T>::DescBehaviour(){}

template <class T>
bool DescBehaviour<T>::compare(T a, T b){
	if(a>b)
		return true;
	else
		return false;	
}

#endif

