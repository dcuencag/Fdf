#include "../fdf.h"

int	**maping(int fd)
{
	char *together;
	char **splited;
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
		while (splited)
		{
			printf("x,y,z = (%d,%d,%d)", x, y, ft_atoi(splited[y]));
			y++;
		}
	x++;
	}
	return (0);
}
