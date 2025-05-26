#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	protected:
		std::string type;

	public:
/* ================= Canonical Form ================= */

		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);

/* ===================== getter ===================== */

		std::string getType() const;

/* ================= Member Function ================= */

		void makeSound() const;
};