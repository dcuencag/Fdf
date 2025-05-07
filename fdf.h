/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:36:13 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/07 12:03:28 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/standar/libft.h"
# include "libft/standar/get_next_line.h"
# include <math.h>

int	main(int ac, char **av);
int **create_window(int width, int height, char *map_path, int zoom);
int	**maping(int fd, void *param);

typedef struct s_point {
	int	x;
	int	y;	
} t_point;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		zoom;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fd;
	int		offset_x;
	int		offset_y;
	int		cols;
	int		rows;
	char	*map_path;
} t_window;

typedef struct s_map
{
	int	**z_matrix;
	int	width;
	int	height;
}	t_map;

#endif