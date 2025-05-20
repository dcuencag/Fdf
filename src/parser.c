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

t_point	parse_point(int x, int y, char *str)
{
	t_point		point;
	char		**parts;

	point.x = y;
	point.y = x;
	point.z = 0;
	point.color = 0xFFFFFF;

	if (!str)
		return (point);

	parts = ft_split(str, ',');
	if (parts && parts[0] && *parts[0])
		point.z = ft_atoi(parts[0]);
	if (parts && parts[1])
		point.color = ft_atoi_base(parts[1], 16);
	else
		point.color = get_color(point.z);
	free_split(parts);
	return (point);
}
