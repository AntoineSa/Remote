#include "ft_printf.h"

int	main(void)
{
	ft_printf("yoooo %% yo double : %0d again %  12.2d, yo u %#u, ok ok %s, and char %c and back %%\n", -250048, 856458, (unsigned int)5845632, "hey heye yehy", 'd');
	system("leaks a.out");
	return (0);
}
