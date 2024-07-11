/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:18 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/11 15:50:28 by lbohm            ###   ########.fr       */
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
	t_map			*dots;
	t_size			size;
	mlx_t			*window;
	mlx_image_t		*img_map;
	mlx_image_t		*img_menu;
}				t_data;

typedef struct s_pos
{
	float		dx;
	float		dy;
	float	slope;
}				t_pos;

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
// void	first_step(int x, int y, int x_2, int y_2, t_data data);
// void	slope_bigger(t_pos value, t_data data);
// void	slope_smaller(t_pos value, t_data data);
void	draw_pixel(int x, int y, t_data data);
int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a);

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
void	rotate_x(t_map *dot);
void	rotate_y(t_map *dot);
void	rotate_z(t_map *dot);

// error msg

# define ERROR_0 "Wrong nbr of Arrguments!\n"
# define ERROR_1 "Open failed!\n"
# define ERROR_2 "Map has invalide char!\n"
# define ERROR_3 "Close failed!\n"
# define ERROR_4 "Allocation failed!\n"
# define ERROR_5 "File ends not with .fdf\n"

#endif