#include "Parser.h"

Parser::Parser(std::string new_path_to_file, char new_delimiter)
{
	path_to_file = new_path_to_file;
	delimiter = new_delimiter;
	parsing_time = 0;
}

std::pair<bool, std::vector<Employee>> Parser::ParsingResult()
{
	auto start = std::chrono::steady_clock::now();

	std::ifstream input(path_to_file);

	if (!input)
	{
		std::cerr << "Could not open the file" << std::endl;
		return { false, {} };
	}
	
	std::string line = "";
	std::vector<Employee> database;

	std::getline(input, line);

	if ("Name;email;department;position;project;task;date;logged hours" != line)
	{
		std::cerr << "Incorrect names of columns" << std::endl;
		return { false, {} };
	}
	
	int num_of_row = 1;
	while (std::getline(input, line))
	{
		std::stringstream buffer(line);

		std::string name = "", email = "", department = "";
		std::string position = "", project = "", task = "";
		Date date = { 0, 0, 0 };
		int logged_hours = 0;

		std::getline(buffer, name, delimiter);
		std::getline(buffer, email, delimiter);
		std::getline(buffer, department, delimiter); 
		std::getline(buffer, position, delimiter);
		std::getline(buffer, project, delimiter); 
		std::getline(buffer, task, delimiter);

		if (name.empty() || email.empty() || department.empty() 
			|| position.empty() || project.empty() || task.empty())
		{
			std::cerr << "Error occurred during parsing row # " << num_of_row << std::endl;
			return { false, {} };
		}

		int day = 0, month = 0, year = 0;
		
		buffer >> year;
		buffer.ignore(1);
		buffer >> month;
		buffer.ignore(1);
		buffer >> day;
		buffer.ignore(1);
		buffer >> logged_hours;

		if (buffer.fail())
		{
			std::cerr << "Error occurred during parsing row # " << num_of_row << std::endl;
			return { false, {} };
		}

		date = Date(year, month, day);
		database.push_back(Employee(name, email, department, position, project, task, date, logged_hours));
		num_of_row++;
	}

	auto finish = std::chrono::steady_clock::now();
	parsing_time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();

	return { true, database };
}

void Parser::SetNewPathToFile(std::string new_path_to_file)
{
	path_to_file = new_path_to_file;
}

void Parser::SetNewDelimiter(char new_delimiter)
{
	delimiter = new_delimiter;
}

long long Parser::GetLastParsingTime() const
{
	return parsing_time;
}

