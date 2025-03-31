#include "../fdf.h"

char	**map(char *map)
{
	int	fd;
	char *together;
	char **splited;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (0);
	}
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
	}
	close(fd);
	return (*splited);
}