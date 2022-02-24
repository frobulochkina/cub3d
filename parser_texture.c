#include "cub3d.h"

void	s_reading(t_vars *box)
{
	int		fd;
	char	*path;
	int		i;

	fd = 0;
	i = 0;
	path = box->s_path;
	box->position++;
	if (box->position[i] == ' ' || box->position[i] == '\t')
	{
		while ((box->position[i] == ' ' || box->position[i] == '\t') && (box->position[i] != '/' \
		|| box->position[i] != '.'))
			i++;
	}
	else
		box->error = -6;
	box->s_path = &box->position[i];
	path = box->s_path;
	check_after_and_before_path(box, path);
	texsture_open_or_no(box, fd, box->s_path);
}

void	no_reading(t_vars *box)
{
	int		fd;
	char	*path;
	int		i;

	fd = 0;
	i = 0;
	path = box->no_path;
	box->position++;
	if (box->position[i] == ' ' || box->position[i] == '\t')
	{
		while ((box->position[i] == ' ' || box->position[i] == '\t') && (box->position[i] != '/' \
		|| box->position[i] != '.'))
			i++;
	}
	else
		box->error = -6;
	box->no_path = &box->position[i];
	path = box->no_path;
	check_after_and_before_path(box, path);
	texsture_open_or_no(box, fd, box->no_path);
}

void	ea_reading(t_vars *box)
{
	int		fd;
	char	*path;
	int		i;

	fd = 0;
	i = 0;
	path = box->ea_path;
	box->position++;
	if (box->position[i] == ' ' || box->position[i] == '\t')
	{
		while ((box->position[i] == ' ' || box->position[i] == '\t') && (box->position[i] != '/' \
		|| box->position[i] != '.'))
			i++;
	}
	else
		box->error = -6;
	box->ea_path = &box->position[i];
	path = box->ea_path;
	check_after_and_before_path(box, path);
	texsture_open_or_no(box, fd, box->ea_path);
}

void	so_reading(t_vars *box)
{
	int		fd;
	char	*path;
	int		i;

	fd = 0;
	i = 0;
	path = box->so_path;
	box->position++;
	if (box->position[i] == ' ' || box->position[i] == '\t')
	{
		while ((box->position[i] == ' ' || box->position[i] == '\t') && (box->position[i] != '/' \
		|| box->position[i] != '.'))
			i++;
	}
	else
		box->error = -6;
	box->so_path = &box->position[i];
	path = box->so_path;
	check_after_and_before_path(box, path);
	texsture_open_or_no(box, fd, box->so_path);
}

void	we_reading(t_vars *box)
{
	int		fd;
	char	*path;
	int		i;

	fd = 0;
	i = 0;
	path = box->we_path;
	box->position++;
	if (box->position[i] == ' ' || box->position[i] == '\t')
	{
		while ((box->position[i] == ' ' || box->position[i] == '\t') && (box->position[i] != '/' \
		|| box->position[i] != '.'))
			i++;
	}
	else
		box->error = -6;
	box->we_path = &box->position[i];
	path = box->we_path;
	check_after_and_before_path(box, path);
	texsture_open_or_no(box, fd, box->we_path);
}
