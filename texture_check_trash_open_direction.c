#include "cub3d.h"

void	texsture_open_or_no(t_vars *box, int fd, char *path)
{
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		box->error = -5;
		ft_error(box);
		exit(0);
	}
}

void	check_after_and_before_path(t_vars *box, char *path)
{
	int	i;
	int	j;	

	i = 0;
	j = 0;
	while (path[i] != '\0')
	{
		if (path[i] == ' ' || path[i] == '\t')
		{
			j = i;
			while (path[i] != '\0')
			{
				if (path[i] != ' ' && path[i] != '\t')
					box->error = -5;
				i++;
			}
			path[j] = '\0';
		}
		i++;
	}
}

int	direction_n_s(t_vars *box)
{
	if (box->plr_direction == 'N')
	{
		box->dirX = -1;
		box->dirY = 0;
		box->planeX = 0;
		box->planeY = 0.66;
	}
	else if (box->plr_direction == 'S')
	{
		box->dirX = 1;
		box->dirY = 0;
		box->planeX = 0;
		box->planeY = -0.66;
	}
	return (0);
}

int	direction_e_w(t_vars *box)
{
	if (box->plr_direction == 'E')
	{
		box->dirX = 0;
		box->dirY = 1;
		box->planeX = 0.66;
		box->planeY = 0;
	}
	else if (box->plr_direction == 'W')
	{
		box->dirX = 0;
		box->dirY = -1;
		box->planeX = -0.66;
		box->planeY = 0;
	}
	return (0);
}
