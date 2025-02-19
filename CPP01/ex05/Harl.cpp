#include "Harl.h"
#include "Harl.hpp"

/* ============== Constructor & Destructor ============== */

Harl::Harl() {}

Harl::~Harl() {}

/* ============== Private Function ============== */

void Harl::debug( void )
{
	std::cout << DEBUG_MSG << '\n';
}

void Harl::info( void )
{
	std::cout << INFO_MSG << '\n';
}

void Harl::warning( void )
{
	std::cout << WARNING_MSG << '\n';
}

void Harl::error( void )
{
	std::cout << ERROR_MSG << '\n';
}


void Harl::complain(std::string level)
{
	std::map<std::string, void (Harl::*)()> actions;
	actions.insert(std::make_pair("DEBUG", &Harl::debug));
	actions.insert(std::make_pair("INFO", &Harl::info));
	actions.insert(std::make_pair("WARNING", &Harl::warning));
	actions.insert(std::make_pair("ERROR", &Harl::error));

	if (actions.find(level) != actions.end())
		(this->*actions[level])();
	else
		std::cout << INPUT_ERROR << '\n';
}
