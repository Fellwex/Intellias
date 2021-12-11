#include "Employee.h"

Employee::Employee()
{
	name = "";
	email = "";
	department = "";
	position = "";
	project = "";
	task = "";
	date = { 0, 0, 0 };
	logged_hours = 0;
}

Employee::Employee(std::string new_name, std::string new_email, std::string new_department,
	std::string new_position, std::string new_project, std::string new_task,
	Date new_date, int new_logged_hours)
{
	name = new_name;
	email = new_email;
	department = new_department;
	position = new_position;
	project = new_project;
	task = new_task;
	date = new_date;
	logged_hours = new_logged_hours;
}

std::string Employee::GetName() const
{
	return name;
}

std::string Employee::GetEmail() const
{
	return email;
}

std::string Employee::GetDepartment() const
{
	return department;
}

std::string Employee::GetPosition() const
{
	return position;
}

std::string Employee::GetProject() const
{
	return project;
}

std::string Employee::GetTask() const
{
	return task;
}

Date Employee::GetDate() const
{
	return date;
}

int Employee::GetLoggedHours() const
{
	return logged_hours;
}
