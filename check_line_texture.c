#include "cub3d.h"

void	meet_n(t_vars *box, char *line)
{
	box->position = ft_strchr(line, 'N');
	box->position++;
	if (*box->position == 'O')
	{
		check_beginning_str(box, line, 'N');
		no_reading(box);
	}
	else
		box->error = -6;
}

void	meet_w(t_vars *box, char *line)
{
	box->position = ft_strchr(line, 'W');
	box->position++;
	if (ft_strchr(line, 'E'))
	{
		box->position = ft_strchr(line, 'E');
		check_beginning_str(box, line, 'W');
		we_reading(box);
	}
}

void	meet_e(t_vars *box, char *line)
{
	box->position = ft_strchr(line, 'E');
	box->position++;
	if (ft_strchr(line, 'A'))
	{
		box->position = ft_strchr(line, 'A');
		check_beginning_str(box, line, 'E');
		ea_reading(box);
	}
}

void	meet_s(t_vars *box, char *line)
{
	box->position = ft_strchr(line, 'S');
	box->position++;
	if (ft_strchr(line, 'O'))
	{
		box->position = ft_strchr(line, 'O');
		check_beginning_str(box, line, 'S');
		so_reading(box);
	}
	else
	{
		box->position = ft_strchr(line, 'S');
		check_beginning_str(box, line, 'S');
		s_reading(box);
	}
}

int	check_line_texture(t_vars *box, char *line)
{
	if (ft_strchr(line, 'N'))
		meet_n(box, line);
	else if (ft_strchr(line, 'W'))
		meet_w(box, line);
	else if (ft_strchr(line, 'E'))
		meet_e(box, line);
	else if (ft_strchr(line, 'S'))
		meet_s(box, line);
	else
		return (0);
	return (1);
}
