#pragma once
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include "Employee.h"

class Parser
{
public:
	Parser(std::string new_path_to_file, char new_delimiter);
	std::pair<bool, std::vector<Employee>> ParsingResult();

	void SetNewPathToFile(std::string new_path_to_file);
	void SetNewDelimiter(char new_delimiter);
	long long GetLastParsingTime() const;
private:
	std::string path_to_file;
	char delimiter;
	long long parsing_time;
};

