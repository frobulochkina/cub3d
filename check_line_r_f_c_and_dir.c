#include "cub3d.h"

void	check_r(t_vars *box, char *line)
{
	if (box->width == -1 && box->height == -1)
	{
		check_beginning_str(box, line, 'R');
		if (box->error == 0)
			resolution_reading(line, box);
	}
	else
	{
		box->error = -4;
	}
}

void	check_f(t_vars *box, char *line)
{
	if (box->floor_r == -1 && box->floor_g == -1 && box->floor_b == -1)
	{
		check_beginning_str(box, line, 'F');
		if (box->error == 0)
			floor_reading(line, box);
	}
	else
	{
		box->error = -7;
	}
}

void	check_c(t_vars *box, char *line)
{
	if (box->ceilling_r == -1 && box->ceilling_g == -1
		&& box->ceilling_b == -1)
	{
		check_beginning_str(box, line, 'C');
		if (box->error == 0)
			ceilling_reading(line, box);
	}
	else
	{
		box->error = -6;
	}
}

int	check_n_w_e_s(t_vars *box, char *line)
{
	if (ft_strchr(line, 'N'))
	{
		box->position = ft_strchr(line, 'N');
		if ((check_line_texture(box, line)) == 0)
			return (0);
	}
	else if (ft_strchr(line, 'W'))
	{
		box->position = ft_strchr(line, 'W');
		if ((check_line_texture(box, line)) == 0)
			return (0);
	}
	else if (ft_strchr(line, 'E'))
	{
		box->position = ft_strchr(line, 'E');
		if ((check_line_texture(box, line)) == 0)
			return (0);
	}
	else if (ft_strchr(line, 'S'))
	{
		box->position = ft_strchr(line, 'S');
		if ((check_line_texture(box, line)) == 0)
			return (0);
	}
	return (0);
}
