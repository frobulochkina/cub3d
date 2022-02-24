#include "cub3d.h"

void	check_place_player(t_vars *box)
{
	int	j;
	int	i;

	j = 0;
	while (box->arr_map[j] != '\0')
	{
		i = 0;
		while (box->arr_map[j][i] != '\0')
		{
			if (box->arr_map[j][i] == 'N' || box->arr_map[j][i] == 'W' \
			|| box->arr_map[j][i] == 'S' || box->arr_map[j][i] == 'E' )
			{
				box->plr_direction = box->arr_map[j][i];
				box->plr_mas_x = j;
				box->plr_mas_y = i;
				box->arr_map[j][i] = '0';
				break ;
			}
			i++;
		}
		if (box->plr_mas_x != 0 && box->plr_mas_y != 0)
			break ;
		j++;
	}
}

char	ft_strchr_i(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	check_last_place_after_all_arg(t_vars *box, char flag)
{
	while (*box->position != '\0' || *box->position == ' ' \
	|| *box->position == '\t')
	{
		if (*box->position != ' ' && *box->position != '\t')
		{
			if (flag == 'f')
				box->error = -7;
			if (flag == 'c')
				box->error = -8;
		}
		box->position++;
	}
}
