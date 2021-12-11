#include "Logger.h"

Logger::Logger(std::string new_path_to_file, const std::vector<Employee>& new_database)
{
	path_to_file = new_path_to_file;
	database = new_database;
}

void Logger::SetNewPathToFile(std::string new_path_to_file)
{
	path_to_file = new_path_to_file;
}

void Logger::SetNewDatabase(const std::vector<Employee>& new_database)
{
	database = new_database;
}

void Logger::GenerateMonthlyReport() const
{
	std::ofstream output(path_to_file);

	const std::string months[12] = { "January", "February", "March", "April", "May", 
	  "June", "July", "August", "September", "October", "November", "December" };

	std::unordered_map<std::string, int> monthlyReport;

	for (const auto& i : database)
	{
		std::string key = i.GetName() + ";" + months[i.GetDate().GetMonth() - 1] + " " 
			+ std::to_string(i.GetDate().GetYear()) + ";";
		monthlyReport[key] += i.GetLoggedHours();
	}

	if (!monthlyReport.empty())
	{
		output << "Name;Month;Total hours" << std::endl;

		for (const auto& i : monthlyReport)
		{
			output << i.first << i.second << std::endl;
		}

		std::cout << "Monthly report was created successfully and written to file \"" << path_to_file << "\"" << std::endl;
	}
	else
	{
		std::cout << "Database is empty" << std::endl;
	}
}
