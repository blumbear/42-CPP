#include "Serializer.hpp"

/* ================= Canonical Form ================= */

Serializer::Serializer() {
	std::cout << "Serializer contructor " << std::endl;
}

Serializer::Serializer(const Serializer &other) {*this = other;}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return (*this);
}

/* ================= Member Function ================= */

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}