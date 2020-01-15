/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:13:47 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/15 16:35:54 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cube.h"

int	game_loop(t_game *game)
{
	if (game->press->w)
		move_front(game->p);
	if (game->press->d)
		move_right(game->p);
	if (game->press->s)
		move_back(game->p);
	if (game->press->a)
		move_left(game->p);
	if (game->press->right)
		look_right(game->p);
	if (game->press->left)
		look_left(game->p);
	reset_dir(g->p->dir);
	raycast();
	return (0);
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_game	game;
	t_settings	set;
	t_player	p;

	if (ac < 2 || check_ext(av[1] == 0))
	{
		clean_exit(1, game);
		return (0);
	}
	get_settings(&set, open(O_RDONLY, av[1]));
	if ((error = parse(&set)) != 0)
	{
		clean_exit(error, game);
		return (0);
	}
	game.set = set;
	player = init_player(game.set);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, res_x, res_y, "Cub3D");
	set_hooks(mlx_ptr, win_ptr, game);
	mlx_do_key_autorepeatoff(mlx_ptr);
	img_ptr = mlx_new_image(mlx_ptr, g.set.res_x, g.set.res_y);
	mlx_loop(mlx_ptr);
}
