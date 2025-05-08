/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:36:13 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:49:52 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft/standar/libft.h"
# include "libft/standar/get_next_line.h"
# include <math.h>

typedef struct s_point
{
	int	x;
	int	y;	
}	t_point;

typedef struct s_projected
{
	int	p_x;
	int	p_y;
}	t_projected;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_line;

typedef struct s_draw_data
{
	int				x;
	int				y;
	t_projected		p0;
}	t_draw_data;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

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
	int		off_x;
	int		off_y;
	int		cols;
	int		rows;
	char	*map_path;
}	t_window;

typedef struct s_window_params
{
	int		width;
	int		height;
	int		zoom;
	char	*map_path;
}	t_window_params;

typedef struct s_map
{
	int	**z_matrix;
	int	width;
	int	height;
}	t_map;

int		main(int ac, char **av);
int		**create_window(int width, int height, char *map_path, int zoom);
int		**maping(int fd, void *param);
void	cleanup_and_exit(t_window *win);
void	zoom_plus(void *param);
void	zoom_less(void *param);
void	move_up(void *param);
void	move_down(void *param);
void	move_left(void *param);
void	move_right(void *param);
void	free_split(char **split);
void	detect_map_dimensions(t_window *win);
void	center_model(t_window *win);
void	put_pixel(t_window *win, int x, int y, int color);
void	maping_loop(t_window *win, char **split, char **prev, int x);
void	draw_horizontal_line(t_window *win, char **split, t_draw_data d);
void	draw_vertical_line(t_window *win, char **prev, t_draw_data d);
void	paint_line(t_window *win, t_line line);

#endif