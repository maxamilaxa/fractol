/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:31:58 by mkopiika          #+#    #+#             */
/*   Updated: 2019/05/07 14:32:00 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_error(int	fail)
{
	if (fail == 20)
	{
		ft_putendl("Error: malloc failed");
		exit(20);					//// for malloc
	}
	else if (fail == 21)
	{
		ft_putendl("Error: pointer from mlx_func is NULL");
		exit(21);					//// win no open
	}

}