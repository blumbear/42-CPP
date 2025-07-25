#include "PmergeMe.hpp"

/* ============= Private Member Function ============= */
std::vector<int> MergeInsertSort::sortVector(std::vector<int> container) {
	std::vector<int> tmp;
	std::vector<int> tmpbis;
	size_t containerSize = container.size();

	if (containerSize == 2) {
		if (container[0] > container[1]) {
			int itmp = container[0];
			container[0] = container[1];
			container[1] = itmp;
		}
		return (container);
	}
	else if (containerSize == 1)
		return (container);
	for (size_t i = 0; i <= containerSize / 2 + (containerSize % 2 == 1) - 1; i++) 
		tmp.push_back(container[i]);
	// tmp = sortVector(tmp);
	for (size_t i = containerSize / 2 - (containerSize % 2 == 0) + 1; i < containerSize; i++)
		tmpbis.push_back(container[i]);
	container.clear();
	// tmpbis = sortVector(tmpbis);

	for (size_t i = 0 ; i < tmp.size(); i++) {container.push_back(tmp[i]);}
	std::vector<int>::iterator it;
	printVector(container);
	printVector(tmpbis);
	for (size_t i = 0 ; i < tmpbis.size(); i++) {

		size_t tmp = container.size();
		size_t startPos = 0;

		std::cout << "-------\n";
		printVector(container); std::cout << "size : " << tmp << std::endl;
		while (true) {
			std::cout << "tmp : " << tmp << std::endl;
			if (tmp == 1) {
				if (tmpbis[i] < container[startPos])
					container.insert(container.begin() + startPos , tmpbis[i]);
				else if (tmpbis[i] > container[startPos])
					container.insert(container.begin() + startPos + 1 , tmpbis[i]);
				std::cout << "A!" <<tmpbis[i]<<"!\n" ;
				break;
			}
			else if (tmp == 2) {
				if (tmpbis[i] < container[startPos])
					container.insert(container.begin() + startPos , tmpbis[i]);
				else if (tmpbis[i] > container[startPos] && tmpbis[i] < container[startPos + 1])
					container.insert(container.begin() + startPos + tmp , tmpbis[i]);
				else if (tmpbis[i] > container[startPos + 1])
					container.insert(container.begin() + startPos + tmp, tmpbis[i]);
				std::cout << "B!" <<tmpbis[i]<<"!\n" ;
				break;
			}
			if (tmp % 2 == 0) {
				tmp = tmp / 2 + (tmp % 2 == 1);
				if (tmpbis[i] > container[startPos + tmp] && tmpbis[i] < container[startPos + tmp + 1]) {
					container.insert(container.begin() + startPos + tmp + 1, tmpbis[i]);
					std::cout << "C!" <<tmpbis[i]<<"!\n" ;
					break;
				}
				else if (tmpbis[i] > container[startPos + tmp]){
					startPos += tmp;
				}
				std::cout << "tmpbis[i] : " << tmpbis[i] << " Acontainer[tmp] : " << container[startPos + tmp] << std::endl;
			}
			else {
				tmp = tmp / 2 + (tmp % 2 == 1);
				std::cout << "tmpbis[i] : " << tmpbis[i] << " Bcontainer[tmp] : " << container[startPos + tmp] << std::endl;
				if (tmpbis[i] > container[startPos + tmp]) {
					startPos += tmp;
				}
			}
			std::cout << "StartPos : " << startPos << std::endl;
		}
	}
	return (container);
}


/* ================= Canonical Form ================= */

MergeInsertSort::MergeInsertSort() : _vtime(0), _ltime(0), _containerSize(0) {}

MergeInsertSort::MergeInsertSort(const MergeInsertSort &other) {*this = other;}

MergeInsertSort::~MergeInsertSort() {}

MergeInsertSort &MergeInsertSort::operator=(const MergeInsertSort &other) {
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

std::vector<int>	MergeInsertSort::getVector() {return _vector;}

std::list<int>	MergeInsertSort::getList() {return _list;}

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
	 for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void MergeInsertSort::parse(char **array) {
	for (int i = 0; array[i]; i++) {
		for (int j = 0; array[i][j]; j++) {
			if (!isdigit(array[i][j])) {
				std::cerr << ERROR_PROMPT << ARG_ERROR << std::endl;
				throw false;
			}
		}
		_vector.push_back(atoi(array[i]));
		_list.push_back(atoi(array[i]));
	}
}

void MergeInsertSort::compute() {
	time_t tmp;

	time(&tmp);
	_vector = sortVector(_vector);
	time(&_vtime);
	_vtime -= tmp;
	time(&tmp);
	// _list = sortList(_list);
	time(&_ltime);
	_ltime -= tmp;
}