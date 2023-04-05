/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:37:00 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 18:46:13 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOCAL_H
# define FT_LOCAL_H

# include "ft_draw_tools.h"

void	ft_trace(t_img *img, t_coord *pt1, t_coord *pt2);
void	ft_drw_2dspot(t_vars *xvar);
void	ft_drw_3dspot(t_vars *xvar);
t_bool	ft_drwin_3dspot(t_vars *xvar, t_coord *o, t_coord *e);
t_bool	ft_checkinframe(int x, int y, int height, int width);
void	ft_ad_in3dspot(t_coord *pt);
t_bool	ft_3d_to_2dbase(t_coord *pt);
void	ft_add_step(t_coord *pt);
void	ft_cpyvertex(t_coord *dst, t_coord *src);
t_bool	ft_alloc2pt(t_coord **pt1, t_coord **pt2);
void	ft_free2pt(t_coord **pt1, t_coord **pt2);
t_bool	ft_alloc3pt(t_coord **pt1, t_coord **pt2, t_coord **pt3);
void	ft_free3pt(t_coord **pt1, t_coord **pt2, t_coord **pt3);

#endif