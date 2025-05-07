/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:11:30 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/07 12:02:37 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./fdf width height map_path zoom\n", 2);
		return (1);
	}
	int width = ft_atoi(av[1]);
	int height = ft_atoi(av[2]);
	int zoom = ft_atoi(av[4]);
	create_window(width, height, av[3], zoom);
	return (0);
}