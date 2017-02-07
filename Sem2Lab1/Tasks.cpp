#include "Tasks.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void Tasks::TaskOne()
{
	// Create vector<char> which contains symbols of alphabet
	//Print in direct and reverse order

	vector<char> charVector;
	for (char symbol = 'a'; symbol != 'z' + 1; symbol++)
		charVector.push_back(symbol);

	// Direct order printing
	for_each(charVector.begin(), charVector.end(), [](char c)->void {
		cout << c << endl;
	});

	//Reverse
	cout << "Reverse order : " << endl << endl;
	for_each(charVector.rbegin(), charVector.rend(), [](char c)->void {
		cout << c << endl;
	});
}

void Tasks::TaskTwo(const string& sourcePath) throw (invalid_argument)
{
	ifstream inputFile;
	inputFile.open(sourcePath);
	if (!inputFile.is_open())
		throw std::invalid_argument("Invalid file path");

	list<string> lst;

	while (!inputFile.eof())
	{
		string data;
		inputFile >> data;
		lst.push_back(data);
	}

	for_each(lst.begin(), lst.end(), [](auto s) {cout << s << endl; });
	
	cout << "done!" << endl;
}