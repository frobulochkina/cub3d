#include "libft.h"
#include <stdio.h>

static	char	ft_count_word(const char *s, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == sep)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == sep && s[i + 1] != sep) || s[i + 1] == '\0')
		{
			count += 1;
		}
		i++;
	}
	return (count + 1);
}

static	char	*ft_create_word(char *mas, const char *s,
							size_t i, size_t len_w)
{
	size_t	j;

	j = 0;
	while (i < len_w)
	{
		mas[j] = s[i];
		j++;
		i++;
	}
	mas[j] = '\0';
	return (mas);
}

static	void	ft_free_malloc(char **news, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(news[i]);
		i++;
	}
	free(news);
}

static	char	**ft_create_arrays(const char *s, char **mas,
							char sep, size_t count)
{
	size_t	i;
	size_t	len_w;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i] != '\0' && count - 1 > words)
	{
		while (s[i] == sep && s[i])
			i++;
		len_w = i;
		while (s[len_w] != sep && s[len_w])
			len_w++;
		mas[words] = (char *)malloc(sizeof(char) * (len_w - i) + 1);
		if (!mas[words])
		{
			ft_free_malloc(mas, words);
			return (NULL);
		}
		ft_create_word(mas[words], s, i, len_w);
		words++;
		i = len_w;
	}
	mas[words] = NULL;
	return (mas);
}

char	**ft_split(char const *s, char c)
{
	char	**news;
	size_t	word;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	news = (char **)malloc(sizeof(char *) * word);
	if (!news)
		return (NULL);
	news = ft_create_arrays(s, news, c, word);
	return (news);
}
