/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:12:23 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/30 12:10:09 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/includes/libft.h"
#include "get_next_line.h"

static int		ft_read_and_join(int const fd, char **join)
{
	char			buff[BUFF_SIZE + 1];
	char			*nstr;
	int				nb_bytes;

	nb_bytes = read(fd, buff, BUFF_SIZE);
	if (nb_bytes > 0)
	{
		if (buff[nb_bytes] != '\0')
			buff[nb_bytes + 1] = '\0';
		nstr = ft_strjoin(* join, buff);
		if (!nstr)
			return (-1);
		free(* join);
		* join = nstr;
	}
	return (nb_bytes);
}

int		get_next_line(const int fd, char **line)
{
	char			*endi;
	static char		*join;
	int				ret;

	if (!join && ((join = ft_strnew(0)) == NULL))
			return (-1);
	endi = ft_strchr(join, '\n');
	while (endi == NULL)
	{
		ret = ft_read_and_join(fd, &join);
		if (ret == 0 && endi == '\0')
			return (0);
		else if (ret == -1)
			return (-1);
		else
			endi = ft_strchr(join, '\n');
	}
	*line = ft_strsub(join, 0, endi - join);
	if (!*line)
		return (-1);
	ft_memdel((void **)&join);
	endi = ft_strdup(endi + 1);
	join = endi;
	return (1);
}
