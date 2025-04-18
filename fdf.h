/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:36:13 by dancuenc          #+#    #+#             */
/*   Updated: 2025/04/17 16:40:52 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/standar/libft.h"
# include "libft/standar/get_next_line.h"
# include <math.h>

int	main(int ac, char **av);
int	**create_window(int width, int height, int fd, int zoom);
int	**maping(int fd, void *param);

typedef struct s_point {
	int	x;
	int	y;	
} t_point;

typedef struct s_window
{
	void *mlx;
	void *win;
	int	zoom;
} t_window;

#endif