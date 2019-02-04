/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:21:15 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/04 15:01:22 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strnjoinfree(char *s1, char *s2, size_t n)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strncat(ret, s2, n);
	ft_strdel(&s1);
	return (ret);
}

static int		die(char **line)
{
	if (!**line)
	{
		ft_strdel(line);
		return (0);
	}
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	str[4096][BUFF_SIZE + 1];
	char		*buf;
	char		*cur;
	int			ret;

	buf = str[fd];
	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	while (TRUE)
	{
		if ((cur = ft_strchr(buf, 10)))
		{
			*line = ft_strnjoinfree(*line, buf, cur - buf);
			ft_strncpy(buf, &buf[cur - buf + 1], BUFF_SIZE - (cur - buf));
			return (1);
		}
		*line = ft_strnjoinfree(*line, buf, BUFF_SIZE);
		ret = read(fd, str[fd], BUFF_SIZE);
		buf[ret] = '\0';
		if (!ret)
			return (die(line));
	}
}
