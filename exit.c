/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:52 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/16 12:49:53 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	clean_window(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->win);
	exit(0);
	return (0);
}

int	quit(void *param)
{
	t_graph	*ptr;

	ptr = param;
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
}
