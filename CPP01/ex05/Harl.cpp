#include "Harl.h"
#include "Harl.hpp"

/* ============== Constructor & Destructor ============== */

Harl::Harl() {}

Harl::~Harl() {}

/* ============== Private Function ============== */

void Harl::debug( void )
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info( void )
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning( void )
{
	std::cout << WARNING_MSG << std::endl;
}

void Harl::error( void )
{
	std::cout << ERROR_MSG << std::endl;
}


void Harl::complain(std::string level)
{
	std::string actions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func_tab[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (actions[i] == level){
			(this->*func_tab[i])();
			return ;
		}
	}
	std::cout << INPUT_ERROR << std::endl;
	return ;
}
