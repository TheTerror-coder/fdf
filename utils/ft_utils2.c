/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:14:40 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 15:23:25 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_bool	ft_set_jx(t_vars *xvar)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (!xvar)
		return (__FALSE);
	fd = open(xvar->map, O_RDONLY);
	if (fd < 0)
		return (__FALSE);
	line = get_next_line(fd);
	if (!line)
		return (__FALSE);
	while (line)
	{
		xvar->jx++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	fd = close(fd);
	if (fd < 0)
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_contain_num(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (__FALSE);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (__TRUE);
		i++;
	}
	return (__FALSE);
}
