#include "cub3d.h"

int	the_end(void)
{
	exit(0);
	return (0);
}

void	turn_to_the_left(t_vars *box)
{
	box->oldDirX = box->dirX;
	box->dirX = box->dirX * cos(0.1) - box->dirY * sin(0.1);
	box->dirY = box->oldDirX * sin(0.1) + box->dirY * cos(0.1);
	box->oldPlaneX = box->planeX;
	box->planeX = box->planeX * cos(0.1) - box->planeY * sin(0.1);
	box->planeY = box->oldPlaneX * sin(0.1) + box->planeY * cos(0.1);
}

void	turn_to_the_right(t_vars *box)
{
	box->oldDirX = box->dirX;
	box->dirX = box->dirX * cos(-0.04) - box->dirY * sin(-0.04);
	box->dirY = box->oldDirX * sin(-0.04) + box->dirY * cos(-0.04);
	box->oldPlaneX = box->planeX;
	box->planeX = box->planeX * cos(-0.04) - box->planeY * sin(-0.04);
	box->planeY = box->oldPlaneX * sin(-0.04) + box->planeY * cos(-0.04);
}

int	ft_key_press(int keycode, t_vars *box)
{
	if (keycode == 13)
		go_forward(box);
	if (keycode == 1)
		go_back(box);
	if (keycode == 0)
		go_left(box);
	if (keycode == 2)
		go_right(box);
	if (keycode == 123)
		turn_to_the_left(box);
	if (keycode == 124)
		turn_to_the_right(box);
	if (keycode == 53)
	{
		exit(0);
		return (1);
	}
	draw_map(box);
	return (0);
}
