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

t_projected	project_point(t_point p, t_window *win)
{
	double			rx;
	double			ry;
	double			rz;
	double			tmp;
	t_projected		proj;
	double			px;
	double			py;

	rx = (double)p.x;
	ry = (double)p.y;
	rz = (double)p.z;
	rz *= win->z_scale;
//	printf("Z: %d -> rz: %f\n", p.z, rz);
	tmp = ry * cos(win->rot_x) - rz * sin(win->rot_x);
	rz = ry * sin(win->rot_x) + rz * cos(win->rot_x);
	ry = tmp;
	tmp = rx * cos(win->rot_y) + rz * sin(win->rot_y);
	rz = -rx * sin(win->rot_y) + rz * cos(win->rot_y);
	rx = tmp;
	tmp = rx * cos(win->rot_z) - ry * sin(win->rot_z);
	ry = rx * sin(win->rot_z) + ry * cos(win->rot_z);
	rx = tmp;
	px = (rx - ry) * cos(0.5236);
	py = (rx + ry) * sin(0.5236) - rz;
	proj.p_x = px * win->zoom + win->off_x;
	proj.p_y = py * win->zoom + win->off_y;
	return (proj);
}

static t_draw_data	
draw_point(t_window *win, int x, int y, char *str)
{
	t_point			point;
	t_projected		p0;
	t_draw_data		data;

	point = parse_point(x, y, str);
	if (win->z_scale == 0.0)
		win->z_scale = 1.0;
	p0 = project_point(point, win);
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
	t_draw_data		data;

	y = 0;
	while (split[y])
	{
		data = draw_point(win, x, y, split[y]);
		draw_horizontal_line(win, split, data);
		draw_vertical_line(win, prev, data);
		y++;
	}
}

int	**maping(int fd_unused, void *param)
{
	t_window	*win;
	char		*line;
	char		**split;
	char		**prev;
	int			x;
	int			fd;

	(void)fd_unused;
	win = (t_window *)param;
	ft_memset(win->addr, 0,
		win->width * win->height * (win->bits_per_pixel / 8));
	fd = open(win->map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
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
	close(fd);
	return (NULL);
}
