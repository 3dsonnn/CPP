#include <iostream>

void	print_str(const char *str)
{
	std::cout << str << std::endl;
}

int	main()
{
	char	str[] = "efinda";
	str[7] = 'A';
	print_str(const_cast<const char *>(str));
	return (0);
}
