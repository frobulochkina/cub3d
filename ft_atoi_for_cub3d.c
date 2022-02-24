#include "cub3d.h"

int	atoi_floor(char *str, t_vars *box, int i)
{
	box->number_f = 0;
	while (!(str[box->count] >= '0' && str[box->count] <= '9'))
	{
		if (str[box->count] == '-')
		{
			if (!(str[box->count++] >= '0' && str[box->count] <= '9'))
				return (box->error = -9);
			if (str[box->count] == '0')
				return (box->number_f);
		}
		if (str[box->count] == ' ' || str[box->count] == '\n' \
		|| str[box->count] == '\t')
			box->count++;
		else
			return (-2);
	}
	while (str[box->count] >= '0' && str[box->count] <= '9')
	{
		box->number_f = box->number_f * 10 + (str[box->count++] - '0');
		if (box->number_f > 2147483647)
			return (box->error = -4);
	}
	box->position_str_f = box->count + i;
	box->count = 0;
	return (box->number_f);
}

int	atoi_ceilling(char *str, t_vars *box, int i)
{
	box->number_c = 0;
	while (!(str[box->count] >= '0' && str[box->count] <= '9'))
	{
		if (str[box->count] == '-')
		{
			if (!(str[box->count++] >= '0' && str[box->count] <= '9'))
				return (box->error = -9);
			if (str[box->count] == '0')
				return (box->number_c);
		}
		if (str[box->count] == ' ' || str[box->count] == '\n' \
		|| str[box->count] == '\t')
			box->count++;
		else
			return (-2);
	}
	while (str[box->count] >= '0' && str[box->count] <= '9')
	{
		box->number_c = box->number_c * 10 + (str[box->count++] - '0');
		if (box->number_c > 2147483647)
			return (box->error = -4);
	}
	box->position_str_c = box->count + i;
	box->count = 0;
	return (box->number_c);
}

int	ft_atoi_for_resolution(char *str, t_vars *box, int i)
{
	unsigned long int	number;
	int					j;

	number = 0;
	j = 0;
	while (!(str[j] >= '0' && str[j] <= '9'))
	{
		if (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
			j++;
		else
			return (-2);
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		number = number * 10 + (str[j] - '0');
		j++;
		if (number > 2147483647)
			return (box->error = -4);
	}
	box->position_str_r = i + j;
	return (number);
}
