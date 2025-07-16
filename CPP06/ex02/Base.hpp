#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Base {
	public :
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

/* ================= Other Function ================= */
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

