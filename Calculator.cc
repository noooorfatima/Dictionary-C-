/*
	StackInterface.cc
	This file contains all of the function definitions for the StackInterface.
	These will be used to generate the text interface for the stack

	Functions:
	Title			  		Description
	------------------------------------------
*/

/*----------Includes---------*/
#include <string>
#include <iostream>
#include <fstream>
#include <regex>  // check if something is numeric with a "regular expression" (coming up later)
#include <cstddef>
#include "Calculator.h"
#include "Dictionary.h"

// Note that we don't want to write both 'using namespace std' and 'using namespace HaverfordCS' because that would bring in two different definitions of lists
// Thus, it is o.k. to 'uncomment' _one_ of the following two lines, but don't do _both_.
// using HaverfordCS::list;	// like using namespace HaverfordCS, but just for one name
//using std::list;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
// std::ostream &trace = std::cerr; // or, use "fopen("/dev/null", "w")", or something like that, to turn off debugging
std::ofstream trace = std::ofstream("/dev/null"); // to turn off debugging

using std::string;

bool looksLikeInt(string s)
{
	std::regex intPattern("-?[0-9]+"); // optional minus followed by at least one numeral
	return std::regex_match(s, intPattern);
}


bool runCalculator()
{
	string prompt = " C> ";
	string token1, token2, token3, hopeForSemicolon;
	Dictionary d;

	cout << "Enter input for the calculator, and 'bye' when you're done" << endl << prompt;
	while (cin and cin >> token1 and token1 != "bye") {
		if (looksLikeInt(token1)) {
			trace << "thanks for entering the integer " << stoi(token1) << endl;
		} else {

			trace << "thanks for entering the non-integer token " << token1 << endl;
		}
//		trace << "line 52" << endl;
		cin >> token2;
		cin >> token3;
		cin >> hopeForSemicolon;

		trace << "received input " << token2 << " " << token3 << endl;
//		trace << "if we see this stoi works? " << stoi(token3) << endl;

		if (token1=="const" && looksLikeInt(token3)){
//			trace << "got const" << endl;
		d=Dictionary(d, token2, stoi(token3));

		}
		if (token1=="var" && looksLikeInt(token3)){
//			trace << "got var" << endl;
		d.add(token2, stoi(token3));

		}
		if (token1==":=" && looksLikeInt(token3)){
//			trace << "got assign" << endl;
		d.add(token2, stoi(token3));
		}
		if (token1=="?" ){
//			trace << "got ?" << endl;
			cout<< d.toCode() <<endl;
		}

//		cout << "past the ifs" << endl;

		//if (token2 != "+" && token2 != "-"&& token2 != "*"&& token2 != "=="&& token2 != "<=") {
			//cerr << "Sorry, only operator + is supported at this time" << endl;
			//return false;
		//}
//		if (not looksLikeInt(token1)) {
//			trace << "Sorry, first operand must be a number" << endl;
//			return false;
//		}
//		if (not looksLikeInt(token3)) {
//			trace << "Sorry, second operand must be a number" << endl;
//			return false;
//		}
//		if (!looksLikeInt(token1)) {
//			trace << "weird token 1 " << token1 << endl;
//		}
//		else {
//			trace << "int-looking token 1" << endl;
//			trace << "if we see this stoi should work " << stoi(token1) << endl;
//		}
		if (token2 == "+"){
			if (!looksLikeInt(token3) && !looksLikeInt(token1)){
				cout << (d.lookup(token1)) + (d.lookup(token3)) << endl;
			}
			else if (!looksLikeInt(token1)){
				cout << (d.lookup(token1)) + stoi(token3) << endl;
			}
			else if (!looksLikeInt(token3)){
				cout << stoi(token1) + (d.lookup(token3)) << endl;
			}
			else {
				cout << stoi(token1) + stoi(token3) << endl;
			}
		}
		if (token2 == "-"){
			if (!looksLikeInt(token3) && !looksLikeInt(token1)){
				cout << (d.lookup(token1)) - (d.lookup(token3)) << endl;
			}
			else if (!looksLikeInt(token1)){
				cout << (d.lookup(token1)) - stoi(token3) << endl;
			}
			else if (!looksLikeInt(token3)){
				cout << stoi(token1) - (d.lookup(token3)) << endl;
			}
			else {
				cout << stoi(token1) - stoi(token3) << endl;
			}
		}
		if (token2 == "*"){
			 if (!looksLikeInt(token3) && !looksLikeInt(token1)){
				cout << ((d.lookup(token1)) * (d.lookup(token3))) << endl;
			}
			 else if (!looksLikeInt(token1)){
				cout << (d.lookup(token1)) * stoi(token3) << endl;
			}
			else if (!looksLikeInt(token3)){
				cout << stoi(token1) * (d.lookup(token3)) << endl;
			}

			else {
				cout << stoi(token1) * stoi(token3) << endl;
			}
		}
		if (token2 == "=="){
			if (!looksLikeInt(token3) && !looksLikeInt(token1)){
				if (d.lookup(token3)==d.lookup(token1)){
				cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else if (!looksLikeInt(token3) ){
				if (d.lookup(token3)==stoi(token1)){
				cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else if (!looksLikeInt(token1)){
				if (d.lookup(token1)==stoi(token3)){
				cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else {
				cout << 0 << endl;
			}
		}
//		if (token2 == "==" && token3!=token1){
//		cout << 0 << endl;
//		}
		if (token2 == "<=" ){
			if (!looksLikeInt(token3) && !looksLikeInt(token1)){
				if (d.lookup(token3)>=d.lookup(token1)){
				cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else if (!looksLikeInt(token3) ){
				if (d.lookup(token3)>=stoi(token1)){
				cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else if (!looksLikeInt(token1)){
				if (d.lookup(token1)<=stoi(token3)){
				cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}
			else {
				cout << 0 << endl;
			}
		}
//		if (token2 == ">=" && token3>token1){
//		cout << 0 << endl;
//		}

	}
	return true;
}
