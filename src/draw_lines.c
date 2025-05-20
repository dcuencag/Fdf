/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:59:37 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 13:24:30 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_horizontal_line(t_window *win, char **split, t_draw_data d)
{
	t_point			p1;
	t_projected		proj;
	t_line			line;

	if (!split[d.y + 1])
		return ;
	p1 = parse_point(d.x, d.y + 1, split[d.y + 1]);
	proj = project_point(p1, win);
	line.x0 = d.p0.p_x;
	line.y0 = d.p0.p_y;
	line.x1 = proj.p_x;
	line.y1 = proj.p_y;
	paint_line(win, line, d);
}

void	draw_vertical_line(t_window *win, char **prev, t_draw_data d)
{
	t_point			p1;
	t_projected		proj;
	t_line			line;

	if (!prev || !prev[d.y])
		return ;
	p1 = parse_point(d.x - 1, d.y, prev[d.y]);
	proj = project_point(p1, win);
	line.x0 = d.p0.p_x;
	line.y0 = d.p0.p_y;
	line.x1 = proj.p_x;
	line.y1 = proj.p_y;
	paint_line(win, line, d);
}
