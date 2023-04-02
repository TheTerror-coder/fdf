/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:34:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 17:03:00 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_TOOLS_H
# define FT_DRAW_TOOLS_H

# include "../ft_fdf.h"

void	ft_trace(t_img *img, t_coord *pt1, t_coord *pt2, int color);
void	ft_drw_2dspot(t_vars *xvar);
void	ft_drw_3dspot(t_vars *xvar);
void	ft_drwin_3dspot(t_vars *xvars, t_coord *o, t_coord *e, int color);
void	ft_drw_vector(t_vars *xvar, t_vec *vec, int	color);
t_bool	ft_checkinframe(int x, int y, int height, int width);
void	ft_ad_in3dspot(t_coord *pt);
void	ft_3d_to_2dbase(t_coord *pt);
void	ft_add_step(t_coord *pt);
void	ft_cpyvertex(t_coord *dst, t_coord *src);

#endif