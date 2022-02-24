#include "cub3d.h"

void	img_texture(t_vars *box, char *path)
{
	box->img_tex = mlx_xpm_file_to_image(box->mlx, path, \
	&box->texWidth, &box->texHeight);
	if (!box->img_tex)
		exit (1);
	box->addr_tex = mlx_get_data_addr(box->img_tex,
			&box->bits_per_pixel_tex,
			&box->line_length_tex, &box->endian_tex);
}

void	init_img_all_texture(t_vars *box)
{
	if (box->rayDirX > 0)
		img_texture(box, box->so_path);
	if (box->rayDirX < 0)
		img_texture(box, box->no_path);
	if (box->rayDirY > 0)
		img_texture(box, box->ea_path);
	if (box->rayDirY < 0)
		img_texture(box, box->we_path);
}
