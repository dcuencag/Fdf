#include "../fdf.h"
#include <unistd.h>

int	main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("Usage: %s <filename> <zoom>\n", av[0]);
        return 1;
    }

    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    maping(fd, atoi(av[2]));
	close(fd);
}