#include "../fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	i = 400;
	int	x = 250;
	int c = 0;
	int	fd;

	fd = open("fdf.h", O_RDONLY);
	while (c < 11)
	{
		printf("%s", get_next_line(fd));
		c++;
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 750, "Hello world!");
	while (i < 800)
	{
		mlx_pixel_put(mlx, mlx_win, i, x, 0x00FFA500);
		i++;
		if (i % 10 == 0)
		{
			x++;
		}
	}
	mlx_loop(mlx);
	close(fd);
}