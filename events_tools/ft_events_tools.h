/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:42:10 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 17:31:09 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENTS_TOOLS_H
# define FT_EVENTS_TOOLS_H

# include "../ft_fdf.h"

t_bool	ft_zoomin(t_vars *xvar);
t_bool	ft_zoomout(t_vars *xvar);
t_bool	ft_translateleft(t_vars *xvar);
t_bool	ft_translateright(t_vars *xvar);
t_bool	ft_translateup(t_vars *xvar);
t_bool	ft_translatedown(t_vars *xvar);
t_bool	ft_rotateright(t_vars *xvar);
t_bool	ft_rotateleft(t_vars *xvar);
t_bool	ft_flat(t_vars *xvar);
t_bool	ft_lower(t_vars *xvar);
t_bool	ft_higher(t_vars *xvar);

#endif