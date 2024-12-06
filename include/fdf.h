/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:18 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/06 10:22:52 by lbohm            ###   ########.fr       */
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

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
}				t_vec;

typedef struct s_ortho
{
	float	l;
	float	r;
	float	b;
	float	t;
	float	n;
	float	f;
}				t_ortho;

typedef struct s_map
{
	t_vec			coords;
	t_vec			color;
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
	int		ratio;
	int		x_max;
	int		y_max;
	int		dots;
	int		scale;
	t_vec	center;
	int		zoom;
	float	angle_z;
	float	angle_y;
	float	angle_x;
	int		dpi;
	float	z_zoom;
	bool	projection;
	bool	moved;
}				t_size;

typedef struct s_data
{
	t_map			*map;
	t_map			*default_map;
	t_size			*size;
	t_ortho			ortho;
	mlx_t			*window;
	mlx_image_t		*img_map;
	mlx_image_t		*menu[19];
}				t_data;

typedef struct s_pos
{
	t_vec	c1;
	t_vec	c2;
	int		dx;
	int		dy;
	int		startx;
	int		starty;
}				t_pos;

// draw_line

void	draw_loop(t_data *data);
void	draw_dot(t_map *dot, t_data *data);
void	draw_pixel(int x, int y, t_pos info, t_data *data);
int		get_color(int r, int g, int b, int a);
int		ft_htoi(char *hexa);

// draw_map

void	draw_map(t_data *data);
void	draw_map_changed(t_data *data);
void	add_zoom(t_data *data);
void	reset_check(t_data *data);

// fdf

int		main(int argc, char **argv);
void	error(char *msg, t_data *data);
void	free_dp(char **arr);
void	free_all(t_data *data);

// key_actions_utils

void	wasdqe(mlx_key_data_t code, t_data *data);
void	reset(mlx_key_data_t code, t_data *data);
void	set_dpi(mlx_key_data_t code, t_data *data);
void	z_altitude(mlx_key_data_t code, t_data *data);

// key_actions

void	controll(void *param);
void	key(mlx_key_data_t code, void *param);
void	scroll(double xdelta, double ydelta, void *param);
void	cursor(t_data *data);
void	resize(int width, int height, void *param);

// line_algo

void	draw_line(t_map dot1, t_map dot2, t_data *data);
void	slope_s(t_map dot1, t_map dot2, t_pos info, t_data *data);
void	slope_b(t_map dot1, t_map dot2, t_pos info, t_data *data);

// menu_utils

void	change_mouse_img(t_data *data);
void	change_projection_img(t_data *data);
void	change_center_img(t_data *data);

// menu

void	draw_menu(t_data *data);
void	draw_menu_2(t_data *data);
void	delete_img(t_data *data);

// parsing_utils_2

void	add_to_map(t_map *dot, t_map **map, t_size *size);
void	add_to_map_2(t_map *dot, t_map *start, t_map *tmp);
void	add_to_map_3(t_map *dot, t_map *start, t_map *tmp);
void	check_value(char *value, t_data *data);
char	*clean_line(char *line);

// parsing_utils

t_data	*init_data(void);
void	init_size(t_data *data);
void	fill_dot(t_map	*dot, char *z, t_size *size, int i);
void	pars_color(t_map *dot, char *z);
void	pars_color_2(t_map *dot, char *color);

// parsing

void	parsing(int argc, char **argv, t_data *data);
void	fill_map(char **argv, t_data *data);
void	fill_dots(t_data *data, int fd);
void	count_size(char *file, t_data *data);
int		count_elements(char **split, t_data *data);

// rotate

void	rotate(t_data *data);
t_vec	r_vec(float m[3][3], t_vec v);
void	translate_to_center(t_data *data);

// rotate_utils

void	get_full_r(float result[3][3], float x, float y, float z);
void	rotate_x(float m[3][3], float angle);
void	rotate_y(float m[3][3], float angle);
void	rotate_z(float m[3][3], float angle);
void	multi_m(float result[3][3], float m1[3][3], float m2[3][3]);

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
# define ERROR_8 "Img creation failed\n"
# define ERROR_9 "Empty file\n"

#endif