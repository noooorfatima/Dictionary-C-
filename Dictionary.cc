/*
 * Dictionary.cc
 *
 *  Created on: Sep 25, 2019
 *      Author: nfatima
 */



#include <hc_list.h>	// gets files from /home/courses/include folder, thanks to -I flag on compiler
#include <hc_list_helpers.h>
#include <list> 	// gets C++ standard library files, thanks to C++ standard
#include <iostream>
#include "listDemos.h"
#include "Dictionary.h"

int valueAtIndex(list<int> l, int index){
	if (length(l)==0){
		return 0;
	}
	if (index==0){
			return head(l);
	}
		else {
			return valueAtIndex(rest(l), index-1);
	}
}
string keyAtIndex(list<string> l, int index){

	if (length(l)==0){
		string toReturn="empty";
		return toReturn;
	}
	if (index==0){

			return head(l);
	}
		else {
			return keyAtIndex(rest(l), index-1);
	}
}
list<string> addkeyToList(list<string> aList, int index, string key) //put s at the n index, remove if you have to
{
	using HaverfordCS::ez_list;
	if (empty(aList)) {
		list<string> toReturn = ez_list(key);
		return toReturn;
	}
	else if (index==0){
		return list<string>(key, rest(aList));
	}
	else{
		return list<string>(head(aList),addkeyToList(rest(aList), index-1, key));
	}
}
list<int> addValToList(list<int> aList, int index, int val) //put s at the n index, remove if you have to
{
	using HaverfordCS::ez_list;
	if (empty(aList)) {
		list<int> toReturn = ez_list(val);
		return toReturn;
	}
	else if (index==0){
		return list<int>(val, rest(aList));
	}
	else{
		return list<int>(head(aList),addValToList(rest(aList), index-1, val));
	}
}

Dictionary::Dictionary(Dictionary smaller, string key, int value){

	valSize = smaller.valSize+1;
	values= smaller.values;
	values=addValToList(values, valSize,value);

	keySize = smaller.keySize+1;
	keys= smaller.keys;
	keys=addkeyToList(keys, keySize,key);

}

Dictionary::Dictionary(){

}

bool  Dictionary::contains(string key) const
{
	return find(key, keys);

}
int  Dictionary::lookup(string key) const
{
	if (find (key, keys)==true){
		int index=index_of(key, keys);
		return valueAtIndex(values,index);
	}
	else{
		return -101;
	}

}
void  Dictionary::add(string key, int value)
{
	if(find(key, keys)==true){
		int index=index_of(key, keys);
		addValToList(values, index, value);
	}
	else{
	values=addValToList(values, valSize,value);
	valSize++;
	keys=addkeyToList(keys, keySize,key);
	keySize++;
	}

}
string  Dictionary::toCode()
{

	string toReturn="";
	for (int i=0;i<valSize;i++){
		toReturn = toReturn +"Dictionary(Dictionary(),"+keyAtIndex(keys,i)+","+std::to_string(valueAtIndex(values,i)) + ")" +'\n';

	}
	return toReturn;

}


