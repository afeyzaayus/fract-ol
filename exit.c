/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:52 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/20 17:48:01 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	clean_window(t_graph *graph)
{
	if (graph->img)
		mlx_destroy_image(graph->mlx, graph->img);
	if (graph->win)
		mlx_destroy_window(graph->mlx, graph->win);
	if (graph->mlx)
	{
		mlx_destroy_display(graph->mlx);
		free(graph->mlx);
	}
	exit(0);
	return (0);
}
