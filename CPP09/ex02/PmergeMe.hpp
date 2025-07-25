#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

#define ERROR_PROMPT "Error: "

#define USAGE_ERROR "Usage: ./PmergeMe <n1> <n> <n3> <n4> <n4> ..."
#define ARG_ERROR "Arguments have to be a positive number."

class MergeInsertSort {
	private:
		std::vector<int> _vector;
		std::list<int> _list;
		time_t		_vtime;
		time_t		_ltime;
		size_t		_containerSize;

		std::vector<int> sortVector(std::vector<int> container);
	
	public:
/* ================= Canonical Form ================= */

		MergeInsertSort();
		MergeInsertSort(const MergeInsertSort &other);
		~MergeInsertSort();
		MergeInsertSort &operator=(const MergeInsertSort &other);

/* ===================== Getter ===================== */

		std::vector<int>	getVector();
		std::list<int>	getList();
		time_t	getvtime();

/* ================= Member Function ================= */

		void	printVector();
		void	printVector(std::vector<int> container);
		void	printList();
		void	parse(char **array);
		void	compute();
};