/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 18:33:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "../ft_fdf.h"

char	**ft_keepnum(char **data);
int		ft_xbutton_close(t_vars *xvar);
int		ft_keyhook(int keycode, t_vars *xvar);
int		ft_mousehook(int button, int x, int y, t_vars *xvar);
int		ft_lensplit(char **sstr);
double	ft_percent(double n, double per);
t_bool	ft_set_mlx(t_vars *xvar);
t_bool	ft_checkextension(char	*name);
t_bool	ft_contain_num(char *str);
t_bool	ft_set_jx(t_vars *xvar);
t_vec	*ft_alloc_vect(unsigned int nmemb, unsigned int size);
t_vars	*ft_init_tvars();
void	ft_free_listvec(t_vars *xvar);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_freesplit(char **str);
void	ft_freezdata(t_vars *xvar);
void	ft_free_vect(t_vec *vec, t_coord *o, t_coord *e);
void	ft_free_tvars(t_vars *xvar);
void	ft_exitprocss(int status, t_vars *xvar);

#endif