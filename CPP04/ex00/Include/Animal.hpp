#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Animal {
	protected:
		std::string type;

	public:
/* ================= Canonical Form ================= */

		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);

/* ===================== getter ===================== */

		virtual std::string getType() const;

/* ================= Member Function ================= */

		virtual void makeSound() const;
};