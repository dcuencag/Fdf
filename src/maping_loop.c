/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:57:43 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:46:53 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	maping_loop(t_window *win, char **split, char **prev, int x)
{
	int				y;
	double			px;
	double			py;
	t_projected		p0;
	t_draw_data		d;

	y = 0;
	while (split[y])
	{
		px = (y * win->zoom * cos(0.5236))
			+ (x * win->zoom * cos(0.5236));
		py = ft_atoi(split[y]) * (win->zoom / 2)
			- ((x * win->zoom * sin(0.5236))
				- (y * win->zoom * sin(0.5236)));
		p0.p_x = px + win->off_x;
		p0.p_y = -py + win->off_y;
		put_pixel(win, p0.p_x, p0.p_y, 0x00FFA500);
		d.x = x;
		d.y = y;
		d.p0 = p0;
		draw_horizontal_line(win, split, d);
		draw_vertical_line(win, prev, d);
		y++;
	}
}
