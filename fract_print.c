/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:42:48 by mkopiika          #+#    #+#             */
/*   Updated: 2019/06/28 18:42:50 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int colorize(t_calc p)
{
	t_colorize	color;
	int 		ret_clr;
	double 		c;

	if (p.i == p.iter_max)
		return (0);
	ret_clr = 0;
	c = (double)p.i / p.iter_max;
	color.red = (unsigned char) ((9) * (1 - c) * c * c * c * 255);
	color.green = (unsigned char) ((15) * (1 - c) * (1 - c) * c * c * 255);
	color.blue = (unsigned char) ((8.5) * (1 - c) * (1 - c) * (1 - c) * c * 255);

	ret_clr = (int)(color.blue) | (int)(color.green) << 8 | (int)(color.red) << 16 | (int)p.alpha << 24;
	return  (ret_clr);
}

void *thread_print(void *dat)
{
	t_thred *d;

	d = (t_thred*)dat;
	d->p.i = 0;
	d->p.y = d->strt_t;
	while (d->p.y < d->end_t)
	{
		d->p.x = 0;
		while (d->p.x < W)
		{
			d->p.i = fract_get_set(d->init_frt, d->p);
			d->img_d[d->p.y * W + d->p.x] = colorize(d->p);
			d->p.x++;
		}
		d->p.y++;
	}
	return (dat);
}

void fract_print(t_data *data)
{
	pthread_t 	pthd[THREADS];
	t_thred		dat[THREADS];
	int 		step_window;
	int 		i;

	i = 0;
	step_window = 0;
	dat[0].strt_t = 0;
	dat[0].img_d = IMG_D;			/// копіюємо вказівник для паралельної роботи тредів ////
	dat[0].end_t = 0;
	dat[0].init_frt = data->init_frt;
	dat[0].p = data->param;

	while (i < THREADS)
	{
		if (i > 0)
			dat[i] = dat[i - 1];			/// копія попередніх даних  ///
		dat[i].strt_t = step_window;
		step_window += H / THREADS;			//// крок, який допомагае визначити старт и енд для і  ///
		dat[i].end_t = step_window;
		pthread_create(&pthd[i], NULL, thread_print, &dat[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)					//// з'єдную треди ////
	{
		pthread_join(pthd[i], NULL);
		i++;
	}
	mlx_put_image_to_window(M_PTR, W_PTR, IMG_P, 0, 0);
}

//void fract_print(t_data *data)
//{
//	t_calc	p;
//
//	p = data->param;
//	p.i = 0;
//	p.y = 0;
//	while (p.y < H)
//	{
//		p.x = 0;
//		while (p.x < W)
//		{
//			p.i = fract_get_set(data->init_frt, p);
//			IMG_D[p.y * W + p.x] = colorize(p);
//			p.x++;
//		}
//		p.y++;
//	}
//	mlx_put_image_to_window(M_PTR, W_PTR, IMG_P, 0, 0);
//}
