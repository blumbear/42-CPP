#include "Harl.h"
#include "Harl.hpp"

/* ============== Constructor & Destructor ============== */

Harl::Harl() {}

Harl::~Harl() {}

/* ============== Private Function ============== */

void Harl::debug( void )
{
	std::cout << DEBUG_MSG << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << INFO_MSG << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << WARNING_MSG << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << ERROR_MSG << std::endl << std::endl;
}

int Harl::getLevelIndex(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0 ; i <= 3 ; i++)
		if (level == levels[i])
			return i;
	return -1;
}

void Harl::complain(std::string level)
{
	switch (getLevelIndex(level))
	{
		case -1:
			std::cout << RANDOM_MSG << std::endl;
			break;
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			std::cerr << COMPLAIN_ERROR << std::endl;
			break;
	}
}
