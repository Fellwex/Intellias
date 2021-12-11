#pragma once
#include <string>
#include "Data.h"

class Employee
{
public:
	Employee();
	
	Employee(std::string new_name, std::string new_email, std::string new_department,
		std::string new_position, std::string new_project, std::string new_task,
		Date new_date, int new_logged_hours);

	std::string GetName() const;
	std::string GetEmail() const;
	std::string GetDepartment() const;
	std::string GetPosition() const;
	std::string GetProject() const;
	std::string GetTask() const;
	Date GetDate() const;
	int GetLoggedHours() const;
	
private:
	std::string name, email, department;
	std::string position, project, task;
	Date date;
	int logged_hours;
};

