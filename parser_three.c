#include "cub3d.h"

void	splice_before_end(t_vars *box, char *line)
{
	int	j;
	int	i;

	if (*line == 0 && *line != ' ' && *line != '\t')
		box->error = -9;
	j = 0;
	i = 0;
	while (box->line_all[i] != '\0')
	{
		if (box->line_all[i] == 'N' || box->line_all[i] == 'E' \
		|| box->line_all[i] == 'W' || box->line_all[i] == 'S')
			j++;
		i++;
	}
	if (j != 1)
		box->error = -3;
}

void	when_wall(t_vars *box, char *line)
{
	if (*line == 0)
		box->error = -9;
}

void	when_wall_two(t_vars *box, char *line)
{
	box->count_lines++;
	box->line_all = ft_strjoin(box->line_all, line);
	box->line_all = ft_strjoin(box->line_all, box->str_with_n);
	free(line);
	if (box->error < 0)
		box->error = -1;
}

void	reading_map(t_vars *box, char *line)
{
	int	i;

	i = 0;
	if (ft_strchr(box->line_all, '1'))
		when_wall(box, line);
	if ((ft_check_int(box) == 1) && ft_strchr(line, '1'))
		when_wall_two(box, line);
	else if (check_line(box, line) == 2)
	{
		while (line[i] != '\0')
		{
			if (line[i] != ' ' || line[i] != '\t')
				box->error = -9;
			i++;
		}
		free(line);
	}
	else if (box->check == 0)
		box->error = -1;
}

char	**ft_parser(int fd, t_vars *box)
{
	char	*line;
	char	**arr_map;

	box->line_all = (char *)malloc(1);
	box->line_all[0] = '\0';
	box->str_with_n = (char *)malloc(2);
	box->str_with_n[0] = '\n';
	box->str_with_n[1] = '\0';
	while (get_next_line(fd, &line) > 0)
		reading_map(box, line);
	splice_before_end(box, line);
	box->line_all = ft_strjoin(box->line_all, line);
	box->line_all = ft_strjoin(box->line_all, box->str_with_n);
	box->count_lines++;
	arr_map = ft_split(box->line_all, '\n');
	arr_map = check_map(arr_map, box);
	free(line);
	return (arr_map);
}
