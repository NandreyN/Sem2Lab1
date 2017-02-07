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

void Tasks::TaskTwo(const string& sourcePath, char filterParam) throw (invalid_argument)
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

	lst.sort([](string a, string b)->bool {return a < b; });

	for_each(lst.begin(), lst.end(), [](auto s) {cout << s << endl; }); // printing

	cout << "Removed strted by letter : " << endl << "/////////////////////////////////////////////////" << endl;
	// Printing only strings started with filterParam letter

	for_each(lst.begin(), lst.end(), [filterParam](const string& a)->void
	{
		if (a.c_str()[0] == filterParam)
			cout << a << endl;
	});

	auto iter = lst.begin();
	while(iter != lst.end())
	{
		if (iter->c_str()[0] == filterParam)
			lst.erase(iter++);
		else
			++iter;
	}

	cout << "After Deleting : " << endl;
	for_each(lst.begin(), lst.end(), [](auto s) {cout << s << endl; }); // printing
	cout << "done!" << endl;
}

bool Tasks::initial(const string& str, char init)
{
	return (str.c_str()[0] == init) ? true : false;
}