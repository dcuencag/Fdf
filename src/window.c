/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:11:27 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/07 12:05:06 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	cleanup_and_exit(t_window *win)
{
	if (win->img)
		mlx_destroy_image(win->mlx, win->img);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	free(win);
	exit(0);
}

int my_key_handler(int keycode, void *param)
{
	t_window *window;

	printf("Keycode: %d\n", keycode);
	window = (t_window *)param;
	if (keycode == 65307)
	{
		cleanup_and_exit(window);
	}
	else if (keycode == 43)
	{
		window->zoom += 1;
		close(window->fd);
		window->fd = open(window->map_path, O_RDONLY);
		if (window->fd < 0)
    		cleanup_and_exit(window);
		maping(window->fd, window);
		mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	}
	else if (keycode == 45)
	{
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
	return (0);
}

int **create_window(int width, int height, char *map_path, int zoom)
{
	t_window *win;

	win = malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	ft_memset(win, 0, sizeof(t_window));
	win->map_path = map_path;
	win->fd = open(map_path, O_RDONLY);
	if (win->fd < 0)
	{
		perror("Error opening map file");
		free(win);
		exit(1);
	}
	win->width = width;
	win->height = height;
	win->zoom = zoom;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "FDF");
	win->img = mlx_new_image(win->mlx, win->width, win->height);
	win->addr = mlx_get_data_addr(win->img,
			&win->bits_per_pixel, &win->line_length, &win->endian);

	maping(win->fd, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_key_hook(win->win, my_key_handler, win);
	mlx_loop(win->mlx);
	free(win);
	return (0);
}
