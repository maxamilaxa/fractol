/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:27:16 by mkopiika          #+#    #+#             */
/*   Updated: 2019/05/07 13:27:18 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void init_data(t_data *data)
{
	if (!(M_PTR = mlx_init()))
		fract_error(21);
	if (!(W_PTR = mlx_new_window(M_PTR, W, H, "fractol")))
		fract_error(21);
	if (!(IMG_P = mlx_new_image(M_PTR, W, H)))
		fract_error(21);
	IMG_D = (int*)mlx_get_data_addr(IMG_P,
			&data->img.img_bpp, &data->img.img_sz, &data->img.img_edn);
}

static void init_param(t_data *d)
{
	d->deflt.iter_max = 200;
	d->deflt.im_y = 0;
	d->deflt.re_x = 0;
	d->deflt.zoom = 0.73;
	d->deflt.alpha = 0;
	if (d->init_frt == JULIA_SET)
	{
		d->deflt.cnst.re = -0.7;
		d->deflt.cnst.im = 0.27015;
	}
	if (d->init_frt == MANDEL_SET)
	{
		;
	}
	d->param = d->deflt;
}

int			main(void/*int ac, char **av*/)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		fract_error(20);
	init_data(data);

	data->init_frt = MANDEL_SET;
//	data->init_frt = JULIA_SET;
//	data->init_frt = HEART_MANDEL_SET;
//	data->init_frt = MANDEL_DBL_SET;
//	data->init_frt = MANDEL_TRPL_SET;
//	data->init_frt = PRTIAL_BUFFL_SET;
//	data->init_frt = MANDEL_QDRPL_SET;
//	data->init_frt = BURNING_SHIP_SET;

	init_param(data);
	fract_print(data);

	fract_event_hook(data);
	printf("HELLLO\n");
	mlx_loop(M_PTR);
	system("leaks -q fractol");
	system("leaks -q fractol");
	return (0);

}