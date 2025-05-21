/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:03:28 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:03:29 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_menu(t_window *win)
{
	int	y;

	y = 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xFFFFFF, "Controls:");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "W/S: rotate X");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "A/D: rotate Y");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "Q/E: rotate Z");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "+/-: zoom");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "Arrows: move");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "I: isometric");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "P: parallel");
	y += 30;
	mlx_string_put(win->mlx, win->win, 30, y, 0xAAAAAA, "ESC: exit");
}
