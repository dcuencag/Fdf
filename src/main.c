/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:11:30 by dancuenc          #+#    #+#             */
/*   Updated: 2025/04/17 16:10:51 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <unistd.h>

int	main(int ac, char **av)
{
    if (ac != 5)
    {
        printf("Usage: %s <window width> <window height> <filename> <zoom>\n", av[0]);
        return (0);
    }

    int fd = open(av[3], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
	create_window(ft_atoi(av[1]), ft_atoi(av[2]), fd, ft_atoi(av[4]));
	close(fd);
	return (0);
}