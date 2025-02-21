/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:45:09 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 17:09:00 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	put_pixel_to_image(t_graph *graph, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = ((graph->bpp / 8) * x) + ((graph->size_line * y));
		graph->img_data[i] = (color >> 16) & 0xFF;
		graph->img_data[i + 1] = (color >> 8) & 0xFF;
		graph->img_data[i + 2] = color & 0xFF;
	}
}

int	get_color(int iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iter / MAX_ITER;
	red = (int)((cos(t * PI) * 0.5 + 0.5) * 255);
	green = (int)((cos(t * PI) * 0.5 + 0.5) * 255);
	blue = (int)((sin(t * PI) * 0.5 + 0.5) * 255);
	return ((red << 16) | (green << 8) | blue);
}
