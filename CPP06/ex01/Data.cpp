#include "Data.hpp"

/* ================= Canonical Form ================= */

Data::Data() : Serializer() {
	std::cout << "Data contructor " << std::endl;
	_data = nullptr;
}

Data::Data(const Data &other) {
	*this = other;
}

Data::~Data() {}

Data &Data::operator=(const Data &other) {
	if (this != &other)
		_data = other._data;
	return (*this);
}

/* ================= Getter/Setter ================= */

void* Data::getData() const {
	return (_data);
}