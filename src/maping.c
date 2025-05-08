/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:57:58 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:08:59 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	put_pixel(t_window *win, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= win->width || y < 0 || y >= win->height)
		return ;
	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	**maping(int fd, void *param)
{
	t_window	*win;
	char		*line;
	char		**split;
	char		**prev;
	int			x;

	win = (t_window *)param;
	ft_memset(win->addr, 0,
		win->width * win->height * (win->bits_per_pixel / 8));
	win->fd = fd;
	prev = NULL;
	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		maping_loop(win, split, prev, x);
		free_split(prev);
		prev = split;
		free(line);
		x++;
		line = get_next_line(fd);
	}
	free_split(prev);
	return (0);
}
