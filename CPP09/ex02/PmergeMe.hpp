#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

#define ERROR_PROMPT "Error: "

#define USAGE_ERROR "Usage: ./PmergeMe <n1> <n> <n3> <n4> <n4> ..."
#define ARG_ERROR "Arguments have to be a positive number."

class Data {
	private:
		std::vector<int> _vector;
		std::list<int> _list;
		time_t		_ltime;
		time_t		_vtime;
		size_t		_containerSize;
	
	public:
/* ================= Canonical Form ================= */

		Data();
		Data(const Data &other);
		~Data();
		Data &operator=(const Data &other);

/* ===================== Getter ===================== */

		std::vector<int>	getVector();
		std::list<int>	getList();

/* ================= Member Function ================= */

		void	printVector();
		void	printList();
		void	parse(char **array);
};