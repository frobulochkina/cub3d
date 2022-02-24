#include "cub3d.h"

static void	zero_b(void *dest, size_t len)
{
	unsigned char	*cdest;

	cdest = (unsigned char *)dest;
	while (len--)
	{
		*cdest = 0;
		cdest += 1;
	}
}

void	*init_bitmap54(t_vars *box)
{
	static char	bitmap[54];

	zero_b(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = box->width * box->height * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = (int)box->width;
	*(int *)(bitmap + 22) = -(int)box->height;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	return ((void *)bitmap);
}

static int	create_clean(const char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		write(2, "ERROR: can't create file\n", 25);
	return (fd);
}

void	do_screenshot(t_vars *box)
{
	int		fd;
	void	*bitmap;

	fd = create_clean("screenshot.bmp");
	if (fd < 0)
		exit(-1);
	bitmap = init_bitmap54(box);
	write(fd, bitmap, 54);
	write(fd, box->addr, (box->height * box->width) * 4);
	close(fd);
}
