#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1;av[i];i++)
			for(int j = 0;av[i][j];j++)
			{
				av[i][j] = std::toupper(av[i][j]);
				std::cout << av[i][j];
			}
	}
	std::cout << std::endl;
	return (0);
}