#include "Tasks.h"
#include <vector>
#include <deque> 
#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <numeric>
#include <iterator>

using namespace std;

void Tasks::TaskOne()
{
	cout << "======================================================================================================================" << endl;
	cout << "TASK 1" << endl;
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
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "Reverse order : " << endl << endl;
	copy(charVector.cbegin(), charVector.cend(), std::ostream_iterator<char>(cout, "\n"));
}

void Tasks::TaskTwo(const string& sourcePath, char filterParam) throw (invalid_argument)
{
	cout << "======================================================================================================================" << endl;
	cout << "TASK 2" << endl;
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
	inputFile.close();
	
	lst.sort([](const string& a, const string& b)->bool {return a < b; });
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "Sorted" << endl;
	for_each(lst.begin(), lst.end(), [](auto s) {cout << s << endl; }); // printing

	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "Printed  by letter : " << endl;
	// Printing only strings started with filterParam letter
	
	copy_if(lst.begin(), lst.end(), ostream_iterator<string>(cout, "\n"), [filterParam](const string& a) {return a[0] == filterParam; });

	/*auto iter = lst.begin();
	while(iter != lst.end())
	{
		if (iter->c_str()[0] == filterParam)
			lst.erase(iter++); // postfix form to erase current element
		else
			++iter;
	}*

	/*Implement delete analog here*/
	remove_if(lst.begin(), lst.end(), [filterParam](const string& a)->bool
	{
		return a[0] == filterParam;
	});

	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "After Deleting : " << endl;
	for_each(lst.begin(), lst.end(), [](auto s) {cout << s << endl; }); // printing

	if (inputFile.is_open())
		throw ifstream::failure("Close file error");
}

void Tasks::TaskThree(const std::string& sourcePath, int compare1, int compare2, bool greater)
{
	cout << "========================================================================================================================" << endl;
	cout << "TASK 3" << endl;
	vector<int> vector;
	list<int> list;
	deque<int> deque;

	ifstream inputFile;
	inputFile.open(sourcePath);
	if (!inputFile.is_open())
		throw std::invalid_argument("Invalid file path");

	int numCount;
	inputFile >> numCount; // empty file?

	for (int i = 0; i < numCount; i++) // getting numbers from file
	{
		int data; inputFile >> data;
		vector.push_back(data);
		list.push_back(data);
		deque.push_back(data);
	}
	// can use deque.assign. list.assign

	int value1Vector = count(vector.begin(), vector.begin(), compare1);
	int value2List = count(list.begin(), list.begin(), compare1);
	int value3Deque = count(deque.begin(), deque.begin(), compare1);

	cout << "task 3.1  : equel to " << to_string(compare1) << endl;
	cout << "Vector : " << value1Vector << endl;
	cout << "List : " << value2List << endl;
	cout << "Deque : " << value3Deque << endl;

	auto funcForTask2 = [greater, compare2](int a)
	{
		if (greater)
			return a > compare2;
		else
			return a < compare2;
	};

	value1Vector = count_if(vector.begin(), vector.end(), funcForTask2);
	value2List = count_if(list.begin(), list.end(), funcForTask2);
	value3Deque = count_if(deque.begin(), deque.end(), funcForTask2);

	string messagetoOut = (greater) ? "greater than " : "less than";
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "task 3.2  : " << messagetoOut << compare2 << endl;
	cout << "Vector : " << value1Vector << endl;
	cout << "List : " << value2List << endl;
	cout << "Deque : " << value3Deque << endl;
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "task 3.3 : sizes" << endl;
	cout << "Vector : " << vector.size() << endl;
	cout << "List : " << list.size() << endl;
	cout << "Deque : " << deque.size() << endl;

	value1Vector = accumulate(vector.begin(), vector.end(), 0);
	value2List = accumulate(list.begin(), list.end(), 0);
	value3Deque = accumulate(deque.begin(), deque.end(), 0);
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "task 3.4: sum" << endl;
	cout << "Vector : " << value1Vector << endl;
	cout << "List : " << value2List << endl;
	cout << "Deque : " << value3Deque << endl;
	cout << "__________________________________________________________________________________________________________________" << endl;
	cout << "task 3.5: average" << endl;
	cout << "Vector : " << static_cast<double>(value1Vector) / vector.size() << endl;
	cout << "List : " << static_cast<double>(value2List) / list.size() << endl;
	cout << "Deque : " << static_cast<double>(value3Deque) / deque.size() << endl;

	inputFile.close();
	if (inputFile.is_open())
		throw ifstream::failure("Close file error"); // To add exception	
}