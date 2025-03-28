#include "../fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int 	mlx_put;
	int	i = 500;
	int	x = 500;
	int c = 0;
	int	fd;

	fd = open("fdf.h", O_RDONLY);
	while (c < 11)
	{
		printf("%s", get_next_line(fd));
		c++;
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	while (i < 1500)
	{
		mlx_put = mlx_pixel_put(mlx, mlx_win, i, x, 0x00FFA500);
		i++;
		if (i % 10 == 0)
			x++;
	}
	mlx_loop(mlx);
	close(fd);
}