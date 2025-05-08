/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:59:37 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:47:13 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_horizontal_line(t_window *win, char **split, t_draw_data d)
{
	double			px;
	double			py;
	t_projected		p1;
	t_line			line;

	if (!split[d.y + 1])
		return ;
	px = ((d.y + 1) * win->zoom * cos(0.5236))
		+ (d.x * win->zoom * cos(0.5236));
	py = ft_atoi(split[d.y + 1]) * (win->zoom / 2)
		- ((d.x * win->zoom * sin(0.5236))
			- ((d.y + 1) * win->zoom * sin(0.5236)));
	p1.p_x = px + win->off_x;
	p1.p_y = -py + win->off_y;
	line.x0 = d.p0.p_x;
	line.y0 = d.p0.p_y;
	line.x1 = p1.p_x;
	line.y1 = p1.p_y;
	paint_line(win, line);
}

void	draw_vertical_line(t_window *win, char **prev, t_draw_data d)
{
	double			px;
	double			py;
	t_projected		p1;
	t_line			line;

	if (!prev || !prev[d.y])
		return ;
	px = (d.y * win->zoom * cos(0.5236))
		+ ((d.x - 1) * win->zoom * cos(0.5236));
	py = ft_atoi(prev[d.y]) * (win->zoom / 2)
		- (((d.x - 1) * win->zoom * sin(0.5236))
			- (d.y * win->zoom * sin(0.5236)));
	p1.p_x = px + win->off_x;
	p1.p_y = -py + win->off_y;
	line.x0 = d.p0.p_x;
	line.y0 = d.p0.p_y;
	line.x1 = p1.p_x;
	line.y1 = p1.p_y;
	paint_line(win, line);
}
