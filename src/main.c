#include "../fdf.h"
#include <unistd.h>

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Usage: %s <filename>\n", av[0]);
        return 1;
    }

    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
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