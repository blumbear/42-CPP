#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	public:
/* ================= Canonical Form ================= */

		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);

/* ===================== getter ===================== */

		std::string getType();

/* ================= Member Function ================= */

		void makeSound();
};