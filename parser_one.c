#include "cub3d.h"

void	resolution_reading(char *line, t_vars *box)
{
	int	max_width;
	int	max_height;
	int	i;

	i = ft_strchr_i(line, 'R');
	mlx_get_screen_size(&max_width, &max_height);
	box->resolution_pos = &line[++i];
	box->width = ft_atoi_for_resolution(box->resolution_pos, box, i);
	if (box->width <= -1)
		box->error = -4;
	box->resolution_pos = &line[box->position_str_r];
	i = box->position_str_r;
	box->height = ft_atoi_for_resolution(box->resolution_pos, box, i);
	if (box->height <= -1)
		box->error = -4;
	if (box->width > max_width)
		box->width = max_width;
	if (box->height > max_height)
		box->height = max_height;
	i = box->position_str_r;
	box->resolution_pos = &line[box->position_str_r];
	if ((check_trash_inside_end(box, '\0', 'R') == 1))
		box->error = -4;
}

void	floor_reading_if_all_ok(char *line, int i, t_vars *box)
{
	box->floor_r = atoi_floor(box->floor_pos, box, i);
	i = box->position_str_f;
	box->floor_pos = &line[box->position_str_f];
	if (box->floor_r <= -1)
		box->error = -7;
	if ((check_trash_inside_end(box, ',', 'F') == 1))
		box->error = -7;
	i = box->position_str_f;
	box->floor_pos = &line[i];
	box->floor_g = atoi_floor(box->floor_pos, box, i);
	i = box->position_str_f;
	box->floor_pos = &line[box->position_str_f];
	if (box->floor_g <= -1)
		box->error = -7;
	if ((check_trash_inside_end(box, ',', 'F') == 1))
		box->error = -7;
	i = box->position_str_f;
	box->floor_pos = &line[i];
	box->floor_b = atoi_floor(box->floor_pos, box, i);
	i = box->position_str_f;
	box->floor_pos = &line[box->position_str_f];
	if (box->floor_b <= -1)
		box->error = -7;
	if ((check_trash_inside_end(box, '\0', 'F') == 1))
		box->error = -7;
}

void	floor_reading(char *line, t_vars *box)
{
	int	i;

	i = ft_strchr_i(line, 'F');
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			box->count_comma += 1;
		i++;
	}
	i = ft_strchr_i(line, 'F');
	if (box->count_comma == 2)
	{
		box->floor_pos = &line[++i];
		floor_reading_if_all_ok(line, i, box);
		if (box->floor_r > 255 || box->floor_g > 255 || box->floor_b > 255)
			box->error = -7;
		if (box->floor_r < 0 || box->floor_g < 0 || box->floor_b < 0)
			box->error = -7;
	}
	else
		box->error = -7;
	box->count_comma = 0;
}

void	ceilling_reading_if_all_ok(char *line, int i, t_vars *box)
{
	box->ceilling_r = atoi_ceilling(box->ceilling_pos, box, i);
	i = box->position_str_c;
	box->ceilling_pos = &line[box->position_str_c];
	if (box->ceilling_r <= -1)
		box->error = -8;
	if ((check_trash_inside_end(box, ',', 'C') == 1))
		box->error = -8;
	i = box->position_str_c;
	box->ceilling_pos = &line[i];
	box->ceilling_g = atoi_ceilling(box->ceilling_pos, box, i);
	i = box->position_str_c;
	box->ceilling_pos = &line[box->position_str_c];
	if (box->ceilling_g <= -1)
		box->error = -8;
	if ((check_trash_inside_end(box, ',', 'C') == 1))
		box->error = -8;
	i = box->position_str_c;
	box->ceilling_pos = &line[i];
	box->ceilling_b = atoi_ceilling(box->ceilling_pos, box, i);
	i = box->position_str_c;
	box->ceilling_pos = &line[box->position_str_c];
	if (box->ceilling_b <= -1)
		box->error = -8;
	if ((check_trash_inside_end(box, '\0', 'C') == 1))
		box->error = -8;
}

void	ceilling_reading(char *line, t_vars *box)
{
	int	i;

	i = ft_strchr_i(line, 'C');
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			box->count_comma += 1;
		i++;
	}
	i = ft_strchr_i(line, 'C');
	if (box->count_comma == 2)
	{
		box->ceilling_pos = &line[++i];
		ceilling_reading_if_all_ok(line, i, box);
		if (box->ceilling_r > 255 || box->ceilling_g > 255 \
		|| box->ceilling_b > 255)
			box->error = -7;
		if (box->ceilling_r < 0 || box->ceilling_g < 0 \
		|| box->ceilling_b < 0)
			box->error = -7;
	}
	else
		box->error = -8;
	box->count_comma = 0;
}
