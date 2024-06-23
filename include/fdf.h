/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:47 by lucabohn          #+#    #+#             */
/*   Updated: 2024/06/23 18:05:29 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/ft_libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/ft_get_next_line/get_next_line.h"
# include "../lib/mlx/include/MLX42/MLX42.h"

// struct
typedef struct	s_data
{
	char	***map;
	mlx_t	*window;
}				t_data;

// fdf

int		main(int argc, char **argv);
void	print_line(char direction, int pos_x, int pos_y, mlx_image_t *img);
int32_t	get_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	parsing(int argc, char **argv, t_data *data);
int		count_rows(char *file);
void	check_input(char **split, t_data *data);
char	**cpy_dp(char **arr, t_data *data);
void	free_dp(char **arr);
void	free_tp(char ***arr);
void	error(char *msg, t_data *data);

// error msg

# define ERROR_0 "Wrong nbr of Arrguments!\n"
# define ERROR_1 "Open failed!\n"
# define ERROR_2 "Map has invalide char!\n"
# define ERROR_3 "Close failed!\n"
# define ERROR_4 "Allocation failed!\n"


#endif