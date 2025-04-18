/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:11:27 by dancuenc          #+#    #+#             */
/*   Updated: 2025/04/18 15:13:20 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int my_key_handler(int keycode, void *param)
{
	t_window *window;

	printf("Keycode: %d\n", keycode);
	window = (t_window *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit (0);
	}
	else if (keycode == 43)
	{
		window->zoom += 1;
	}
	else if (keycode == 45)
	{
		if (window->zoom > 1)
			window->zoom -= 1;
	}
	return (0);
}

int	**create_window(int width, int height, int fd, int first_zoom)
{
	t_window window;
	int	try;
	printf("here");
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, width, height, "Fil de Fer");
	window.zoom = first_zoom;
	maping(fd, &window);
	try = mlx_key_hook(window.win, my_key_handler, &window);
	mlx_loop(window.mlx);
	return (0);
}