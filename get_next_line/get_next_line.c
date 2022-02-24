#include "get_next_line.h"
#include "../libft/libft.h"

size_t	ft_space_n(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*ft_processing(char **ostatok, char *buf_line)
{
	char	*tmp;

	if (*ostatok == NULL)
	{
		*ostatok = ft_strdup(buf_line);
		if (!*ostatok)
			return (NULL);
	}
	else
	{
		tmp = *ostatok;
		*ostatok = ft_strjoin(*ostatok, buf_line);
		if (!*ostatok)
			return (NULL);
	}
	return (*ostatok);
}

int	ft_write_to_line(char **ostatok, char **line, int rd)
{
	int		len;
	char	*tmp;

	if (ft_strchr(*ostatok, '\n'))
	{
		len = ft_space_n(*ostatok);
		*line = ft_substr(*ostatok, 0, len);
		if (!*line)
			free(ostatok);
		tmp = *ostatok;
		*ostatok = ft_substr(*ostatok, len + 1, ft_strlen(*ostatok));
		free(tmp);
	}
	else if ((ft_strchr(*ostatok, '\0') && rd == 0))
	{
		len = ft_strlen(*ostatok);
		*line = ft_substr(*ostatok, 0, ft_strlen(*ostatok));
		free(*ostatok);
	}
	if (!*line || !*ostatok)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				rd;
	char			buf_line[2];
	static char		*ostatok;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	rd = 0;
	while (rd >= 0)
	{
		rd = read(fd, buf_line, 1);
		buf_line[rd] = '\0';
		ostatok = ft_processing(&ostatok, buf_line);
		if (ft_strchr(ostatok, '\n'))
			return (ft_write_to_line(&ostatok, line, rd));
		else if (ft_strchr(ostatok, '\0') && rd == 0)
		{
			if (ft_write_to_line(&ostatok, line, rd) == -1)
				return (-1);
			ostatok = NULL;
			break ;
		}
	}
	if (rd < 0)
		return (-1);
	return (0);
}
