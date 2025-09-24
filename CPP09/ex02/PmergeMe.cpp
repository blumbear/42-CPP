#include "PmergeMe.hpp"
#include <algorithm>

/* ============= Private Member Function ============= */

/* ================= Canonical Form ================= */

MergeInsertSort::MergeInsertSort() : _containerSize(0) {}

MergeInsertSort::MergeInsertSort(const MergeInsertSort &other) {*this = other;}

MergeInsertSort::~MergeInsertSort() {}

MergeInsertSort &MergeInsertSort::operator=(const MergeInsertSort &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
		_dtime = other._dtime;
		_vtime = other._vtime;
		_containerSize = other._containerSize;
	}
	return (*this);
}

/* ===================== Getter ===================== */

std::vector<int>	MergeInsertSort::getVector() {return _vector;}

std::deque<int>	MergeInsertSort::getList() {return _deque;}

double	MergeInsertSort::getvtime() {return _vtime;}

double	MergeInsertSort::getdtime() {return _dtime;}

/* ================= Member Function ================= */

void MergeInsertSort::printVector() {
	if (_vector.empty()) {
		std::cout << "Vector is empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
}

void	MergeInsertSort::printVector(std::vector<int> container) {
	if (container.empty()) {
		std::cout << "Vector is empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

void	MergeInsertSort::printList() {
	 for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void MergeInsertSort::parse(char **array) {
	int tmp = 0;
	for (int i = 0; array[i]; i++) {
		tmp = atoi(array[i]);
		for (int j = 0; array[i][j]; j++) {
			if (!isdigit(array[i][j])) {
				std::cerr << ERROR_PROMPT << ARG_ERROR << std::endl;
				throw false;
			}

		}
		for (size_t x = 0; x < _vector.size(); x++) {
			if (_vector[x] == tmp) {
				std::cout << "Doublon error." << std::endl;
				throw false;
			}
		}
		_vector.push_back(tmp);
		_deque.push_back(tmp);
	}
}

void MergeInsertSort::compute() {
	timeval tmp;
	timeval tmpb;

	gettimeofday(&tmp, NULL);
	_vector = sortVector(_vector);
	gettimeofday(&tmpb, NULL);
	_vtime = (tmpb.tv_sec - tmp.tv_sec) * 1000000 + (double)(tmpb.tv_usec - tmp.tv_usec) ;
	// if (!isSorted(_vector)) {
	// 	std::cout << "vector is not sort." << std::endl;
	// 	return ;
	// }
	// else 
	// 	std::cout << "vector is sort." << std::endl;
	gettimeofday(&tmp, NULL);
	_deque = sortVector(_deque);
	gettimeofday(&tmpb, NULL);
	_dtime = (tmpb.tv_sec - tmp.tv_sec) * 1000000 + (double)(tmpb.tv_usec - tmp.tv_usec) ;
	// if (!isSorted(_deque)) {
	// 	std::cout << "deque is not sort." << std::endl;
	// 	return ;
	// }
	// else 
	// 	std::cout << "deque is sort." << std::endl;
}