/**
	Fareha Sultan - 100968491 
	COMP2404 - Professor Laurendeau - Final Project
	Map Template class 
**/

#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "Record.h"

template <class T > 
class Map{
	template <class V>
  	friend ostream& operator<<(ostream&, Map<V>&);
  
  	public:
  		void add(T,Record*);
  		int getKeySize();
  		vector<T>& getKeysCollection();
  		vector<Record*>& operator[](T);
    		T getKeyAt(int);

  	private:
    		vector <T> keys; //keys collection
    		vector<vector<Record*>> values;
    		
};




template <class T>
ostream& operator<<(ostream& output, Map<T>& m)
{ 
  output << "Key: " << m.key << ", Value: " << m.value << endl;

  return output;
}

template <class T>
void Map<T>::add(T key,Record* rec){

	for (int i = 0; i< keys.size(); i++){
		if(keys[i] == key ){
			values[i].push_back(rec);
		}
	}
	keys.push_back(key); 
	vector<Record*> newVal;
	newVal.push_back(rec);
	values.push_back(newVal);
}

template <class T>
int Map<T>:: getKeySize(){
	return keys.size();	
}
template <class T>
vector<T>& Map<T>:: getKeysCollection(){
	return keys;
}
template <class T>
T Map<T>::getKeyAt(int i){
	return keys.at(i);
}

template <class T>
vector<Record*>& Map<T>::operator[](T key){
	try{
		for(int i=0;i<keys.size();i++){
			if(keys[i]==key){
				return values[i];
			}
		}
	}
	catch(const T error){
		cout<<"Error given key not found "<<error<<endl;
	}
	
}



