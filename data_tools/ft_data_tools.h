/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:36:50 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 18:55:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_TOOLS_H
# define FT_DATA_TOOLS_H

# include "../ft_fdf.h"

t_bool	ft_addindex(t_vars *xvar, int i);
t_bool	ft_getdata(t_vars *xvar);
t_bool	ft_setvectors(t_vars *xvar);

#endif