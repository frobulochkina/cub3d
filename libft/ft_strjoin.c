#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*newcon;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if ((s1 == 0 && s2 == 0) || s1 == 0)
		return (NULL);
	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	newcon = (char *)malloc(sizeof(char *) * (len_s1 + len_s2) + 1);
	while (i < len_s1 || i < (len_s1 + len_s2))
	{
		while (i < len_s1)
		{
			newcon[i] = s1[i];
			i++;
		}
		newcon[i++] = s2[j++];
	}
	newcon[i] = '\0';
	free(s1);
	return (newcon);
}
