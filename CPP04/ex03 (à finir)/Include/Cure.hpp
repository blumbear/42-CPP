#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AMateria.hpp"

class Cure : public AMateria {
	protected:
		std::string type;

	public:
/* =================== Canonical Form =================== */

		Cure();
		Cure(Cure& other);
		Cure &operator=(const Cure &other);
		~Cure();

/* ================= Member Function ================= */

		Cure* clone() const;
		void use(ICharacter& target);
};