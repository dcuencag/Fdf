/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:17:25 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:24:33 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_plus(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	window->zoom += 1;
	close(window->fd);
	window->fd = open(window->map_path, O_RDONLY);
	if (window->fd < 0)
		cleanup_and_exit(window);
	maping(window->fd, window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

void	zoom_less(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (window->zoom > 1)
	{
		window->zoom -= 1;
		close(window->fd);
		window->fd = open(window->map_path, O_RDONLY);
		if (window->fd < 0)
			cleanup_and_exit(window);
		maping(window->fd, window);
		mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	}
}
