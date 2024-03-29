/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:34:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 13:45:35 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_TOOLS_H
# define FT_DRAW_TOOLS_H

# include "../ft_fdf.h"

t_bool	ft_drw_vector(t_vars *xvar, t_vec *vec);
void	ft_drw_2dspot(t_vars *xvar);
void	ft_drw_3dspot(t_vars *xvar);

#endif