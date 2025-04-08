#include "../fdf.h"

int	**maping(int fd, int zoom)
{
	char *together;
	char **splited;
	void	*mlx;
	void	*mlx_win;
	int	x;
	int	y;
	double p_x;
	double	p_y;

	x = 0;
	p_x = 0;
	p_y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2400, 1500, "Fil de Fer");
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
		y = 0;
//		usleep(1500);
		while (splited[y])
		{
			p_x = ((y * zoom * cos(0.5236)) + (x * zoom * cos(0.5236)));
			p_y = (ft_atoi(splited[y]) * (zoom / 2) - ((x * zoom * sin(0.5236)) - (y * zoom * sin(0.5236))));
			printf("(%f,%f)\n", p_x, p_y);
			mlx_pixel_put(mlx, mlx_win, p_x + 700, -p_y + 750, 0x00FFA500);
			y++;
		}
		free(together);
		free(splited);
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
