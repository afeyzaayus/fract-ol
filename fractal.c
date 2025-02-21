/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:50:18 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 15:35:42 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	pixel_to_complex(int x, int y, t_zoom *zoom)
{
	t_complex	z;

	z.re = (zoom->max_re - zoom->min_re) * x / (double)WIDTH + zoom->min_re;
	z.im = (zoom->max_im - zoom->min_im) * y / (double)HEIGHT + zoom->min_im;
	return (z);
}

int	get_rid_of(t_complex z, t_complex c)
{
	int		iter;
	double	temp;

	iter = 0;
	while (z.re * z.re + z.im * z.im < BAIL_OUT && iter < MAX_ITER)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	return (iter);
}
