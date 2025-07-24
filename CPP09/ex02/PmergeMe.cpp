#include "PmergeMe.hpp"

/* ================= Canonical Form ================= */

Data::Data() : _ltime(0), _vtime(0), _containerSize(0) {}

Data::Data(const Data &other) {*this = other;}

Data::~Data() {}

Data &Data::operator=(const Data &other) {
	if (this != &other) {
		_vector = other._vector;
		_list = other._list;
		_ltime = other._ltime;
		_vtime = other._vtime;
		_containerSize = other._containerSize;
	}
	return (*this);
}

/* ===================== Getter ===================== */

std::vector<int>	Data::getVector() {return _vector;}

std::list<int>	Data::getList() {return _list;}

/* ================= Member Function ================= */

void Data::printVector() {
	for (int i = 0; _vector[i]; i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
}

void	Data::printList() {
	 for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}