#include "Parser.h"
#include "Logger.h"

int main()
{
	std::string inp_path, out_path;

	std::cout << "Enter path for input file: ";
	std::cin >> inp_path;

	std::cout << "Enter path for output file: ";
	std::cin >> out_path;

	Parser parser(inp_path, ';');
	std::pair<bool, std::vector<Employee>> result = parser.ParsingResult();
	if (result.first)
	{
		std::cout << "Parsing time: " << parser.GetLastParsingTime() << " ms" << std::endl;
		Logger logger(out_path, result.second);
		logger.GenerateMonthlyReport();
	}
	else
	{
		std::cout << "Parsing wasn't successful" << std::endl;
	}

	return 0;
}