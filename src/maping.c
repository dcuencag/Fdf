#include "../fdf.h"

int	**maping(int fd, void *param)
{
	char *together;
	char **splited;
	double p_x;
	double	p_y;
	t_point point;
	t_window *window;

	window = (t_window *)param;
	point.x = 0;
	p_x = 0;
	p_y = 0;
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
		point.y = 0;
		while (splited[point.y])
		{
			p_x = ((point.y * window->zoom * cos(0.5236)) + (point.x * window->zoom * cos(0.5236)));
			p_y = (ft_atoi(splited[point.y]) * (window->zoom / 2) - ((point.x * window->zoom * sin(0.5236)) - (point.y * window->zoom * sin(0.5236))));
			printf("(%f,%f)\n", p_x, p_y);
			mlx_pixel_put(window->mlx, window->win, p_x + 700, -p_y + 950, 0x00FFA500);
			point.y++;
		}
		free(together);
		free(splited);
		point.x++;
	}
	return (0);
}
