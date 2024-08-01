/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:04:45 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 11:43:28 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// t_data	*init_data(void)
// {
// 	t_data	*data;

// 	data = (t_data *)malloc (sizeof(t_data));
// 	if (!data)
// 		error(ERROR_4, NULL);
// 	data->map = NULL;
// 	data->default_map = NULL;
// 	data->size = (t_size *)malloc (sizeof(t_size));
// 	if (!data->size)
// 		error(ERROR_4, data);
// 	data->size->dots = 0;
// 	data->size->x_max = 0;
// 	data->size->y_max = 0;
// 	data->size->width = 1600;
// 	data->size->height = 900;
// 	data->zoom = 31;
// 	data->angle_z = 45;
// 	data->angle_y = 45;
// 	data->angle_x = 0;
// 	data->mouse_x = 0;
// 	data->mouse_y = 0;
// 	data->dpi = 40;
// 	return (data);
// }

// void	fill_map(char **argv, t_data *data)
// {
// 	int		i;
// 	int		fd;
// 	char	**split;
// 	t_map	*dots = NULL;

// 	i = 0;
// 	count_size(argv[1], data->size);
// 	data->map = (t_map *)malloc (data->size->dots * sizeof(t_map));
// 	if (!data->map)
// 		error(ERROR_4, data);
// 	data->default_map = (t_map *)malloc (data->size->dots * sizeof(t_map));
// 	if (!data->default_map)
// 		error(ERROR_4, data);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		error(ERROR_1, data);
// 	while (i < data->size->dots)
// 	{
// 		split = ft_split(get_next_line(fd), ' ');
// 		while (*split)
// 		{
// 			fill_dot(&data->map[i], *split, *data->size, i + 1);
// 			add_to_map(&data->map[i], &dots, *data->size);
// 			data->default_map[i] = data->map[i];
// 			split++;
// 			i++;
// 		}
// 	}
// }

void	add_to_map(t_map *dot, t_map **map, t_size size)
{
	t_map	*start;
	t_map	*tmp;

	start = *map;
	if (!start)
	{
		start = dot;
		*map = start;
	}
	else
	{
		if (dot->y == 1)
		{
			while (start->right)
				start = start->right;
			dot->left = start;
			start->right = dot;
		}
		else if (dot->y <= size.y_max)
		{
			if (dot->x == 1)
			{
				while (start->down)
					start = start->down;
				dot->up = start;
				start->down = dot;
			}
			else
			{
				while (start->down)
				{
					if (!start->down->down)
						tmp = start;
					start = start->down;
				}
				while (start->right)
				{
					start = start->right;
					tmp = tmp->right;
				}
				tmp = tmp->right;
				dot->left = start;
				dot->up = tmp;
				tmp->down = dot;
				start->right = dot;
			}
		}
	}
}

// void	fill_dot(t_map	*dot, char *z, t_size size, int i)
// {
// 	int	y;

// 	y = 1;
// 	while (i > size.x_max)
// 	{
// 		i -= size.x_max;
// 		y++;
// 	}
// 	dot->x = i;
// 	dot->y = y;
// 	dot->z = ft_atoi(z);
// 	if (dot->z == 0)
// 		dot->color = "F18F08";
// 	else
// 		dot->color = "00FFFF";
// 	dot->draw_up = false;
// 	dot->draw_down = false;
// 	dot->draw_left = false;
// 	dot->draw_right = false;
// 	dot->up = NULL;
// 	dot->down = NULL;
// 	dot->left = NULL;
// 	dot->right = NULL;
// }

// void	count_size(char *file, t_size *size)
// {
// 	char	*line;
// 	char	**split;
// 	int		fd;
// 	int		dots;

// 	dots = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		error(ERROR_1, NULL);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		split = ft_split(line, ' ');
// 		free(line);
// 		dots += count_elements(split);
// 		size->y_max++;
// 		if (size->y_max == 1)
// 			size->x_max = dots;
// 		free_dp(split);
// 	}
// 	size->dots = dots;
// 	if (close(fd) == -1)
// 		error(ERROR_3, NULL);
// }

// int	count_elements(char **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split[i])
// 		i++;
// 	return (i);
// }
