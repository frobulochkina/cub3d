#include "cub3d.h"

void	memory_zbuf(t_vars *box)
{
	box->zBuffer = (double *)malloc(sizeof(double) * box->width);
}

void	ft_count_sprite(t_vars *box)
{
	int	i;
	int	j;

	j = 0;
	while (box->arr_map[j] != '\0')
	{
		i = 0;
		while (box->arr_map[j][i] != '\0')
		{
			if (box->arr_map[j][i] == '2')
			{
				box->count_sprites++;
			}
			i++;
		}
		j++;
	}
}

void	sort_order(t_data *sprites, t_vars *box)
{
	t_data	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < box->count_sprites)
	{
		j = 0;
		while (j < box->count_sprites - 1)
		{
			if (sprites[j].first > sprites[j + 1].first)
			{
				tmp.first = sprites[j].first;
				tmp.second = sprites[j].second;
				sprites[j].first = sprites[j + 1].first;
				sprites[j].second = sprites[j + 1].second;
				sprites[j + 1].first = tmp.first;
				sprites[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sortSprites(int *spriteOrder, double *spriteDistance,
		t_vars *box)
{
	t_data	*sprites;
	int		i;

	i = 0;
	sprites = (t_data *)malloc(sizeof(t_data) * box->count_sprites);
	while (i < box->count_sprites)
	{
		sprites[i].first = spriteDistance[i];
		sprites[i].second = spriteOrder[i];
		i++;
	}
	sort_order(sprites, box);
	i = 0;
	while (i < box->count_sprites)
	{
		spriteDistance[i] = sprites[box->count_sprites - i - 1].first;
		spriteOrder[i] = sprites[box->count_sprites - i - 1].second;
		i++;
	}
	free(sprites);
}

void	memory_sprites(t_vars *box)
{
	int	i;

	i = 0;
	box->array_sprite = (double **)malloc(sizeof(double *)
			* box->count_sprites);
	while (i < box->count_sprites)
	{
		box->array_sprite[i] = (double *)malloc(sizeof(double) * 2);
		i++;
	}
	if (box->array_sprite[box->count_sprites] == NULL)
	{
		free(box->array_sprite);
		exit(-1);
	}
}
