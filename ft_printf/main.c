#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%d\n", ft_printf("%c\n", 0));
	printf("%d\n", printf("%c\n", 0));
	return (0);
}
