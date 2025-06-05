#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string type;

	public:
/* ============== Constructor & Destructor ============== */

		AMateria(std::string const & type);

/* =================== Canonical Form =================== */

		AMateria();
		AMateria(AMateria& other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

/* ======================= Getter ======================= */

		std::string const & getType() const; //Returns the materia type

/* ================= Member Function ================= */

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};