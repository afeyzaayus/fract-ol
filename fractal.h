/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:52:47 by aserbest          #+#    #+#             */
/*   Updated: 2025/02/16 15:16:36 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <math.h>

# define ESC 65307
# define HEIGHT 500
# define WIDTH 500
# define BAIL_OUT 4
# define MAX_ITER 75
# define PI 3.14
# define ZOOM_IN 4  
# define ZOOM_OUT 5  
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

typedef struct s_zoom
{
	double	max_re;
	double	min_re;
	double	max_im;
	double	min_im;
}	t_zoom;

typedef struct s_complex
{
	long double	re;
	long double	im;
}	t_complex;

typedef struct s_graph
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	t_zoom		zoom;
	t_complex	c;
}	t_graph;

int			clean_window(t_graph *graph);
int			quit(void *param);
void		set_initial_zoom(t_graph *graph);
t_complex	pixel_to_complex(int x, int y, t_zoom *zoom);
void		put_pixel_to_image(t_graph *graph, int x, int y, int color);
int			get_rid_of(t_complex z, t_complex c);
int			get_color(int iter);
double		set_zoom_factor(int button);
double		ft_atof(const char *str);
void		draw_julia(t_graph *graph);
void		draw_mandelbrot(t_graph *graph);
void		set_julia(t_graph *g, char **argv);
void		set_mandelbrot(t_graph *g);
int			mouse_julia(int button, int x, int y, void *param);
int			mouse_mandelbrot(int button, int x, int y, void *param);
int			key_mandelbrot(int keycode, t_graph *graph);
int			key_julia(int keycode, t_graph *graph);

#endif
