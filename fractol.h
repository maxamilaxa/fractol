/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:26:13 by mkopiika          #+#    #+#             */
/*   Updated: 2019/05/07 13:26:17 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//////////////////////////////
# include <stdio.h>
/////////////////////////////
# include "libft/libft.h"
# include <math.h>
# include "mlx.h"

#include <pthread.h>

# define H 800
# define W 1200
# define THREADS 4

# define MANDEL_SET 1
# define JULIA_SET  2
# define HEART_MANDEL_SET 3
# define MANDEL_DBL_SET 4
# define MANDEL_TRPL_SET 5
# define MANDEL_QDRPL_SET 6
# define PRTIAL_BUFFL_SET 7
# define BURNING_SHIP_SET 8

# define ESC_KEY		53
# define UP_WHEEL		5
# define DOWN_WHEEL		4

# define IMG_D data->img.img_d
# define IMG_P data->img.img_p
# define M_PTR data->mlx_p
# define W_PTR data->win_p
# define PARAM data->param

typedef struct 		s_colorize
{
	unsigned  char	red;
	unsigned  char	green;
	unsigned  char	blue;
}					t_colorize;

typedef struct 		s_re_im
{
	double			re;
	double			im;
}					t_re_im;

typedef struct 		s_calc
{
	double			zoom;
	double			re_x;			//// moveX
	double			im_y;			//// moveY
	int				iter_max;
	int				y;
	int				x;
	int				i;
	unsigned char	alpha;
	t_re_im			cnst;
	t_re_im			new;
	t_re_im			old;
}					t_calc;

typedef struct 		s_image
{
	void			*img_p;
	int 			*img_d;
	int 			img_bpp;
	int 			img_edn;
	int 			img_sz;
}					t_image;

typedef struct		s_thred
{
	int 			strt_t;
	int 			end_t;
	int 			init_frt;
	int 			*img_d;
	t_calc			p;
}					t_thred;

typedef struct		s_data
{
	void			*mlx_p;
	void			*win_p;
	int 			init_frt;
	t_image			img;
	t_calc			deflt;				///standart set//
	t_calc			param;				///variabls for keyboard//
}					t_data;

void				fract_error(int	fail);
int					fract_get_set(int frct, t_calc p);
void 				fract_print(t_data *data);
int 				partial_buffalo_set(t_calc c);
int 				mandelbrot_double_set(t_calc c);
int 				mandelbrot_triple_set(t_calc c);
int 				mandelbrot_quadruple_set(t_calc c);
void				fract_event_hook(t_data *data);

#endif