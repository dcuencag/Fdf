/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:57:58 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 13:23:31 by dancuenc         ###   ########.fr       */
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

t_point	parse_point(int x, int y, char *str)
{
	t_point		point;
	char		**parts;

	point.x = x;
	point.y = y;
	parts = ft_split(str, ',');
	point.z = ft_atoi(parts[0]);
	if (parts[1])
		point.color = ft_atoi_base(parts[1], 16);
	else
		point.color = get_color(point.z);
	free_split(parts);
	return (point);
}

static t_draw_data	draw_point(t_window *win, int x, int y, char *str)
{
	t_point			point;
	t_projected		p0;
	t_draw_data		data;
	double			px;
	double			py;

	point = parse_point(x, y, str);
	px = (y * win->zoom * cos(win->rot_y)) + (x * win->zoom * cos(win->rot_x));
	py = point.z * (win->zoom / 2)
		- ((x * win->zoom * sin(win->rot_x)) - (y * win->zoom * sin(win->rot_y)));
	p0.p_x = px + win->off_x;
	p0.p_y = -py + win->off_y;
	put_pixel(win, p0.p_x, p0.p_y, point.color);
	data.x = x;
	data.y = y;
	data.p0 = p0;
	data.color = point.color;
	return (data);
}

void	maping_loop(t_window *win, char **split, char **prev, int x)
{
	int				y;
	double			px;
	double			py;
	t_projected		p0;
	t_draw_data		data;

	y = 0;
	while (split[y])
	{
		data = draw_point(win, x, y, split[y]);
		px = (y * win->zoom * cos(0.5236))
			+ (x * win->zoom * cos(0.5236));
		py = ft_atoi(split[y]) * (win->zoom / 2)
			- ((x * win->zoom * sin(0.5236))
				- (y * win->zoom * sin(0.5236)));
		p0.p_x = px + win->off_x;
		p0.p_y = -py + win->off_y;
		data.x = x;
		data.y = y;
		data.p0 = p0;
		draw_horizontal_line(win, split, data);
		draw_vertical_line(win, prev, data);
		y++;
	}
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
	win->rot_x = 0.5236;
	win->rot_y = 0.5236;
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
