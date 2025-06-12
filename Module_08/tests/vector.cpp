#include <iostream>
#include <vector>
#include <algorithm>

template <typename A, class B, class C>	void	print(A a, B b, C c) { std::cout << a << b << c; }

int	main()
{
	std::vector<int> numbers(5, 5);

	for (int i = 0; i < numbers.size(); i++)
	{
		print("At(", i, ")");
		print(" = ", numbers.at(i), '\n');
	}

	std::vector<int>::iterator it = numbers.begin();

	*it = 9;

	std::vector<int>::iterator tmp = std::find(it, it + 4, 12);

	print("--> ", *tmp, "\n");

	return (0);
}
