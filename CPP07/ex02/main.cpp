#include "Array.hpp"

int main() {
	{
		std::cout << "\033[32m" << std::endl << "Empty Array" << "\033[0m" << std::endl;
		Array<int> emptyArray;
		std::cout << "\033[32m" << std::endl << "Out Of Bounds" << "\033[0m" << std::endl;
		try
		{
			std::cout << "emptyArray[5]: " << emptyArray[5] << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


	{
		std::cout << "\033[32m" << std::endl << "Int Array" << "\033[0m" << std::endl;
		Array<int> intArray(5);
		for (int i = 0; i < 5; i++)
			intArray[i] = i;
		std::cout << "intArray Size: " << intArray.size() << std::endl;
		std::cout << "intArray: ";
		for (int i = 0; i < 5; i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;

		std::cout << "\033[32m" << std::endl << "Int Array Copy" << "\033[0m" << std::endl;
		Array<int> intArrayCopy(intArray);
		std::cout << "intArrayCopy: ";
		for (int i = 0; i < 5; i++)
			std::cout << intArrayCopy[i] << " ";
		std::cout << std::endl;

	}

	{
		std::cout << "\033[32m" << std::endl << "Double Array" << "\033[0m" << std::endl;
	Array<double> doubleArray(10);
	for (int i = 0; i < 10; i++)
		doubleArray[i] = i / 2.0;
	std::cout << "doubleArray size: " << doubleArray.size() << std::endl;
	std::cout << "doubleArray: ";
	for (int i = 0; i < 10; i++)
		std::cout << doubleArray[i] << " ";
	std::cout << std::endl;
	}
	return (0);
}