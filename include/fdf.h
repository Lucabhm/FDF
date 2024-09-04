/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:18 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 22:12:51 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/ft_libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/ft_get_next_line/get_next_line.h"
# include "../lib/mlx/include/MLX42/MLX42.h"

// struct

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct s_ortho
{
	int	l;
	int	r;
	int	b;
	int	t;
	int	n;
	int	f;
}				t_ortho;

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	t_color			color;
	struct s_map	*up;
	struct s_map	*down;
	struct s_map	*left;
	struct s_map	*right;
	bool			draw_up;
	bool			draw_down;
	bool			draw_left;
	bool			draw_right;
}				t_map;

typedef struct s_size
{
	int		x_max;
	int		y_max;
	int		dots;
	int		width;
	int		height;
	t_color	center;
}				t_size;

typedef struct s_data
{
	t_map			*map;
	t_map			*default_map;
	t_size			size;
	t_ortho			ortho;
	mlx_t			*window;
	mlx_image_t		*img_map;
	mlx_image_t		*img_menu;
	mlx_image_t		*menu[14];
	int				zoom;
	int				angle_z;
	int				angle_y;
	int				angle_x;
	int				dpi;
	bool			projection;
	bool			moved;
}				t_data;

typedef struct s_pos
{
	t_color	c1;
	t_color	c2;
	int		dx;
	int		dy;
	int		startx;
	int		starty;
}				t_pos;

// fdf

int		main(int argc, char **argv);
void	error(char *msg, t_data *data);
void	free_dp(char **arr);

// draw_line

void	draw_loop(t_data *data);
void	draw_dot(t_map *dot, t_data *data);
void	draw_pixel(int x, int y, t_pos info, t_data *data);
int		get_color(int r, int g, int b, int a);
int		htoi(char	*hexa);
void	reset_check(t_data *data);

// line_algo

void	draw_line(t_map dot1, t_map dot2, t_data *data);
void	slope_s(t_map dot1, t_map dot2, t_pos info, t_data *data);
void	slope_b(t_map dot1, t_map dot2, t_pos info, t_data *data);

// parsing

void	parsing(int argc, char **argv, t_data *data);
void	fill_map(char **argv, t_data *data);
void	count_size(char *file, t_data *data);
int		count_elements(char **split, t_data *data);
void	check_value(char *value, t_data *data);

// parsing2

t_data	*init_data(void);
void	fill_dot(t_map	*dot, char *z, t_size size, int i);
void	add_to_map(t_map *dot, t_map **map, t_size size);
void	pars_color(t_map *dot, char *z);
void	pars_color_2(t_map *dot, char *color);

// rotate

void	rotate(t_data *data);
void	rotate_x(t_map *dot, t_data *data);
void	rotate_y(t_map *dot, t_data *data);
void	rotate_z(t_map *dot, t_data *data);
int		max(t_data *data, char coord);
int		min(t_data *data, char coord);
void	translate_to_center(t_data *data);


// key_actions

void	controll(void *param);
void	key(mlx_key_data_t code, void *param);
void	scroll(double xdelta, double ydelta, void *param);
void	cursor(t_data *data);
void	resize(int width, int height, void *param);
void	wasdqe(mlx_key_data_t code, t_data *data);

// menu

void	draw_menu(t_data *data);
void	delete_img(t_data *data);
void	change_mouse_img(t_data *data);
void	change_projection_img(t_data *data);

// test

void	free_all(t_data *data);

// draw_map

void	draw_map(t_data *data);
void	draw_map_changed(t_data *data);
void	add_zoom(t_data *data);
void	add_zoom_test(t_data *data);

// rotate_ortho

void	rotate_ortho(t_data *data);
void	init_ortho(t_data *data);
void	draw_map_ortho(t_data *data);
void	key_ortho(mlx_key_data_t code, t_data *data);

// error msg

# define ERROR_0 "Wrong nbr of Arrguments!\n"
# define ERROR_1 "Open failed!\n"
# define ERROR_2 "Map has invalide char!\n"
# define ERROR_3 "Close failed!\n"
# define ERROR_4 "Allocation failed!\n"
# define ERROR_5 "File ends not with .fdf\n"
# define ERROR_6 "Conversion from hexa to int failed\n"
# define ERROR_7 "Wrong Value inside map\n"

#endif