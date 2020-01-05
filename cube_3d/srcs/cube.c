#include <mlx.h>
#include "cube.h"

int	main(int ac, char **av)
{
	s_settings	set;

	if (ac < 2)
		ft_printf("no .cub specified\n");
	get_input(&set, open(O_RDONLY, av[1]));
	format(input);
	while (true)
	{
		raycast
	}
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, res_x, res_y, "cube_3d");
	mlx_loop(mlx_ptr);
}
