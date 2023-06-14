/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:50:51 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/14 15:28:41 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "../ft_fdf.h"

void	ft_events(t_vars *xvar);
int		ft_mousehook(int button, int x, int y, t_vars *xvar);
int		ft_keyhook(int keycode, t_vars *xvar);

#endif