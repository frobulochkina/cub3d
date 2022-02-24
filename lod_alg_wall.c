#include "cub3d.h"

void	calculate_step_and_init_sideDist(t_vars *box)
{
	if (box->rayDirX < 0)
	{
		box->stepX = -1;
		box->sideDistX = (box->posX - box->mapX) * box->deltaDistX;
	}
	else
	{
		box->stepX = 1;
		box->sideDistX = (box->mapX + 1.0 - box->posX) \
		* box->deltaDistX;
	}
	if (box->rayDirY < 0)
	{
		box->stepY = -1;
		box->sideDistY = (box->posY - box->mapY) * box->deltaDistY;
	}
	else
	{
		box->stepY = 1;
		box->sideDistY = (box->mapY + 1.0 - box->posY) \
		* box->deltaDistY;
	}
}

void	dda(t_vars *box)
{
	while (box->hit == '0')
	{
		if (box->sideDistX < box->sideDistY)
		{
			box->sideDistX += box->deltaDistX;
			box->mapX += box->stepX;
			box->side = '0';
		}
		else
		{
			box->sideDistY += box->deltaDistY;
			box->mapY += box->stepY;
			box->side = '1';
		}
		if (box->arr_map[box->mapX][box->mapY] == '1')
			box->hit = '1';
	}
}

void	not_fish_eye_plus_height_wall(t_vars *box)
{
	if (box->side == '0')
		box->perpWallDist = (box->mapX - box->posX \
		+ (1 - box->stepX) / 2) / box->rayDirX;
	else
		box->perpWallDist = (box->mapY - box->posY \
		+ (1 - box->stepY) / 2) / box->rayDirY;
	box->lineHeight = (int)(box->height / box->perpWallDist);
	box->drawStart = -box->lineHeight / 2 + box->height / 2;
	if (box->drawStart < 0)
		box->drawStart = 0;
	box->drawEnd = box->lineHeight / 2 + box->height / 2;
	if (box->drawEnd >= box->height)
		box->drawEnd = box->height - 1;
}
