/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:12:03 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/29 09:13:46 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"

# define BUFF_SIZE 1

typedef struct s_stock
{
	struct	s_stock		*next;
	int					fd;
	char				*str;
}						t_stock;

int		get_next_line(const int fd, char **line);

#endif
