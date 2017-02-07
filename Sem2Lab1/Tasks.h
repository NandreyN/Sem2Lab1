#pragma once
#include <string>

class Tasks
{
public:
	static void TaskOne();
	static void TaskTwo(const std::string&, char);
	static void TaskThree();
private:
	bool initial(const std::string&,char);
};

