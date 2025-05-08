/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:40:49 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:25:14 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	move_down(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->off_y -= 25;
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
		cleanup_and_exit(win);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void	move_up(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->off_y += 25;
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
		cleanup_and_exit(win);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void	move_left(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->off_x += 25;
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
		cleanup_and_exit(win);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void	move_right(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	win->off_x -= 25;
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
		cleanup_and_exit(win);
	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}
