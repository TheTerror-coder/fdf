/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 19:00:30 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "ft_preprocss.h"
# include "mlx_linux/mlx.h"
# include<unistd.h>
# include<math.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>

//enlever stdio
#include<stdio.h>

# include "./include/libft/libft.h"
# include "./include/get_next_line/get_next_line.h"
# include "./draw_tools/ft_draw_tools.h"
# include "./utils/ft_utils.h"
# include "./data_tools/ft_data_tools.h"
# include "./events_tools/ft_events_tools.h"

t_bool	ft_fdf_op(t_vars *xvar);
#endif
