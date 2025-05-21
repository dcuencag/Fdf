/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:07:27 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/21 15:10:49 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_projection(void *param, t_proj mode)
{
	t_window	*window;

	window = (t_window *)param;
	window->projection = mode;
	close(window->fd);
	window->fd = open(window->map_path, O_RDONLY);
	if (window->fd < 0)
		cleanup_and_exit(window);
	maping(window->fd, window);
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
	draw_menu(window);
}

static	t_fpoint	apply_rotation(t_point p, t_window *win)
{
	t_fpoint	v;
	double		tmp;

	v.x = (double)p.x;
	v.y = (double)p.y;
	v.z = (double)p.z * win->z_scale;
	tmp = v.y * cos(win->rot_x) - v.z * sin(win->rot_x);
	v.z = v.y * sin(win->rot_x) + v.z * cos(win->rot_x);
	v.y = tmp;
	tmp = v.x * cos(win->rot_y) + v.z * sin(win->rot_y);
	v.z = -v.x * sin(win->rot_y) + v.z * cos(win->rot_y);
	v.x = tmp;
	tmp = v.x * cos(win->rot_z) - v.y * sin(win->rot_z);
	v.y = v.x * sin(win->rot_z) + v.y * cos(win->rot_z);
	v.x = tmp;
	return (v);
}

t_projected	project_iso(t_point p, t_window *win)
{
	t_projected	proj;
	t_fpoint	rot;
	double		px;
	double		py;

	rot = apply_rotation(p, win);
	px = (rot.x - rot.y) * cos(0.5236);
	py = (rot.x + rot.y) * sin(0.5236) - rot.z;
	proj.p_x = px * win->zoom + win->off_x;
	proj.p_y = py * win->zoom + win->off_y;
	return (proj);
}

t_projected	project_parallel(t_point p, t_window *win)
{
	double			rx;
	double			ry;
	double			rz;
	double			tmp;
	t_projected		proj;

	rx = (double)p.x;
	ry = (double)p.y;
	rz = (double)p.z * win->z_scale;
	tmp = ry * cos(win->rot_x) - rz * sin(win->rot_x);
	rz = ry * sin(win->rot_x) + rz * cos(win->rot_x);
	ry = tmp;
	tmp = rx * cos(win->rot_y) + rz * sin(win->rot_y);
	rz = -rx * sin(win->rot_y) + rz * cos(win->rot_y);
	rx = tmp;
	tmp = rx * cos(win->rot_z) - ry * sin(win->rot_z);
	ry = rx * sin(win->rot_z) + ry * cos(win->rot_z);
	rx = tmp;
	proj.p_x = rx * win->zoom + win->off_x;
	proj.p_y = ry * win->zoom + win->off_y;
	return (proj);
}

t_projected	project_point(t_point p, t_window *win)
{
	if (win->projection == PROJ_PARALLEL)
		return (project_parallel(p, win));
	return (project_iso(p, win));
}
