#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AMateria.hpp"

class Ice : public AMateria {
	protected:
		std::string type;

	public:
/* =================== Canonical Form =================== */

		Ice();
		Ice(Ice& other);
		Ice &operator=(const Ice &other);
		~Ice();

/* ================= Member Function ================= */

		Ice* clone() const;
		void use(ICharacter& target);
};