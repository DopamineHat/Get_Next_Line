/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:05:06 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/30 11:09:57 by rpagot           ###   ########.fr       */
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
		buff[nb_bytes] = '\0';
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
	int				*endi;
	static char		*join;
	int				ret;

	if (!join && ((join = ft_strnew(0)) == NULL))
		return (-1);
	endi = ft_strchr(join, '\n')

