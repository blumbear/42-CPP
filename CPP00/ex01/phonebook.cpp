#include <iostream>
#include <string>
#include <cstring>
#include "phonebook.hpp"

void find_command(std::string command)
{
	int tmp;

	if (std::strcmp(command, "ADD"))
		add_function();
	else if (std::strcmp(command, "SEARCH"))
		search_function();
	else if (std::strcmp(command, "EXIT"))
		exit_function();
	return ;
}

int main(void)
{
	std::string command;

	while(true)
	{
		std::getline (std::cin,command);
		find_command(command);
	}
	return(true);
}