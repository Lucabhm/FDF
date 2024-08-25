/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:18 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/23 17:59:25 by lucabohn         ###   ########.fr       */
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
	int	x_max;
	int	y_max;
	int	dots;
	int	width;
	int	height;
}				t_size;

typedef struct s_data
{
	t_map			*map;
	t_map			*default_map;
	t_size			size;
	mlx_t			*window;
	mlx_image_t		*img_map;
	mlx_image_t		*img_menu;
	int				zoom;
	int				angle_z;
	int				angle_y;
	int				angle_x;
	int				dpi;
	mlx_image_t		*menu[10];
	t_ortho			ortho;
}				t_data;

typedef struct s_pos
{
	int		dx;
	int		dy;
	int		startx;
	int		starty;
	t_color	c1;
	t_color	c2;
}				t_pos;

// fdf

int		main(int argc, char **argv);
void	error(char *msg, t_data *data);
void	freeDp(char **arr);

// draw_line

void	drawLoop(t_data *data);
void	drawDot(t_map *dot, t_data *data);
void	drawPixel(int x, int y, t_pos info, t_data *data);
int32_t	getColor(int32_t r, int32_t g, int32_t b, int32_t a);
int		htoi(char	*hexa);
void	resetCheck(t_data *data);

// line_algo

void	drawLine(t_map dot1, t_map dot2, t_data *data);
void	slopeS(t_map dot1, t_map dot2, t_pos info, t_data *data);
void	slopeB(t_map dot1, t_map dot2, t_pos info, t_data *data);

// parsing

void	parsing(int argc, char **argv, t_data *data);
void	fillMap(char **argv, t_data *data);
void	countSize(char *file, t_data *data);
int		countElements(char **split, t_data *data);
void	checkValue(char *value, t_data *data);

// parsing2

t_data	*initData(void);
void	fillDot(t_map	*dot, char *z, t_size size, int i);
void	addToMap(t_map *dot, t_map **map, t_size size);

// rotate

void	rotate(t_data *data);
void	rotateX(t_map *dot, t_data *data);
void	rotateY(t_map *dot, t_data *data);
void	rotateZ(t_map *dot, t_data *data);


// key_actions

void	controll(void *param);
void	key(mlx_key_data_t code, void *param);
void	scroll(double xdelta, double ydelta, void *param);
void	cursor(t_data *data);

// menu

void	drawMenu(t_data *data);
void	deleteImg(t_data *data);

// test

void	freeAll(t_data *data);

// drawMap

void	drawMap(t_data *data);
void	drawMapChanged(t_data *data);
void	addZoom(t_data *data);

// rotateOrtho

void	rotateOrtho(t_data *data);
void	initOrtho(t_data *data);

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