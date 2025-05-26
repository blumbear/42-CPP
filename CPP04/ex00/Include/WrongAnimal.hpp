#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class WrongAnimal {
	protected:
		std::string type;

	public:
/* ================= Canonical Form ================= */

		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &other);

/* ===================== getter ===================== */

		virtual std::string getType() const;

/* ================= Member Function ================= */

		virtual void makeSound() const;

};