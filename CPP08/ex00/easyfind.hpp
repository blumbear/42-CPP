#pragma once

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return ("Element not found");
	}
};

template <typename T> typename T::const_iterator easyfind(const T& container, const int n) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}