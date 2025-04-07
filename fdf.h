/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:36:13 by dancuenc          #+#    #+#             */
/*   Updated: 2025/04/07 11:48:31 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/standar/libft.h"
# include "libft/standar/get_next_line.h"
# include <math.h>

int		main(void);
int	**maping(int fd);

typedef struct s_point {
	int	x;
	int	y;
	int	z;	
} t_point;

#endif