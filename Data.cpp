#include "Data.h"

Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int new_year, int new_month, int new_day)
{
    year = new_year;
    month = new_month;
    day = new_day;
}

int Date::GetYear() const
{
    return year;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetDay() const
{
    return day;
}