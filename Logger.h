#pragma once
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "Employee.h"

class Logger
{
public:
	Logger(std::string new_path_to_file, const std::vector<Employee>& new_database);
	
	void SetNewPathToFile(std::string new_path_to_file);
	void SetNewDatabase(const std::vector<Employee>& new_database);

	void GenerateMonthlyReport() const;

private:
	std::string path_to_file;
	std::vector<Employee> database;
};

