#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

#define ERROR_PROMPT "Error: "

#define USAGE_ERROR "Usage: ./PmergeMe <n1> <n> <n3> <n4> <n4> ..."
#define ARG_ERROR "Arguments have to be a positive number."

class MergeInsertSort {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		double		_vtime;
		double		_dtime;
		size_t		_containerSize;

		template <typename T>
		T sortVector(T container) {
			T big;
			T small;
			size_t i = 0;
			while (i < container.size() - 1) {
				if (container[i] < container[i + 1]) { 
					small.push_back(container[i]);
					big.push_back(container[i + 1]);
				} else {
					big.push_back(container[i]);
					small.push_back(container[i + 1]);
				}
				i += 2;
			}
			if (i < container.size())
				small.push_back(container[i]);
			i = 0;
			if (big.size() >= 2)
				big = sortVector(big);
			for (size_t i = 0; i < small.size(); i++) {
				size_t j = 0;
				while (big[j] < small[i]) j++;
				big.insert(big.begin() + j, small[i]);
			}
			return (big);
		}
	
	template <typename T>
	bool isSorted(T& v) {
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i - 1] > v[i])
			return false;
	}
	return true;
}
	public:
/* ================= Canonical Form ================= */

		MergeInsertSort();
		MergeInsertSort(const MergeInsertSort &other);
		~MergeInsertSort();
		MergeInsertSort &operator=(const MergeInsertSort &other);

/* ===================== Getter ===================== */

		std::vector<int>	getVector();
		std::deque<int>	getList();
		double	getvtime();
		double	getdtime();

/* ================= Member Function ================= */

		void	printVector();
		void	printVector(std::vector<int> container);
		void	printList();
		void	parse(char **array);
		void	compute();
};