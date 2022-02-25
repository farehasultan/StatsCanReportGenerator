#ifndef ASCBEHAVIOUR_H
#define ASCBEHAVIOUR_H 
#include <iostream>
using namespace std;
#include <cstdlib>
#include<string>
#include <iomanip>



#include "CompareBehaviour.h"

template <class T>
class AscBehaviour: public CompareBehaviour<T>{
	public:
		AscBehaviour();
		virtual bool compare(T,T);
};

template <class T>
AscBehaviour<T>::AscBehaviour(){}

template <class T>
bool AscBehaviour<T>::compare(T a, T b){
	if(a>b)
		return false;
	else
		return true;
}

#endif	

