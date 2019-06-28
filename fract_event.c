/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:05:46 by mkopiika          #+#    #+#             */
/*   Updated: 2019/06/28 19:05:51 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fract_close(void *param)
{
	(void)param;
	system("leaks -q fractol");
	exit(0);
	return (0);
}

int fract_press(int b, t_data *data)
{
	if (b == ESC_KEY)
		fract_close(data);
	return (0);
}

int fract_mouse_press(int butt, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)butt;
	t_re_im		mouse;

	mouse.re = 1.5 * (x - W / 2) / (0.5 * PARAM.zoom * W) + PARAM.re_x;
	mouse.im = (y - H / 2) / (0.5 * PARAM.zoom * H) + PARAM.im_y;
	PARAM.re_x += mouse.re - PARAM.re_x;
	PARAM.im_y += mouse.im - PARAM.im_y;

	if (butt == UP_WHEEL)
		data->param.zoom *= 2;
	if (butt == DOWN_WHEEL)
		data->param.zoom *= 0.5;

	mouse.re = 1.5 * (x - W / 2) / (0.5 * PARAM.zoom * W) + PARAM.re_x;
	mouse.im = (y - H / 2) / (0.5 * PARAM.zoom * H) + PARAM.im_y;
	PARAM.re_x -= mouse.re - PARAM.re_x;
	PARAM.im_y -= mouse.im - PARAM.im_y;
	printf("%f - zoom\n", data->param.zoom);
	fract_print(data);
	return (0);
}

void fract_event_hook(t_data *data)
{
	printf("Hello\n");
	mlx_hook(W_PTR, 17, 0, fract_close, (void *)data);		/// for x press
	mlx_hook(W_PTR, 2, 0, fract_press, (void *)data);		/// for press button
	mlx_hook(W_PTR, 4, 0, fract_mouse_press, (void *)data);		/// for wheel mouse
}
