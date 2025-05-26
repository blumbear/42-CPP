#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	public:
/* ================= Canonical Form ================= */

		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);

/* ===================== getter ===================== */

		std::string getType();

/* ================= Member Function ================= */

		void makeSound();
};