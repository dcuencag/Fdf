/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:18:56 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 13:44:50 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	init_window_struct(t_window *win, t_window_params p)
{
	win->map_path = p.map_path;
	win->fd = open(p.map_path, O_RDONLY);
	if (win->fd < 0)
	{
		perror("Error opening map file");
		free(win);
		exit(1);
	}
	win->width = p.width;
	win->height = p.height;
	win->zoom = p.zoom;
	detect_map_dimensions(win);
	center_model(win);
}

static void	init_window_graphics(t_window *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "FDF");
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length, &win->endian);
}

int	my_key_handler(int keycode, void *param)
{
	t_window	*window;
	
	window = (t_window *)param;
	if (keycode == 65307)
		cleanup_and_exit(window);
	else if (keycode == 43)
		zoom_plus(window);
	else if (keycode == 45)
		zoom_less(window);
	else if (keycode == 65362)
		move_up(window);
	else if (keycode == 65364)
		move_down(window);
	else if (keycode == 65361)
		move_left(window);
	else if (keycode == 65363)
		move_right(window);
	else if (keycode == 119)
		rotate_up(window);
	else if (keycode == 115)
		rotate_down(window);
	else if (keycode == 97)
		rotate_left(window);
	else if (keycode == 100)
		rotate_right(window);
	return (0);
}

int	**create_window(int width, int height, char *map_path, int zoom)
{
	t_window			*win;
	t_window_params		params;

	win = malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	ft_memset(win, 0, sizeof(t_window));
	params.width = width;
	params.height = height;
	params.zoom = zoom;
	params.map_path = map_path;
	init_window_struct(win, params);
	init_window_graphics(win);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_key_hook(win->win, my_key_handler, win);
	mlx_loop(win->mlx);
	free(win);
	return (0);
}
