/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:24:30 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 12:49:08 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	abs_diff(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

static void	paint_line_loop(t_window *win, t_line line, t_bres b, t_draw_data d)
{
	while (line.x0 != line.x1 || line.y0 != line.y1)
	{
		put_pixel(win, line.x0, line.y0, d.color);
		b.e2 = 2 * b.err;
		if (b.e2 > -b.dy)
		{
			b.err -= b.dy;
			line.x0 += b.sx;
		}
		if (b.e2 < b.dx)
		{
			b.err += b.dx;
			line.y0 += b.sy;
		}
	}
}

void	paint_line(t_window *win, t_line line, t_draw_data d)
{
	t_bres	b;

	b.dx = abs_diff(line.x1, line.x0);
	b.dy = abs_diff(line.y1, line.y0);
	b.sx = 1;
	if (line.x0 > line.x1)
		b.sx = -1;
	b.sy = 1;
	if (line.y0 > line.y1)
		b.sy = -1;
	b.err = b.dx - b.dy;
	paint_line_loop(win, line, b, d);
}
