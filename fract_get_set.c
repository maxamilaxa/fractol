/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_get_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:42:36 by mkopiika          #+#    #+#             */
/*   Updated: 2019/06/28 18:42:38 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int heart_mandelbrot_set(t_calc c)
{
	c.i = 0;
	c.cnst.re = 1.5 * (c.x - W / 2) / (0.5 * c.zoom * W) + c.re_x;
	c.cnst.im = (c.y - H / 2) / (0.5 * c.zoom * H) + c.im_y;
	c.new.im = 0;
	c.new.re = 0;
	while(c.i < c.iter_max)
	{
		c.old.im = c.new.im;
		c.old.re = c.new.re;
		c.new.im = 2 * fabs(c.old.re) * c.old.im + c.cnst.im;
		c.new.re = c.old.re * c.old.re - c.old.im * c.old.im + c.cnst.re;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}

static int mandelbrot_set(t_calc c)
{
	c.i = 0;
	c.cnst.im = (c.y - H / 2) / (0.5 * c.zoom * H) + c.im_y;
	c.cnst.re = 1.5 * (c.x - W / 2) / (0.5 * c.zoom * W) + c.re_x;
	c.new.im = 0;
	c.new.re = 0;
	while(c.i < c.iter_max)
	{
		c.old.re = c.new.re;
		c.old.im = c.new.im;
		c.new.im = 2 * c.old.re * c.old.im + c.cnst.im;
		c.new.re = c.old.re * c.old.re - c.old.im * c.old.im + c.cnst.re;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}


static int burning_ship_set(t_calc c)
{
	c.i = 0;
	c.cnst.im = (c.y - H / 2) / (0.5 * c.zoom * H) + c.im_y;
	c.cnst.re = 1.5 * (c.x - W / 2) / (0.5 * c.zoom * W) + c.re_x;
	c.new.im = 0;
	c.new.re = 0;
	while(c.i < c.iter_max)
	{
		c.old.re = c.new.re;
		c.old.im = c.new.im;
		c.new.im = 2 * fabs(c.old.re * c.old.im) + c.cnst.im;
		c.new.re = c.old.re * c.old.re - c.old.im * c.old.im + c.cnst.re;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}

static int julia_set(t_calc	c)
{
	c.i = 0;
	c.new.im = (c.y - H / 2) / (0.5 * c.zoom * H) + c.im_y;
	c.new.re = 1.5 * (c.x - W / 2) / (0.5 * c.zoom * W) + c.re_x;
	while(c.i < c.iter_max)
	{
		c.old.re = c.new.re;
		c.old.im = c.new.im;
		c.new.im = 2 * c.old.re * c.old.im + c.cnst.im;
		c.new.re = c.old.re * c.old.re - c.old.im * c.old.im + c.cnst.re;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}

int	fract_get_set(int fractol, t_calc p)
{
	p.i = 0;
	if (fractol == JULIA_SET)
		p.i = julia_set(p);
	else if (fractol == MANDEL_SET)
		p.i = mandelbrot_set(p);
	else if (fractol == HEART_MANDEL_SET)
		p.i = heart_mandelbrot_set(p);
	else if (fractol == MANDEL_DBL_SET)
		p.i = mandelbrot_double_set(p);
	else if (fractol == MANDEL_TRPL_SET)
		p.i = mandelbrot_triple_set(p);
	else if (fractol == MANDEL_QDRPL_SET)
		p.i = mandelbrot_quadruple_set(p);
	else if (fractol == PRTIAL_BUFFL_SET)
		p.i = partial_buffalo_set(p);
	else if (fractol == BURNING_SHIP_SET)
		p.i = burning_ship_set(p);
	return (p.i);
}
