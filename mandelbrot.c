/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:05:12 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/28 15:37:51 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_mandelbrot(t_graph *graph)
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
			z.re = 0;
			z.im = 0;
			graph->c.re = (graph->zoom.max_re - graph->zoom.min_re) * x
				/ (double)WIDTH + graph->zoom.min_re;
			graph->c.im = (graph->zoom.max_im - graph->zoom.min_im) * y
				/ (double)HEIGHT + graph->zoom.min_im;
			iter = get_rid_of(z, graph->c);
			put_pixel_to_image(graph, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
}

int	mouse_mandelbrot(int button, int x, int y, void *param)
{
	t_graph		*graph;
	t_complex	mouse;
	double		factor;

	graph = param;
	factor = set_zoom_factor(button);
	mouse.re = (graph->zoom.max_re - graph->zoom.min_re) * x
		/ (double)WIDTH + graph->zoom.min_re;
	mouse.im = (graph->zoom.max_im - graph->zoom.min_im) * y
		/ (double)HEIGHT + graph->zoom.min_im;
	graph->zoom.max_re = mouse.re + (graph->zoom.max_re - mouse.re) * factor;
	graph->zoom.min_re = mouse.re + (graph->zoom.min_re - mouse.re) * factor;
	graph->zoom.max_im = mouse.im + (graph->zoom.max_im - mouse.im) * factor;
	graph->zoom.min_im = mouse.im + (graph->zoom.min_im - mouse.im) * factor;
	draw_mandelbrot(graph);
	return (0);
}

int	key_mandelbrot(int keycode, t_graph *graph)
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
	draw_mandelbrot(graph);
	return (0);
}
