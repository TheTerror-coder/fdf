/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:36:50 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/31 18:42:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETDATA_H
# define FT_GETDATA_H

#include "../ft_fdf.h"

t_bool	ft_addindex(t_vars *xvar, int i);
t_bool	ft_getdata(t_vars *xvar);
t_bool	ft_setvectors(t_vars *xvar);
void	ft_set_lenlist(t_vars *xvar);

#endif