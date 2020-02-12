/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:07:18 by llahti            #+#    #+#             */
/*   Updated: 2020/02/06 09:26:45 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/srcs/libft/libft.h"
# include "mlx.h"
# define MAX_HEIGHT 1000
# define WIN_WIDTH 1400
# define WIN_HEIGHT 800
# define IMG_WIDTH 1000
# define IMG_HEIGHT 800
# define DEFAULT_RED 255
# define DEFAULT_GREEN 255
# define DEFAULT_BLUE 255
# define DEFAULT_PROJECTION 3
# define THEMES 4
# define TEXT_COLOR 0xE9E9E9
# define WARNING_COLOR 0xFFFFFF

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			dx;
	int			dy;
	int			r;
	int			g;
	int			b;
	int			tr;
	int			tg;
	int			tb;
}				t_point;

typedef struct	s_grid
{
	t_point		**arr;
	t_point		*center;
	int			width;
	int			height;
	int			x0;
	int			y0;
	int			multiply;
	int			multiply_z;
	int			max_z;
	int			min_z;
	int			projection;
	int			colortheme;
	int			reverse_arrows;
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

int				ft_bresenham(t_line *line, t_point *next);
int				ft_x_is_longer(t_line *l);

void			ft_get_theme_colors(t_grid *grid, t_point *point);

void			ft_dot_to_image(t_point *dot, t_ptrs *ptrs, int single);
void			ft_get_dot_color(t_point *next, t_line *l, int theme);

int				ft_draw(t_grid *grid);
int				ft_draw_image(t_ptrs *ptrs);
void			ft_get_zero_point(t_grid *grid);

void			ft_get_draw_pts_flat(t_grid *grid, t_point *point);
void			ft_get_zero_flat(t_grid *grid);

int				ft_get_color(t_point *point, char *input, int k, int theme);
void			ft_get_default_color(t_point *point);

void			ft_get_draw_pts_isometric(t_grid *grid, t_point *point);
void			ft_get_zero_isometric(t_grid *grid);

int				ft_deal_key(int key, void *ptrs);

int				ft_move_down(t_ptrs *ptrs);
int				ft_move_up(t_ptrs *ptrs);
int				ft_move_left(t_ptrs *ptrs);
int				ft_move_right(t_ptrs *ptrs);
int				ft_reset_to_middle(t_ptrs *ptrs);

int				ft_reverse_arrows(t_ptrs *ptrs);
int				ft_zoom_in(t_ptrs *ptrs);
int				ft_zoom_out(t_ptrs *ptrs);
int				ft_switch_projection(t_ptrs *ptrs);
int				ft_switch_color(t_ptrs *ptrs);

void			ft_to_point_array(t_grid *grid, char **lines);

void			ft_make_grid(t_grid **grid, char **lines, int height);

void			ft_make_image(t_ptrs *ptrs, t_grid *grid);

int				ft_abs(int nb);
int				ft_next_fibonacci(int nb);
int				ft_prev_fibonacci(int nb);

int				ft_deal_mouse(int button, int x, int y, void *ptrs);
void			ft_draw_warning(t_ptrs *ptrs, char *str);

void			ft_get_draw_pts_origami(t_grid *grid, t_point *point);
void			ft_get_zero_origami(t_grid *grid);

void			ft_get_draw_pts_paralinear(t_grid *grid, t_point *point);
void			ft_get_zero_paralinear(t_grid *grid);

char			**ft_theme_1(void);
char			**ft_theme_2(void);
char			**ft_theme_3(void);
char			**ft_theme_4(void);

int				ft_error(char *str, int nb);
int				ft_usage();

#endif
