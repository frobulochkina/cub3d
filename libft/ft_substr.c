#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	subs = (char *)malloc(sizeof(char) * len + 1);
	if (ft_strlen(s) < len || (!(subs)))
	{
		subs = (char *)malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
	}
	while (s[start] && j < len)
		subs[j++] = s[start++];
	subs[len] = '\0';
	return (subs);
}
