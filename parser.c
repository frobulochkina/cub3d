#include "cub3d.h"

void	ft_check_str(char **arr_map, t_vars *box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr_map[j])
	{
		if (arr_map[j][i] == '0')
			box->error = -1;
		j++;
	}
}

void	check_map_j_i_two(char **arr_map, t_vars *box, int j)
{
	if (arr_map[j][box->end] == ' ')
		arr_map[j][box->end] = '1';
	box->end--;
}

void	check_map_j_i(char **arr_map, t_vars *box, int j, int i)
{
	while (arr_map[j])
	{
		while (arr_map[j][i] != '\0' && arr_map[j][i] != '0' \
		&& arr_map[j][i] != '1' && arr_map[j][i] != '2' \
		&& arr_map[j][i] != 'N' && arr_map[j][i] != 'W' \
		&& arr_map[j][i] != 'E' && arr_map[j][i] != 'S')
		{
			if (arr_map[j][i] == ' ')
				arr_map[j][i] = '1';
			else if (arr_map[j][i] == '0' && arr_map[j][i] != '1')
				box->error = -1;
			i++;
		}
		box->end = ft_strlen(arr_map[j]);
		while (arr_map[j][box->end] != '0' \
		&& arr_map[j][box->end] != '1' \
		&& arr_map[j][box->end] != '2' \
		&& arr_map[j][box->end] != 'N' &&
		arr_map[j][i] != 'W' && arr_map[j][i] != 'E' \
		&& arr_map[j][i] != 'S')
			check_map_j_i_two(arr_map, box, j);
		j++;
	}
}

char	**check_map(char **arr_map, t_vars *box)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_check_str(arr_map, box);
	check_map_j_i(arr_map, box, j, i);
	box->error = check_valid(arr_map, box);
	if (box->error < 0)
		return (NULL);
	if (box->error != -1)
		box->error = check_valid_sim(arr_map);
	return (arr_map);
}

int	when_len_now(t_vars *box, int i, int j, char **arr_map)
{
	i = box->len_prew;
	while (arr_map[j][i] != '\0')
	{
		if (arr_map[j][i] != '1')
		{
			box->error = -1;
			return (j);
		}
		i++;
	}
	return (j);
}
