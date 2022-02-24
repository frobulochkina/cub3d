#include "cub3d.h"

int	ft_check_int(t_vars *box)
{
	if (box->width == -1 || box->height == -1
		|| box->floor_r == -1 || box->floor_g == -1
		|| box->floor_b == -1 || box->ceilling_r == -1
		|| box->ceilling_g == -1 || box->ceilling_b == -1
		|| box->no_path == 0 || box->we_path == 0
		|| box->ea_path == 0 || box->so_path == 0
		|| box->s_path == 0)
	{
		return (-6);
	}
	return (1);
}

int	ft_error(t_vars *box)
{
	if (box->error != 0 || box->arr_map == NULL)
	{
		if (box->error == -1)
			printf("error: map\n");
		else if (box->error == -2)
			printf("error: map\n");
		else if (box->error == -3)
			printf("error: map\n");
		else if (box->error == -4)
			printf("error: trash in resolution\n");
		else if (box->error == -5)
			printf("error: trash in texture\n");
		else if (box->error == -6)
			printf("error: trash in file\n");
		else if (box->error == -7)
			printf("error: trash in floor\n");
		else if (box->error == -8)
			printf("error: trash in ceilling\n");
		else if (box->error == -9)
			printf("error: trash in lines\n");
		return (1);
	}
	return (0);
}

void	ft_allstruct_init(t_vars *box)
{
	box->mlx = NULL;
	box->win = NULL;
	box->arr_map = NULL;
	box->width = -1;
	box->height = -1;
	box->position = 0;
	box->ceilling_r = -1;
	box->ceilling_g = -1;
	box->ceilling_b = -1;
	box->floor_r = -1;
	box->floor_g = -1;
	box->floor_b = -1;
}
