/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:09:03 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:27:49 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
