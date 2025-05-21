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

t_projected	project_iso(t_point p, t_window *win)
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
	px = (rx - ry) * cos(0.5236);
	py = (rx + ry) * sin(0.5236) - rz;
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
