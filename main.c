/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:05:52 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 17:58:29 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

int	main(int argc, char **argv)
{
	t_graph	graph;

	if (argc < 2 || argc > 4 || argc == 3)
	{
		write(1, "Invalid arguments!!\n", 20);
		return (1);
	}
	ft_memset(&graph, 0, sizeof(graph));
	if (argc == 4 && ft_strcmp(argv[1], "Julia") == 0)
		set_julia(&graph, argv);
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
		set_mandelbrot(&graph);
	else if (argc == 2 && ft_strcmp(argv[1], "Julia") == 0)
		return (write(1, "Invalid arguments!!\n", 20));
	mlx_hook(graph.win, DestroyNotify, 0, clean_window, (void *)&graph);
	mlx_loop(graph.mlx);
	return (0);
}
