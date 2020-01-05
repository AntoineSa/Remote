#include <mlx.h>
#include "cube.h"

int	fucnt(t_settings)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, t_set.res_x, t_set.res_y, "cube_3d");
	while(gME)
