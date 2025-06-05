#include "SedIsForLosers.h"

int	print_error(std::string Error)
{
	std::cout << Error << std::endl;
	return (0);
}

std::string replaceFunction(std::string fileContent, std::string str1, std::string str2)
{
	size_t	str1Pos = fileContent.find(str1);
	std::string res;

	while (str1Pos != std::string::npos)
	{
		res.append(fileContent, 0, str1Pos);
		fileContent.erase(0, str1Pos + str1.size());
		res += str2;
		str1Pos = fileContent.find(str1);
	}
	res += fileContent;
	return res;
}


int main(int ac, char **av)
{
	if (ac != 4)
		return (print_error(USAGE_ERROR));
	if (av[2][0] == 0)
		return (print_error(ARG_ERROR));
	std::ifstream infile(av[1]);
	if (!infile.is_open())
		return (print_error(FILE_ERROR));
	std::string newFileName = std::string(av[1]) + ".replace";
	std::ofstream newFile(newFileName.c_str());
	if (!newFile.is_open())
		return (print_error(NFILE_ERROR));
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string fileContent = buffer.str();
	newFile << replaceFunction(fileContent, std::string(av[2]), std::string(av[3]));
	return 1;
}