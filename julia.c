/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:57:30 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/16 14:22:49 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_julia(t_graph *graph)
{
	t_complex	z;
	int			x;
	int			y;
	int			iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = 0;
			z = pixel_to_complex(x, y, &graph->zoom);
			iter = get_rid_of(z, graph->c);
			put_pixel_to_image(graph, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
}

int	mouse_julia(int button, int x, int y, void *param)
{
	t_graph		*graph;
	t_complex	mouse;
	double		factor;

	graph = param;
	factor = set_zoom_factor(button);
	mouse = pixel_to_complex(x, y, &graph->zoom);
	graph->zoom.max_re = mouse.re + (graph->zoom.max_re - mouse.re) * factor;
	graph->zoom.min_re = mouse.re + (graph->zoom.min_re - mouse.re) * factor;
	graph->zoom.max_im = mouse.im + (graph->zoom.max_im - mouse.im) * factor;
	graph->zoom.min_im = mouse.im + (graph->zoom.min_im - mouse.im) * factor;
	draw_julia(graph);
	return (0);
}

int	key_julia(int keycode, t_graph *graph)
{
	if (keycode == ESC)
		clean_window(graph);
	else if (keycode == ARROW_RIGHT)
	{
		graph->zoom.max_re += 0.1;
		graph->zoom.min_re += 0.1;
	}
	else if (keycode == ARROW_LEFT)
	{
		graph->zoom.max_re -= 0.1;
		graph->zoom.min_re -= 0.1;
	}
	else if (keycode == ARROW_UP)
	{
		graph->zoom.max_im -= 0.1;
		graph->zoom.min_im -= 0.1;
	}
	else if (keycode == ARROW_DOWN)
	{
		graph->zoom.max_im += 0.1;
		graph->zoom.min_im += 0.1;
	}
	draw_julia(graph);
	return (0);
}
