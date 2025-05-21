/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:27:16 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 13:33:17 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_z_left(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->rot_z -= 0.05;
	ft_memset(win->addr, 0,
		win->width * win->height * (win->bits_per_pixel / 8));
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
	{
		perror("Error reopening map file");
		exit(1);
	}
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	draw_menu(win);
}

void	rotate_z_right(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->rot_z += 0.05;
	ft_memset(win->addr, 0,
		win->width * win->height * (win->bits_per_pixel / 8));
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
	{
		perror("Error reopening map file");
		exit(1);
	}
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	draw_menu(win);
}
