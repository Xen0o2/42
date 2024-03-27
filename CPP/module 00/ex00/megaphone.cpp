#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISES *" << std::endl;
	else
		for (int i = 1; av[i]; i++)
			for (int x = 0; av[i][x]; x++)
				std::cout << (char)toupper(av[i][x]);
	std::cout << std::endl;
	return (0);
}
