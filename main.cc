/*
	main.cc
	This file contains the main function for the Stack class and text interface.
*/

/*-----------Includes---------*/
#include <iostream>

#include "listDemos.h"
#include "listPractice.h"
#include "Calculator.h"
#include "Dictionary.h"

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	Dictionary d;
	d=Dictionary(d, "X", 1);
	d.add("y", 2);
 d.add("y", 3);
	cout << d.toCode() << endl;

	cout << "***** First, some list demos:" << endl;
	hcListDemos();
	stdListDemo();
	cout << endl << endl;  // space between tests

	cout << "***** Now, the list practice, as described in the pre-lab" << endl;
	if (!testListPractice()) cout << "oops, it returns false" << endl;
	cout << endl << endl;  // space between tests
	

	cout << "***** Finally, the stack program (you'll need to write this, too):" << endl;

	if (runCalculator()) {
		// success
		cout << "Thanks for using the calculator demo" << endl;
		return 0;  // report success to operating system
	} else {
		cout << "Sorry it didn't work out too well" << endl;
		return 1;  // any non-zero counts as failure
	}
}
