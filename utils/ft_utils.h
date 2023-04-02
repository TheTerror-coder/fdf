/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 17:13:42 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

#include "../ft_fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_xbutton_destroy(t_vars *xvar);
int		ft_keyhook(int keycode, t_vars *xvar);
void	ft_freesplit(char **str);
t_vars	*ft_init_tvars();
void	ft_freezdata(double **arr2, int nline);
int		ft_lensplit(char **sstr);
t_bool	ft_checkextension(char	*name);
double	ft_percent(double n, double per);
t_vec	*ft_alloc_vect(unsigned int nmemb, unsigned int size);
void	ft_free_vect(t_vec *vec, t_coord *o, t_coord *e);
t_vec	**ft_alloclist_vec(unsigned int nmemb, unsigned int size);
void	ft_free_listvec(t_vec **list);
char	**ft_keepnum(char **data);
t_bool	ft_contain_num(char *str);
t_bool	ft_set_jx(t_vars *xvar);

#endif