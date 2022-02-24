#include "cub3d.h"

int	ft_check_two(t_vars *box, int y)
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
				box->array_sprite[y][0] = j + 0.5;
				box->array_sprite[y][1] = i + 0.5;
				box->arr_map[j][i] = '0';
				return (0);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_check_sprite(t_vars *box)
{
	int	j;

	memory_sprites(box);
	j = 0;
	while (j < box->count_sprites)
	{
		ft_check_two(box, j);
		j++;
	}
}

void	ft_sprites(t_vars *box)
{
	int		*spriteOrder;
	double	*spriteDistance;

	spriteOrder = (int *)malloc(sizeof(int) * box->count_sprites);
	spriteDistance = (double *)malloc(sizeof(double) * box->count_sprites);
	img_texture(box, box->s_path);
	order_and_distance(box, spriteOrder, spriteDistance);
	sortSprites(spriteOrder, spriteDistance, box);
	sprite_from_player(box, spriteOrder);
	free(spriteOrder);
	free(spriteDistance);
}
