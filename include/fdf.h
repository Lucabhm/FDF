/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:13:18 by lbohm             #+#    #+#             */
/*   Updated: 2024/06/28 17:17:45 by lbohm            ###   ########.fr       */
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
typedef struct s_data
{
	int			**map;
	mlx_t		*window;
	mlx_image_t	*img;
}				t_data;

typedef struct s_pos
{
	int		x;
	int		y;
	int		x_2;
	int		y_2;
	float	delta_x;
	float	delta_y;
	float	slope;
}				t_pos;

// fdf

int		main(int argc, char **argv);
void	parsing(int argc, char **argv, t_data *data);
void	error(char *msg, t_data *data);
int		**fill_map(char **argv);
int		count_rows(char *file);
int		check_input(char **split);
int		*fill_rows(char **split);
void	free_dp(char **arr);

// draw_line

void	first_step(int x, int y, int x_2, int y_2, t_data data);
void	slope_bigger(t_pos value, t_data data);
void	slope_smaller(t_pos value, t_data data);
void	draw_pixel(int x, int y, t_data data);
int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	isometric(int *x, int *y);

// error msg

# define ERROR_0 "Wrong nbr of Arrguments!\n"
# define ERROR_1 "Open failed!\n"
# define ERROR_2 "Map has invalide char!\n"
# define ERROR_3 "Close failed!\n"
# define ERROR_4 "Allocation failed!\n"
# define ERROR_5 "File ends not with .fdf\n"

#endif