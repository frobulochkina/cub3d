#include "get_next_line.h"
#include "../libft/libft.h"

static size_t	ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	unsigned char	*tmp;
	size_t			i;

	s = malloc(count * size);
	tmp = (unsigned char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < count)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

static	char	*ft_strdup(const char *s1)
{
	char			*news1;
	int				i;
	int				size;

	size = 0;
	while (s1[size])
		size++;
	news1 = ft_calloc(size + 1, sizeof(char));
	if (!news1)
		return (0);
	i = 0;
	while (s1[i])
	{
		news1[i] = s1[i];
		i++;
	}
	news1[i] = '\0';
	return (news1);
}
