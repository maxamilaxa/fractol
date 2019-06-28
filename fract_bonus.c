/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:42:22 by mkopiika          #+#    #+#             */
/*   Updated: 2019/06/28 18:42:25 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int partial_buffalo_set(t_calc c)
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
		c.new.re = fabs(((c.old.re * c.old.re) - (3 * c.old.im * c.old.im))
						* c.old.re) + c.cnst.re;
		c.new.im = ((3 * c.old.re * c.old.re) - (c.old.im * c.old.im))
				   * c.old.im + c.cnst.im;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}

int mandelbrot_double_set(t_calc c)
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
		c.new.re = ((c.old.re * c.old.re) - (3 * c.old.im * c.old.im))
				   * c.old.re + c.cnst.re;
		c.new.im = ((3 * c.old.re * c.old.re) - (c.old.im * c.old.im))
				   * c.old.im + c.cnst.im;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}

int mandelbrot_triple_set(t_calc c)
{
	double re_pow;
	double im_pow;

	c.i = 0;
	c.cnst.re = 1.5 * (c.x - W / 2) / (0.5 * c.zoom * W) + c.re_x;
	c.cnst.im = (c.y - H / 2) / (0.5 * c.zoom * H) + c.im_y;
	c.new.im = 0;
	c.new.re = 0;
	while(c.i < c.iter_max)
	{
		c.old.im = c.new.im;
		c.old.re = c.new.re;
		im_pow = c.old.im * c.old.im;
		re_pow = c.old.re * c.old.re;
		c.new.re = (re_pow * re_pow + im_pow * im_pow)
				   - (6 * re_pow * im_pow) + c.cnst.re;
		c.new.im = 4 * c.old.re * c.old.im * (re_pow - im_pow) + c.cnst.im;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}

int mandelbrot_quadruple_set(t_calc c)
{
	double re_pow;
	double im_pow;

	c.i = 0;
	c.cnst.re = 1.5 * (c.x - W / 2) / (0.5 * c.zoom * W) + c.re_x;
	c.cnst.im = (c.y - H / 2) / (0.5 * c.zoom * H) + c.im_y;
	c.new.im = 0;
	c.new.re = 0;
	while(c.i < c.iter_max)
	{
		c.old.im = c.new.im;
		c.old.re = c.new.re;
		im_pow = c.old.im * c.old.im;
		re_pow = c.old.re * c.old.re;
		c.new.re = c.old.re * (re_pow * re_pow - 10 * re_pow * im_pow
					+ 5 * im_pow * im_pow) + c.cnst.re;
		c.new.im = c.old.im * (5 * re_pow * re_pow - 10 * re_pow * im_pow
					+ im_pow * im_pow) + c.cnst.im;
		if((c.new.re * c.new.re + c.new.im * c.new.im) > 4)
			break ;
		c.i++;
	}
	return (c.i);
}
