/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:18 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/19 14:51:01 by lbohm            ###   ########.fr       */
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

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	char			*color;
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
	int	x_max;
	int	y_max;
	int	dots;
}				t_size;

typedef struct s_data
{
	t_map			*map;
	t_map			*default_map;
	t_map			*dots;
	t_size			size;
	mlx_t			*window;
	mlx_image_t		*img_map;
	mlx_image_t		*img_menu;
	int				zoom;
	int				angle_z;
	int				angle_y;
	int				angle_x;
	int				mouse_x;
	int				mouse_y;
	int				dpi;
	mlx_image_t		*str[9];
}				t_data;

typedef struct s_pos
{
	int		dx;
	int		dy;
	int		startx;
	int		starty;
	char	*color1;
	char	*color2;
	float	fraction;
}				t_pos;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	color;
}				t_color;

// fdf

int		main(int argc, char **argv);
void	parsing(int argc, char **argv, t_data *data);
void	error(char *msg, t_data *data);
int		count_rows(char *file);
int		check_input(char **split);
void	free_dp(char **arr);

// draw_line

void	draw_loop(t_data data);
void	draw_dot(t_map *dot, t_data data);
void	draw_pixel(int x, int y, t_pos info, t_data data);
int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a);
int		htoi(char	*hexa);
void	reset_check(t_data *data);

// line_algo

void	draw_line(t_map dot1, t_map dot2, t_data data);
void	slope_s(t_map dot1, t_map dot2, t_pos info, t_data data);
void	slope_b(t_map dot1, t_map dot2, t_pos info, t_data data);

// parsing

void	init_data(t_data *data);
void	fill_map(char **argv, t_data *data);
void	add_to_map(t_map *dot, t_map **map, t_size size);
void	fill_dot(t_map	*dot, char *z, t_size size, int i);
void	count_size(char *file, t_size *size);
int		count_elements(char **split);

// rotate

void	add_zoom(t_data *data);
void	rotate(t_data *data);
void	rotate_x(t_map *dot, int angle, t_data data);
void	rotate_y(t_map *dot, int angle, t_data data);
void	rotate_z(t_map *dot, int angle, t_data data);


// key_actions

void	controll(void *param);
void	key(mlx_key_data_t code, void *param);
void	scroll(double xdelta, double ydelta, void *param);
void	cursor(t_data *data);

// menu

void	draw_menu(t_data *data);
void	delete_img(t_data *data);

// test

void	cpy_map(t_data *data);

// error msg

# define ERROR_0 "Wrong nbr of Arrguments!\n"
# define ERROR_1 "Open failed!\n"
# define ERROR_2 "Map has invalide char!\n"
# define ERROR_3 "Close failed!\n"
# define ERROR_4 "Allocation failed!\n"
# define ERROR_5 "File ends not with .fdf\n"
# define ERROR_6 "Conversion from hexa to int failed\n"

#endif