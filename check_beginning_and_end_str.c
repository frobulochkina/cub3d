#include "cub3d.h"

void	check_beginning_str(t_vars *box, char *line, char flag)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != flag)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != flag)
			box->error = -6;
		i++;
	}
}

int	check_trash_inside_end(t_vars *box, char c, char flag)
{
	int	i;

	i = 0;
	if (flag == 'F')
		box->position = box->floor_pos;
	if (flag == 'C')
		box->position = box->ceilling_pos;
	if (flag == 'R')
		box->position = box->resolution_pos;
	while (box->position[i] != c && box->position[i] != '\0')
	{
		if (box->position[i] != ' ' && box->position[i] != '\t')
			return (1);
		i++;
	}
	if (box->position[i] == c)
	{
		if (flag == 'F')
			box->position_str_f = i + box->position_str_f + 1;
		if (flag == 'C')
			box->position_str_c = i + box->position_str_c + 1;
		return (0);
	}
	return (0);
}
