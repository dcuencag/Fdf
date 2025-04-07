#include "../fdf.h"
#include <unistd.h>

int	main(void)
{
/* 	void	*mlx;
	void	*mlx_win; */
	int	fd;

	fd = open("1.fdf", O_RDONLY);
	maping(fd);
/* 	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 750, "Hello world!");
	while (i < 800)
	{
		usleep(9999);
		mlx_pixel_put(mlx, mlx_win, i, x, 0x00FFA500);
		i++;
		if (i % 10 == 0)
		{
			x++;
		}
	}
	mlx_loop(mlx); */
	close(fd);
}