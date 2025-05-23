/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:11:30 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 14:52:49 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <unistd.h>

static int	atoi_args(int *width, int *height, int *zoom, char **av)
{
	*width = ft_atoi(av[1]);
	*height = ft_atoi(av[2]);
	*zoom = ft_atoi(av[4]);
	return (0);
}

static void	init_rotation_state(t_window *win)
{
	win->rot_x = 0.5236;
	win->rot_y = 0.5236;
	win->rot_z = 0.5236;
	win->z_scale = 1.0;
}

int	main(int ac, char **av)
{
	t_window	*win;
	int			width;
	int			height;
	int			zoom;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./fdf width height map_path zoom\n", 2);
		return (1);
	}
	atoi_args(&width, &height, &zoom, av);
	win = create_window(width, height, av[3], zoom);
	if (!win)
		return (1);
	init_rotation_state(win);
	detect_map_dimensions(win);
	win->off_x = (win->width / 2) - (win->cols * win->zoom / 2);
	win->off_y = (win->height / 2) - (win->rows * win->zoom / 2);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_loop(win->mlx);
	return (0);
}
