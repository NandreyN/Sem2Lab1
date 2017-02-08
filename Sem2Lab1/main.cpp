#include <iostream>
#include "Tasks.h"
using namespace std;

int main()
{
	try
	{
		Tasks::TaskOne();
		Tasks::TaskTwo("inT2.txt", 'P');
		Tasks::TaskThree("inT3.txt", 5, 15, true);
	}
	catch (exception e)
	{
		cout << "Exception caught : " << e.what() << endl;
	}
	return 0;
}