/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:13:17 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/16 15:15:47 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_initial_zoom(t_graph *graph)
{
	graph->zoom.max_re = 2.0;
	graph->zoom.min_re = -2.0;
	graph->zoom.max_im = 2.0;
	graph->zoom.min_im = -2.0;
}

double	set_zoom_factor(int button)
{
	if (button == ZOOM_IN)
		return (0.9);
	else if (button == ZOOM_OUT)
		return (1.1);
	return (1.0);
}

static int	is_valid_number(const char *str)
{
	int	dot_count;
	int	sign_count;

	dot_count = 0;
	sign_count = 0;
	if (*str == '-')
	{
		sign_count++;
		str++;
	}
	while (*str)
	{
		if (*str == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	if (sign_count > 1)
		return (0);
	return (1);
}

void	set_julia(t_graph *g, char **argv)
{
	if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
	{
		write(1, "Invalid arguments!!\n", 20);
		exit(1);
	}
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "aserbest");
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->img_data = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->endian);
	set_initial_zoom(g);
	g->c.re = ft_atof(argv[2]);
	g->c.im = ft_atof(argv[3]);
	draw_julia(g);
	mlx_key_hook(g->win, key_julia, g);
	mlx_mouse_hook(g->win, mouse_julia, g);
}

void	set_mandelbrot(t_graph *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "aserbest");
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->img_data = mlx_get_data_addr(g->img, &g->bpp, &g->size_line, &g->endian);
	set_initial_zoom(g);
	draw_mandelbrot(g);
	mlx_key_hook(g->win, key_mandelbrot, g);
	mlx_mouse_hook(g->win, mouse_mandelbrot, g);
}
