/*
 * Dictionary.h
 *
 *  Created on: Sep 25, 2019
 *      Author: nfatima
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include <hc_list.h>
#include <array>
#include <string>
using std::string;
using HaverfordCS::list;


class Dictionary {

public:
	Dictionary(Dictionary smaller, string key, int value);
	Dictionary();
	bool contains(string key) const;
	int lookup(string key) const;
	void add(string key, int value);
	string toCode();
	int getValue(string key);
	void setValue(string key, int value);
//private:
	int valSize=0;
	int keySize=0;
	list<int> values;
	list<string> keys;
};

#endif /* DICTIONARY_H_ */
