#pragma once

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;

	public:

/* ============ Constructor & Destructor ============ */

		Zombie();
		Zombie(std::string name);
		~Zombie();

/* ===================== Else ===================== */

		void announce( void );

};