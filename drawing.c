#include "cub3d.h"

void	where_the_wall_hit(t_vars *box)
{
	if (box->side == '0')
	{
		box->wall_x = box->posY + box->perpWallDist * box->rayDirY;
		if (box->rayDirX > 0)
			img_texture(box, box->so_path);
		else if (box->rayDirX < 0)
			img_texture(box, box->no_path);
	}
	if (box->side == '1')
	{
		box->wall_x = box->posX + box->perpWallDist * box->rayDirX;
		if (box->rayDirY > 0)
			img_texture(box, box->ea_path);
		else if (box->rayDirY < 0)
			img_texture(box, box->we_path);
	}
	box->wall_x -= floor((box->wall_x));
}

void	verline(t_vars *box, int x)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	where_the_wall_hit(box);
	tex_x = (int)(box->wall_x * (double)(box->texWidth));
	if ((box->side == '0' && box->rayDirX > 0)
		|| (box->side == '1' && box->rayDirY < 0))
		tex_x = box->texWidth - tex_x - 1;
	step = 1.0 * box->texHeight / box->lineHeight;
	tex_pos = (box->drawStart - box->height
			/ 2 + box->lineHeight / 2) * step;
	y = box->drawStart;
	while (y < box->drawEnd)
	{
		tex_y = (int)tex_pos & (box->texHeight - 1);
		tex_pos += step;
		box->color = my_mlx_pixel_put_get(box, tex_x, tex_y);
		if (box->side == '1')
			box->color = box->color / 2;
		my_mlx_pixel_put(box, x, y, box->color);
		y++;
	}
}

int	rgb_ceilling(t_vars *box)
{
	return (box->ceilling_r << 16
		| box->ceilling_g << 8 | box->ceilling_b);
}

int	rgb_floor(t_vars *box)
{
	return (box->floor_r << 16 | box->floor_g << 8 | box->floor_b);
}

void	draw_map(t_vars *box)
{
	int	x;

	x = 0;
	while (x < box->width)
	{
		draw_floor_and_ceilling(box, x);
		box->posX = box->plr_mas_x + 0.5;
		box->posY = box->plr_mas_y + 0.5;
		box->cameraX = 2 * x / (double)box->width - 1;
		box->rayDirX = box->dirX + box->planeX * box->cameraX;
		box->rayDirY = box->dirY + box->planeY * box->cameraX;
		box->mapX = (int)box->posX;
		box->mapY = (int)box->posY;
		box->deltaDistX = fabs(1 / box->rayDirX);
		box->deltaDistY = fabs(1 / box->rayDirY);
		box->hit = '0';
		calculate_step_and_init_sideDist(box);
		dda(box);
		not_fish_eye_plus_height_wall(box);
		verline(box, x);
		box->zBuffer[x] = box->perpWallDist;
		x++;
	}
	ft_sprites(box);
	mlx_put_image_to_window(box->mlx, box->win, box->img, 0, 0);
}
