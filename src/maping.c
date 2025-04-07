#include "../fdf.h"

int	**maping(int fd)
{
	char *together;
	char **splited;
	void	*mlx;
	void	*mlx_win;
	int	x;
	int	y;
	int p_x;
	int	p_y;

	x = 0;
	p_x = 0;
	p_y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 750, "Fil de Fer");
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
		y = 0;
		while (splited[y])
		{
			p_x = ((y * cos(30)) - (x * cos(30)));
			p_y = ft_atoi(splited[y]) - ((y * sin(30)) - (x * sin(30)));
			printf("(%d,%d)\n", p_x, p_y);
			mlx_pixel_put(mlx, mlx_win, p_y, p_x, 0x00FFA500);
			y++;
		}
		free(together);
		free(splited);
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
