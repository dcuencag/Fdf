/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:11:44 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:11:57 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	refresh_display(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,
			&win->line_length, &win->endian);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	draw_menu(win);
}

void	reset_view(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->rot_x = 0;
	win->rot_y = 0;
	win->rot_z = 0;
	win->z_scale = 1.0;
	win->projection = PROJ_ISO;
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
		cleanup_and_exit(win);
	maping(win->fd, win);
	center_model(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	draw_menu(win);
	refresh_display(win);
}
