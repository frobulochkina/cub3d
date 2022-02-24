#include "cub3d.h"

void	go_forward(t_vars *box)
{
	if (box->arr_map[(int)(box->posX + box->dirX * 0.2)]
			[(int)(box->posY)] != '1')
		box->plr_mas_x += box->dirX * 0.2;
	if (box->arr_map[(int)(box->posX)]
			[(int)(box->posY + box->dirY * 0.2)] != '1')
		box->plr_mas_y += box->dirY * 0.2;
}

void	go_back(t_vars *box)
{
	if (box->arr_map[(int)(box->posX - box->dirX * 0.2)]
			[(int)(box->posY)] != '1')
		box->plr_mas_x -= box->dirX * 0.2;
	if (box->arr_map[(int)(box->posX)]
			[(int)(box->posY - box->dirY * 0.2)] != '1')
		box->plr_mas_y -= box->dirY * 0.2;
}

void	go_left(t_vars *box)
{
	if (box->arr_map[(int)(box->posX - 3
			* box->dirY * 0.2)][(int)box->posY] != '1')
		box->plr_mas_x -= box->dirY * 0.2;
	if (box->arr_map[(int)box->posX][(int)
		(box->posY + 3 * box->dirX * 0.2)] != '1')
		box->plr_mas_y += box->dirX * 0.2;
}

void	go_right(t_vars *box)
{
	if (box->arr_map[(int)(box->posX + 3
			* box->dirY * 0.2)][(int)box->posY] != '1')
		box->plr_mas_x += box->dirY * 0.2;
	if (box->arr_map[(int)box->posX][(int)(box->posY
		- 3 * box->dirX * 0.2)] != '1')
		box->plr_mas_y -= box->dirX * 0.2;
}
