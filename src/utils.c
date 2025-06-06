/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:04:18 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:13:31 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_columns(char *line)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_split(line, ' ');
	while (split[count])
		count++;
	free_split(split);
	return (count);
}

void	detect_map_dimensions(t_window *win)
{
	int		fd;
	int		rows;
	int		cols;
	char	*line;

	rows = 0;
	cols = 0;
	fd = open(win->map_path, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (rows == 0)
			cols = count_columns(line);
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	close(fd);
	win->rows = rows;
	win->cols = cols;
}

int	cleanup_and_exit(void *param)
{
	t_window	*win;

	win = (t_window *)param;
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
	return (0);
}
