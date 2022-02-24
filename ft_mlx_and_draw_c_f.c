#include "cub3d.h"

void	my_mlx_pixel_put(t_vars *box, int x, int y, int color)
{
	char	*dst;

	dst = box->addr + (y * box->line_length + x
			* (box->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_put_get(t_vars *box, int x, int y)
{
	char	*dst;
	int		color;

	dst = box->addr_tex + (y * box->line_length_tex + x
			* (box->bits_per_pixel_tex / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	verline_ceilling_floor(t_vars *box, int x, int color)
{
	while (box->drawStart < box->drawEnd)
	{
		my_mlx_pixel_put(box, x, box->drawStart, color);
		box->drawStart++;
	}
}

void	draw_floor_and_ceilling(t_vars *box, int x)
{
	int	color_c;
	int	color_f;

	color_c = rgb_ceilling(box);
	color_f = rgb_floor(box);
	box->drawStart = box->height / 2;
	box->drawEnd = box->height;
	verline_ceilling_floor(box, x, color_f);
	box->drawStart = 0;
	box->drawEnd = box->height / 2;
	verline_ceilling_floor(box, x, color_c);
}
