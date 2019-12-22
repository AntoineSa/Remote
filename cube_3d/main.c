#include "cube.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	t_settings	*set;

	fd = open(O_RDONLY, test.cub)
	get_map(set, fd, get_settings(set, fd));
	printf("res x : %d\t res y : %d\t\n", set->res_x, set->res_y);
	printf("t_n : %s\n", set->t_n);
	printf("t_e : %s\n", set->t_e);
	printf("t_s : %s\n", set->t_s);
	printf("t_w : %s\n", set->t_w);
	printf("c_f : %d, %d, %d\tc_c : %d, %d, %d\n", set->c_f[0], set->c_f[1], set->c_f[2], set->c_c[0], set->c_c[1], set->c_c[2]);
	printf("map line 1 : %s\n", set->map[1]);
	close(fd);
	return (0);
}
