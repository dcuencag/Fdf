#include "../fdf.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	put_pixel(t_window *win, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= win->width || y < 0 || y >= win->height)
		return ;
	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	**maping(int fd, void *param)
{
	char		*together;
	char		**splited;
	double		p_x;
	double		p_y;
	t_point		point;
	t_window	*window;
	int			cols;
	int			rows;
	double		model_width;
	double		model_height;

	window = (t_window *)param;
	ft_memset(window->addr, 0, window->width * window->height * (window->bits_per_pixel / 8));
	window->fd = fd;
	cols = window->cols;
	rows = window->rows;
	model_width = (cols + rows) * window->zoom * cos(0.5236);
	model_height = (cols + rows) * window->zoom * sin(0.5236);
	window->offset_x = (window->width - model_width) / 2;
	window->offset_y = (window->height - model_height) / 2;
	point.x = 0;
	while ((together = get_next_line(fd)))
	{
		splited = ft_split(together, ' ');
		point.y = 0;
		while (splited[point.y])
		{
			p_x = ((point.y * window->zoom * cos(0.5236)) + (point.x * window->zoom * cos(0.5236)));
			p_y = (ft_atoi(splited[point.y]) * (window->zoom / 2) - ((point.x * window->zoom * sin(0.5236)) - (point.y * window->zoom * sin(0.5236))));
			put_pixel(window, p_x + window->offset_x, -p_y + window->offset_y, 0x00FFA500);
			point.y++;
		}
		free(together);
		free_split(splited);
		point.x++;
	}
	return (0);
}
