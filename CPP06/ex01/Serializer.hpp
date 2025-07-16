#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
	int _value;
	std::string _name;
};

class Serializer {
	private:
	/* ================= Canonical Form ================= */

		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		Serializer &operator=(const Serializer &other);

		
	public:
		
	/* ================= Member Function ================= */

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
