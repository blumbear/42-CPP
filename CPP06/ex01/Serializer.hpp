#pragma once

#include "Data.hpp"
#include <cstdint>
#include <iostream>

class Serializer {
	protected:
		Serializer();
		Serializer(const Serializer &other);

	public:
	/* ================= Canonical Form ================= */

		~Serializer();
		Serializer &operator=(const Serializer &other);

	/* ================= Member Function ================= */

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};
