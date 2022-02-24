#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*news1;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		size++;
	news1 = malloc(sizeof(char) * (size + 1));
	if (!news1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		news1[i] = s1[i];
		i++;
	}
	news1[i] = '\0';
	return (news1);
}
