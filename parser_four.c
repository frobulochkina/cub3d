#include "cub3d.h"

int	when_len_prew(t_vars *box, int i, int j, char **arr_map)
{
	i = box->len_now;
	while (arr_map[j - 1][i] != '\0')
	{
		if (arr_map[j - 1][i] != '1')
		{
			box->error = -1;
			return (j);
		}
		i++;
	}
	return (j);
}

int	map_check(char **arr_map, t_vars *box, int i, int j)
{
	while (arr_map[j] != '\0')
	{
		box->len_now = ft_strlen(arr_map[j]);
		if (arr_map[j][box->len_now - 1] != '1')
		{
			box->error = -1;
			return (j);
		}
		if (box->len_now != box->len_prew)
		{
			if (box->len_now > box->len_prew)
				when_len_now(box, i, j, arr_map);
			else
				when_len_prew(box, i, j, arr_map);
		}
		box->len_prew = box->len_now;
		box->len_now = 0;
		j++;
	}
	return (j);
}

int	check_valid(char **arr_map, t_vars *box)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (arr_map[j][i] != '\0')
	{
		if (arr_map[j][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	box->len_prew = ft_strlen(arr_map[j]);
	j++;
	map_check(arr_map, box, i, j);
	box->len_prew = 0;
	j = j - 1;
	i = 0;
	while (arr_map[j][i] != '\0')
	{
		if (arr_map[j][i] != '1')
			return (-1);
		i++;
	}
	return (box->error);
}

int	check_valid_sim(char **arr_map)
{
	int	i;
	int	j;

	j = 1;
	while (arr_map[j])
	{
		i = 1;
		while (arr_map[j][i])
		{
			if ((arr_map[j][i] == '1' || arr_map[j][i] == '0' \
			|| arr_map[j][i] == '2') || (arr_map[j][i] == 'N' \
			|| arr_map[j][i] == 'E' || arr_map[j][i] == 'W' \
			|| arr_map[j][i] == 'S'))
				i++;
			else
				return (-2);
		}
		j++;
	}
	return (0);
}

int	check_line(t_vars *box, char *line)
{
	box->check = 2;
	if (ft_strchr(line, 'R') && (!ft_strchr(line, 'N')) \
	&& (!ft_strchr(line, 'S')) && (!ft_strchr(line, 'E')) \
	&& (!ft_strchr(line, 'W')))
		check_r(box, line);
	else if (ft_strchr(line, 'F'))
		check_f(box, line);
	else if (ft_strchr(line, 'C'))
		check_c(box, line);
	else if (ft_strchr(line, 'N') || ft_strchr(line, 'W') \
	|| ft_strchr(line, 'E') || ft_strchr(line, 'S'))
		check_n_w_e_s(box, line);
	else
		return (2);
	if (box->error < 0)
		return (0);
	return (1);
}
