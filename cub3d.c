#include "cub3d.h"

int	all_step(t_vars *box, int argc)
{
	box->mlx = mlx_init();
	if (argc == 2)
	{
		box->win = mlx_new_window(box->mlx, box->width,
				box->height, "cub3d");
	}
	box->win = mlx_new_window(box->mlx, box->width,
			box->height, "cub3d");
	box->img = mlx_new_image(box->mlx, box->width, box->height);
	box->addr = mlx_get_data_addr(box->img, &box->bits_per_pixel,
			&box->line_length, &box->endian);
	draw_map(box);
	if (argc == 2)
	{
		mlx_hook(box->win, 2, 0, ft_key_press, box);
		mlx_hook(box->win, 17, 0, the_end, box);
		mlx_loop(box->mlx);
	}
	return (0);
}

void	check_extension(t_vars	*box, char *argv)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(argv);
	while (i < len)
	{
		if (argv[i] == '.')
			box->count_dot++;
		i++;
	}
	if (box->count_dot == 1)
	{
		box->argc_one = ft_strchr(argv, '.');
		if (ft_strncmp(".cub", box->argc_one, 5) != 0)
		{
			printf ("%s\n", "ERROR");
			exit (1);
		}
	}
	else
	{
		printf ("%s\n", "ERROR");
		exit (1);
	}
}

void	chech_fd(int fd)
{
	if (fd < 0)
	{
		printf ("%s\n", "ERROR");
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	box;

	check_extension(&box, argv[1]);
	if (argc == 2 || (argc == 3 && ft_strncmp("--save", argv[2], 7) == 0))
	{
		fd = open(argv[1], O_RDONLY);
		chech_fd(fd);
		ft_allstruct_init(&box);
		box.arr_map = ft_parser(fd, &box);
		close(fd);
		if ((ft_error(&box) == 1))
			exit(0);
		memory_zbuf(&box);
		ft_count_sprite(&box);
		check_place_player(&box);
		ft_check_sprite(&box);
		direction_n_s(&box);
		direction_e_w(&box);
		all_step(&box, argc);
		do_screenshot(&box);
	}
	else
		exit (0);
	return (0);
}
