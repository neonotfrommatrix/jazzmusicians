// write code here
//#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include "jazzmusicians.h"
#include <string>
#include <iostream>
#include <fstream>

void printmenu() {
	cout << "Menu:" << endl;
	cout << "N: New entry" << endl;
	cout << "P: print any order" << endl;
	cout << "D: Display by Instrument" << endl;
	cout << "M: Print the full name of the most prolific musician" << endl;
	cout << "Q: quit" << endl;
};

int main(void) {


	char input;
	string inst;

	//JM is the obhject identifier it has all the structs and stuff
	JazzMusicians JM("JazzMusicians.txt");

	// present operator with menu
	printmenu();

	cin >> input;

	string fname, lname, ins;
	int b, d, r;

	while (input != 'Q' && input != 'q') {
		switch (input) {
		case 'n':
		case 'N':
			// Add a new musician to the data store

			cout << "Enter First name ";
			cin >> fname;

			cout << "Enter last name ";
			cin >> lname;

			cout << "Enter instrument played ";
			cin >> ins;

			cout << "Enter year born ";
			cin >> b;

			cout << "Enter year died ";
			cin >> d;

			cout << "Enter num of recordings ";
			cin >> r;

			JM.addMusician(fname, lname, ins, b, d, r);

			break;

		case 'p':
		case 'P':

			// calls the function to print
			JM.printInAnyOrder();


			break;

		case 'd':
		case 'D':
			// Display musicians according to the instrument they play
			// for example, if the operator enters Bass, display all
			// musicians that play the Bass.  For the purposes of this
			// program bass and Bass are considered different instruments
			// since the capitalization differs.

			cout << "Which instrument would you like to search for?\n";
			cin >> ins;

			JM.DisplayByInstrument(ins);


			break;

		case 'm':
		case 'M':
			// Print the name of the musician that performed on the most
			// recordings per year on average.

			JM.printMostProlific();


			break;

		default:
			cout << "what happened?" << endl;
		};

		printmenu();
		cin >> input;

	}

	system("pause");
}

