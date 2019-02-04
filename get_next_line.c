/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:21:15 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/04 12:47:50 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	str[4096][BUFF_SIZE + 1];
	char		*buf;
	char		*cur;
	int			ret;

	buf = str[fd];
	if (fd < 0 || (ret = read(fd, buf, BUFF_SIZE)) < 0 || !*line)
		return (-1)
	*line = ft_strnew(1);
	while (true)
	{
		if ((cur = ft_strchr(buf, 10)))
		{
			*line = ft_strjoinfree(*line, buf, cur - buf, 1);
			//Garder le curseur de lecture en static
			return (1);
		}
		
		//Append tout buf a line en passant par str
		//Verifier que si on as fini de lire, on free line, et ret 0  nan ?
	}
}
