/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keepnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:18:45 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 16:22:58 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	**ft_keepnum_op(char **data, int len, int i, int j);

char	**ft_keepnum(char **data)
{
	char	**newdata;
	int		i;
	int		len;

	i = 0;
	len = 0;
	newdata = NULL;
	if (!data)
		return (NULL);
	while (data[i])
	{
		if (ft_contain_num(data[i]) == __TRUE)
			len++;
		i++;
	}
	newdata = ft_keepnum_op(data, len, 0, 0);
	ft_freesplit(data);
	data = NULL;
	return (newdata);
}

char	**ft_keepnum_op(char **data, int len, int i, int j)
{
	char	**newdata;

	newdata = NULL;
	if (!len)
		return (NULL);
	newdata = ft_calloc(len + 1, sizeof(char *));
	if (!newdata)
		return (NULL);
	while (data[i])
	{
		if (ft_contain_num(data[i]) == __TRUE)
		{
			newdata[j] = ft_strdup(data[i]);
			if (!newdata[j])
			{
				ft_freesplit(newdata);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	newdata[j] = NULL;
	return (newdata);
}
