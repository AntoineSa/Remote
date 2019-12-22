#include <mlx.h>
#include "cube.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		get_input(av);
		parse(input);
	}
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
