/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:17:16 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:21:22 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_projection_keys(int keycode, t_window *win)
{
	if (keycode == 65307)
		cleanup_and_exit(win);
	else if (keycode == 105)
		set_projection(win, PROJ_ISO);
	else if (keycode == 112)
		set_projection(win, PROJ_PARALLEL);
	else if (keycode == 114)
		reset_view(win);
	else
		return (0);
	return (1);
}

int	handle_zoom_move_keys(int keycode, t_window *win)
{
	if (keycode == 43)
		zoom_plus(win);
	else if (keycode == 45)
		zoom_less(win);
	else if (keycode == 65362)
		move_up(win);
	else if (keycode == 65364)
		move_down(win);
	else if (keycode == 65361)
		move_left(win);
	else if (keycode == 65363)
		move_right(win);
	else
		return (0);
	return (1);
}

int	handle_rotation_keys(int keycode, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (keycode == 119)
		rotate_up(win);
	else if (keycode == 115)
		rotate_down(win);
	else if (keycode == 97)
		rotate_left(win);
	else if (keycode == 100)
		rotate_right(win);
	else if (keycode == 101)
		rotate_z_left(param);
	else if (keycode == 113)
		rotate_z_right(param);
	else
		return (0);
	return (1);
}
