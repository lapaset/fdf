/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:07:18 by llahti            #+#    #+#             */
/*   Updated: 2020/02/03 17:30:01 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
//change this to libft header!
# include "../libft/srcs/ft_printf/ft_printf.h"
# include "mlx.h"

# define MAX_SIZE 1000
# define WIN_WIDTH 2000
# define WIN_HEIGHT 1000
# define IMG_WIDTH 1600
# define IMG_HEIGHT 1000
# define DEFAULT_RED 255
# define DEFAULT_GREEN 255
# define DEFAULT_BLUE 255
# define DEFAULT_PROJECTION 3

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			dx;
	int			dy;
	int			r;
	int			b;
	int			g;
}				t_point;

typedef struct	s_grid
{
	t_point		**arr;
	int			arr_width;
	int			arr_height;
	int			multiply;
	int			multiply_z;
	int			max_z;
	int			min_z;
	int			projection;
	int			x0;
	int			y0;
	int			reverse_arrows;
	int			center_moved;
	t_point		*center;
}				t_grid;

typedef struct	s_ptrs
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_ptr;
	t_grid		*grid;
}				t_ptrs;

typedef struct	s_line
{
	t_point		*start;
	t_point		*end;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_line;

int				ft_count_width(char *line);
void			ft_print_arr(t_point **arr, int height, int width);
void			ft_to_point_array(t_grid *grid, char **lines);

int				ft_abs(int nb);
int				ft_next_fibonacci(int nb);
int				ft_prev_fibonacci(int nb);

void			ft_print_line(t_point *start, t_point *end, t_ptrs *ptrs);
void			ft_print_dots(t_point *point, t_ptrs *ptrs);
void			ft_print_grid(t_grid *grid, t_ptrs *ptrs);

void			ft_make_grid(t_grid **grid, char **lines, int height);

void			ft_make_image(t_ptrs *ptrs, t_grid *grid);
void			ft_dot_to_image(t_point *dot, t_ptrs *ptrs);

int				ft_bresenham(t_line *line, t_point *next);

void			ft_make_line(t_point *start, t_point *end, t_line *l);

int				ft_error(char *str, int nb);
int				ft_usage();

int				ft_get_color(t_point *point, char *input, int k);
void			ft_get_default_color(t_point *point);

int				ft_x_is_longer(t_line *l);

void			ft_get_dot_color(t_point *next, t_line *l);
void			ft_dot_to_image(t_point *dot, t_ptrs *ptrs);

int				ft_draw(t_grid *grid);
int				ft_draw_image(t_ptrs *ptrs);

void			ft_get_zero_point(t_grid *grid);

void			ft_iterate_arr(t_grid *grid, void (f)(t_point*));

//projections:
void			ft_get_draw_pts_isometric(t_grid *grid);
void			ft_get_zero_isometric(t_grid *grid);

void			ft_get_draw_pts_paralinear(t_grid *grid);
void			ft_get_zero_paralinear(t_grid *grid);

void			ft_get_draw_pts_origami(t_grid *grid);
void			ft_get_zero_origami(t_grid *grid);

void			ft_get_draw_pts_flat(t_grid *grid);
void			ft_get_zero_flat(t_grid *grid);

//events:
int				ft_deal_key(int key, void *ptrs);

void			ft_move_down(t_ptrs *ptrs);
void			ft_move_up(t_ptrs *ptrs);
void			ft_move_left(t_ptrs *ptrs);
void			ft_move_right(t_ptrs *ptrs);
void			ft_reverse_arrows(t_ptrs *ptrs);

void			ft_reset_to_middle(t_ptrs *ptrs);
void			ft_close(t_ptrs *ptrs);
void			ft_zoom_in(t_ptrs *ptrs);
void			ft_zoom_out(t_ptrs *ptrs);
void			ft_switch_projection(t_ptrs *ptrs);

int				ft_deal_mouse(int button, int x, int y, void *ptrs);

void			ft_color_theme_1(t_point *next, t_line *l, int max_z, int min_z);

int				ft_get_i(t_point *next, t_line *l);
int				ft_get_len(t_line *l);

#endif
