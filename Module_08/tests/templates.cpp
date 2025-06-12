#include <iostream>

typedef struct s_test
{
	typedef int i;
	i t;
}	t_test;

template <int T, int times = 3>
void	print()
{
	for (int i = 0; i < times; i++)
		std::cout << T << std::endl;
}

int	main()
{
	const t_test::i t = 9;
	const t_test a = (t_test){4};

	std::cout << a.t << std::endl;
	print<'c', t>();
}
