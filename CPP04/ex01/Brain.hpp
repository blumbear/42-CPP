#pragma once

#include "Animal.h"
#include <string>
#include <iostream>

class Brain {
	private :
		std::string ideas[100];

	public :
/* ================= Constructor & Destructor ================= */

		Brain();
		Brain(const Brain &other);
		~Brain();
};