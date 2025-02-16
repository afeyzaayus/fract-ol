/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:05:52 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/16 15:18:22 by aserbest         ###   ########.fr       */
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

static int	return_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

static void	set_variables(double *res, double *fraction, double *div, int *sign)
{
	*res = 0.0;
	*fraction = 0.0;
	*div = 1.0;
	*sign = 1;
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	double	divisor;
	int		sign;

	set_variables(&result, &fraction, &divisor, &sign);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = return_sign(*str++);
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction = fraction * 10.0 + (*str++ - '0');
			divisor *= 10.0;
		}
	}
	return (sign * (result + fraction / divisor));
}

int	main(int argc, char **argv)
{
	t_graph	graph;

	if (argc < 2 || argc > 4 || argc == 3)
	{
		write(1, "Invalid arguments!!\n", 20);
		return (1);
	}
	if (argc == 4 && ft_strcmp(argv[1], "Julia") == 0)
		set_julia(&graph, argv);
	else if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
		set_mandelbrot(&graph);
	mlx_hook(graph.win, DestroyNotify, 0, quit, (void *)&graph);
	mlx_loop(graph.mlx);
	return (0);
}
