/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 01:40:40 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/07 01:40:47 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	int		strlen;
	char	*strdup;

	i = 0;
	strlen = ft_strlen((char*)str);
	strdup = (char*)malloc((strlen + 1) * sizeof(*str));
	if (!strdup)
		return (NULL);
	strdup[strlen + 1] = '\0';
	while (i <= strlen)
	{
		strdup[i] = str[i];
		i++;
	}
	return (strdup);
}
