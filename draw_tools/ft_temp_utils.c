/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_temp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:20:44 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/16 16:38:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_local.h"

t_bool	ft_alloc2pt(t_coord **pt1, t_coord **pt2)
{
	*pt1 = NULL;
	*pt2 = NULL;
	*pt1 = ft_calloc(1, sizeof(t_coord));
	if (!*pt1)
		return (__FALSE);
	*pt2 = ft_calloc(1, sizeof(t_coord));
	if (!*pt2)
	{
		free(*pt1);
		*pt1 = NULL;
		return (__FALSE);
	}
	return (__TRUE);
}

void	ft_free2pt(t_coord **pt1, t_coord **pt2)
{
	if (*pt1)
		free(*pt1);
	*pt1 = NULL;
	if (*pt2)
		free(*pt2);
	*pt2 = NULL;
}

t_bool	ft_alloc3pt(t_coord **pt1, t_coord **pt2, t_coord **pt3)
{
	*pt1 = NULL;
	*pt2 = NULL;
	*pt3 = NULL;
	*pt1 = ft_calloc(1, sizeof(t_coord));
	if (!*pt1)
		return (__FALSE);
	*pt2 = ft_calloc(1, sizeof(t_coord));
	if (!*pt2)
	{
		free(*pt1);
		*pt1 = NULL;
		return (__FALSE);
	}
	*pt3 = ft_calloc(1, sizeof(t_coord));
	if (!*pt3)
	{
		free(*pt1);
		free(*pt2);
		*pt1 = NULL;
		*pt2 = NULL;
		return (__FALSE);
	}
	return (__TRUE);
}

void	ft_free3pt(t_coord **pt1, t_coord **pt2, t_coord **pt3)
{
	if (*pt1)
		free(*pt1);
	*pt1 = NULL;
	if (*pt2)
		free(*pt2);
	*pt2 = NULL;
	if (*pt3)
		free(*pt3);
	*pt3 = NULL;
}
