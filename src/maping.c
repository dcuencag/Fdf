#include "../fdf.h"

int	**maping(int fd)
{
	char *together;
	char **splited;
	int	x;
	int	y;
	int	z;

	x = 0;
	z = 0;
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
		y = 0;
		while (splited[y])
		{
			printf("x,y,z = (%d,%d,%d)\n", x, y, ft_atoi(splited[y]));
			y++;
		}
		free(together);
		free(splited);
		x++;
	}
	return (0);
}
