#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	char i;

	i = 0;
	printf("%d\n", ft_printf("hey %d hey\n", -416));
	printf("%d\n", printf("hey %d hey\n", -416));
//	printf("%d\n", ft_printf("%-5c uu %c%c%s%c%c \n", '\0', '\0', '\0', "yo",'\0', '\0'));
//	printf("%d\n", printf("%-5c uu %c%c%s%c%c \n", '\0', '\0', '\0', "yo", '\0', '\0'));
//	printf("%zd\n", write(1, "12\0", 3));
	return (0);
}
