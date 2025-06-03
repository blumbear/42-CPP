#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	protected:
		std::string type;

	public:
/* ================= Canonical Form ================= */

		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();
		WrongCat &operator=(const WrongCat &other);

/* ===================== getter ===================== */

		std::string getType() const;

/* ================= Member Function ================= */

		void makeSound() const;
};