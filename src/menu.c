#include "../fdf.h"

void	draw_menu(t_window *win)
{
	int	y;

	y = 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xFFFFFF, "Controls:");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "W/S: rotate X");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "A/D: rotate Y");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "Q/E: rotate Z");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "+/-: zoom");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "Arrows: move");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "I: isometric");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "P: parallel");
	y += 20;
	mlx_string_put(win->mlx, win->win, 20, y, 0xAAAAAA, "ESC: exit");
}
