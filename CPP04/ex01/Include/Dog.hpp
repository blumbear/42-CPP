#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	protected:
		std::string type;
	private:
		Brain* brain;

	public:
/* ================= Canonical Form ================= */

		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);

/* ===================== getter ===================== */

		std::string getType() const;

/* ================= Member Function ================= */

		void makeSound() const;
};