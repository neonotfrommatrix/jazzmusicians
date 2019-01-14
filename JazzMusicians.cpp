// JazzMusuicans.cpp

// JazzMusicians.cpp : This file contains the 'main' function. Program execution begins and ends there.
// write code here

//#include "pch.h"
#include "stdafx.h"
#include "JazzMusicians.h"
#include <string>
#include <fstream>


JazzMusicians::JazzMusicians(string filename) {
	// read data from file
	// open
	//discard file
	// loop til end of end
	// 
	ifstream myFile;

	myFile.open("JazzMusicians.txt");

	string temp;
	for (int i = 0; i < 6; i++) {
		myFile >> temp;
	}


	while (!myFile.eof())
	{
		JazzMusician current; // declaring an object
							  // now read in each data piece into the struct

		myFile >> current.firstname >> current.lastname >> current.instrument >> current.yearborn >> current.yeardied >> current.numrecs;

		// musician storage is name of vector and you are pushing the struct info into the stack (back)
		MusicianStorage.push_back(current);
	}

	myFile.close();

}

void JazzMusicians::addMusician(string first, string last, string instr, int born, int died, int recs) {

	//make a struct
	//load with info given to you
	// push it back

	JazzMusician current;

	current.firstname = first;
	current.lastname = last;
	current.instrument = instr;
	current.yearborn = born;
	current.yeardied = died;
	current.numrecs = recs;

	MusicianStorage.push_back(current);



}

void JazzMusicians::DisplayByInstrument(string instrument) {
	// go through vector
	// check if each structs instrument is equal to the instrument made by user
	// display that info

	for (int i = 0; i < MusicianStorage.size(); i++) {

		if (MusicianStorage[i].instrument == instrument) {
			cout << MusicianStorage[i].firstname << " ";
			cout << MusicianStorage[i].lastname << " ";
			cout << MusicianStorage[i].instrument << " ";
			cout << MusicianStorage[i].yearborn << " ";
			cout << MusicianStorage[i].yeardied << " ";
			cout << MusicianStorage[i].numrecs << " \n";
		}

	}



}

void JazzMusicians::printInAnyOrder(void) {

	// print everything
	for (int i = 0; i < MusicianStorage.size(); i++) {

		cout << MusicianStorage[i].firstname << " ";
		cout << MusicianStorage[i].lastname << " ";
		cout << MusicianStorage[i].instrument << " ";
		cout << MusicianStorage[i].yearborn << " ";
		cout << MusicianStorage[i].yeardied << " ";
		cout << MusicianStorage[i].numrecs << " \n";

	}



}

void JazzMusicians::printMostProlific(void) {

	int i = -1;
	int mostProl = -1;


	for (int j = 0; j < MusicianStorage.size(); j++) {
		int avg = MusicianStorage[j].numrecs / (MusicianStorage[j].yeardied - MusicianStorage[j].yearborn);
		if (avg > mostProl)
		{
			mostProl = avg;
			i = j;
		}


	}
	cout << MusicianStorage[i].firstname << " ";
	cout << MusicianStorage[i].lastname << " ";
	cout << "is the most prolific musician he played an avg of " << mostProl << " recordings per year";
}


