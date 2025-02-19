#pragma once 

#include <string> 
#include <iostream>
#include <map>

class Harl
{
	private:

/* ============== Private Function ============== */

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		int getLevelIndex(std::string level);

	public:

/* ============== Constructor & Destructor ============== */

		Harl();
		~Harl();

/* =================== Else =================== */

		void complain(std::string level);

};