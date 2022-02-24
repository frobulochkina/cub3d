#include "cub3d.h"

void	order_and_distance(t_vars *box, int *spriteOrder
			, double *spriteDistance)
{
	int	i;

	i = 0;
	while (i < box->count_sprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((box->posX - box->array_sprite[i][0])
				* (box->posX - box->array_sprite[i][0]) + (box->posY
					 - box->array_sprite[i][1])
				* (box->posY - box->array_sprite[i][1]));
		i++;
	}
}

void	init_for_sprite(t_vars *box, int *spriteOrder, int i)
{
	box->sprite_x = box->array_sprite[spriteOrder[i]][0] - box->posX;
	box->sprite_y = box->array_sprite[spriteOrder[i]][1] - box->posY;
	box->inv_det = 1.0 / (box->planeX * box->dirY
			- box->dirX * box->planeY);
	box->transform_x = box->inv_det * (box->dirY
			* box->sprite_x - box->dirX * box->sprite_y);
	box->transform_y = box->inv_det * (-box->planeY
			* box->sprite_x + box->planeX * box->sprite_y);
	box->sprite_screen_x = (int)((box->width / 2)
			* (1 + box->transform_x / box->transform_y));
	box->v_move_screen = (int)(0.0 / box->transform_y);
	box->sprite_height = (int)fabs((box->height / box->transform_y) / 1);
	box->draw_start_y = -box->sprite_height / 2
		+ box->height / 2 + box->v_move_screen;
}

void	loop_vertical_two(t_vars *box, int y)
{
	box->d = (y - box->v_move_screen) * 256 - box->height \
	* 128 + box->sprite_height * 128;
	box->texY = ((box->d * box->texHeight) / box->sprite_height) / 256;
	box->color = my_mlx_pixel_put_get(box, box->texX, box->texY);
	if ((box->color & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(box, box->stripe, y, box->color);
}

void	loop_vertical_pride_stripe(t_vars *box)
{
	int	y;

	box->stripe = box->draw_start_x;
	while (box->stripe < box->draw_end_x)
	{
		box->texX = (int)((256 * (box->stripe - (-box->sprite_width / 2
							+ box->sprite_screen_x)) * box->texWidth
					/ box->sprite_width) / 256);
		if (box->transform_y > 0 && box->stripe > 0 && box->stripe
			< box->width && box->transform_y
			< box->zBuffer[box->stripe])
			y = box->draw_start_y;
		while (y < box->draw_end_y)
		{
			loop_vertical_two(box, y);
			y++;
		}
		box->stripe++;
	}
}

void	sprite_from_player(t_vars *box, int	*spriteOrder)
{
	int	i;

	i = 0;
	while (i < box->count_sprites)
	{
		init_for_sprite(box, spriteOrder, i);
		if (box->draw_start_y < 0)
			box->draw_start_y = 0;
		box->draw_end_y = box->sprite_height / 2
			+ box->height / 2 + box->v_move_screen;
		if (box->draw_end_y >= box->height)
			box->draw_end_y = box->height - 1;
		box->sprite_width = (int)fabs((box->height
					/ box->transform_y) / 1);
		box->draw_start_x = -box->sprite_width / 2 + box->sprite_screen_x;
		if (box->draw_start_x < 0)
			box->draw_start_x = 0;
		box->draw_end_x = box->sprite_width / 2 + box->sprite_screen_x;
		if (box->draw_end_x >= box->width)
			box->draw_end_x = box->width - 1;
		loop_vertical_pride_stripe(box);
		i++;
	}
}
