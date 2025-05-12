/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:09:03 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 13:10:16 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	center_model(t_window *win)
{
	double	angle;
	double	x0, y0;
	double	x1, y1;

	angle = 0.5236;
	x0 = (0 * win->zoom * cos(angle)) + (win->rows * win->zoom * cos(angle));
	y0 = -(0 * win->zoom * sin(angle)) + (win->rows * win->zoom * sin(angle));
	x1 = (win->cols * win->zoom * cos(angle)) + (0 * win->zoom * cos(angle));
	y1 = -(win->cols * win->zoom * sin(angle)) + (0 * win->zoom * sin(angle));
	win->off_x = (win->width / 2) - ((x0 + x1) / 2);
	win->off_y = (win->height / 2) - ((y0 + y1) / 2);
}

void	detect_map_dimensions(t_window *win)
{
	char	*line;
	char	**split;

	line = get_next_line(win->fd);
	while (line)
	{
		win->rows++;
		if (win->rows == 1)
		{
			split = ft_split(line, ' ');
			while (split[win->cols])
				win->cols++;
			free_split(split);
		}
		free(line);
		line = get_next_line(win->fd);
	}
	close(win->fd);
	win->fd = open(win->map_path, O_RDONLY);
	if (win->fd < 0)
	{
		perror("Error reopening map");
		exit(1);
	}
}
