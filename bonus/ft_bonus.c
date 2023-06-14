/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:13:12 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/14 17:18:53 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	ft_events(t_vars *xvar)
{
	mlx_hook(xvar->win, __ON_MOUSEDOWN, __BUTTONPRESSMASK, ft_mousehook, xvar);
	mlx_hook(xvar->win, __ON_DESTROY, 0, ft_xbutton_close, xvar);
	mlx_hook(xvar->win, __ON_KEYDOWN, __KEYPRESSMASK, ft_keyhook, xvar);
}

int	ft_keyhook(int keycode, t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	if (keycode == __LEFT)
		xvar->fdbk = ft_translateleft(xvar);
	else if (keycode == __RIGHT)
		xvar->fdbk = ft_translateright(xvar);
	else if (keycode == __UP)
		xvar->fdbk = ft_translateup(xvar);
	else if (keycode == __DOWN)
		xvar->fdbk = ft_translatedown(xvar);
	else if (keycode == __LMIN)
		xvar->fdbk = ft_lower(xvar);
	else if (keycode == __HMIN)
		xvar->fdbk = ft_higher(xvar);
	else if (keycode == __ESC)
		ft_exitprocss(EXIT_SUCCESS, xvar);
	if (xvar->fdbk == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	return (0);
}

int	ft_mousehook(int button, int x, int y, t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	if (button == __ZOOMIN)
		xvar->fdbk = ft_zoomin(xvar);
	else if (button == __ZOOMOUT)
		xvar->fdbk = ft_zoomout(xvar);
	else if (button == __RIGHTBUTTON)
		xvar->fdbk = ft_rotateright(xvar);
	else if (button == __LEFTBUTTON)
		xvar->fdbk = ft_rotateleft(xvar);
	else if (button == __WHEELBUTTON)
		xvar->fdbk = ft_flat(xvar);
	if (xvar->fdbk == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	(void) x;
	(void) y;
	return (0);
}