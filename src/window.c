/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:18:56 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:19:19 by dancuenc         ###   ########.fr       */
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
	win->off_x = (win->width / 2) - (win->cols * win->zoom / 2);
	win->off_y = (win->height / 2) - (win->rows * win->zoom / 2);
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
	t_window	*win;

	printf("keycode: %d\n", keycode);
	win = (t_window *)param;
	if (handle_projection_keys(keycode, win))
		return (0);
	if (handle_zoom_move_keys(keycode, win))
		return (0);
	if (handle_rotation_keys(keycode, param))
		return (0);
	return (0);
}

t_window	*create_window(int width, int height, char *map_path, int zoom)
{
	t_window			*win;
	t_window_params		params;

	win = malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	params.width = width;
	params.height = height;
	params.zoom = zoom;
	params.map_path = map_path;
	init_window_struct(win, params);
	init_window_graphics(win);
	maping(win->fd, win);
	detect_map_dimensions(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	draw_menu(win);
	mlx_key_hook(win->win, my_key_handler, win);
	mlx_hook(win->win, 17, 0, cleanup_and_exit, win);
	mlx_loop(win->mlx);
	free(win);
	return (0);
}
