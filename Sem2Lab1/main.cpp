#include <iostream>
#include "Tasks.h"

using namespace std;

int main()
{
	Tasks::TaskOne();
	Tasks::TaskTwo("inT2.txt", 'H');
	Tasks::TaskThree("inT3.txt", 5,15,true);
}