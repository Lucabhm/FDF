/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:04:45 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/09 16:52:16 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_data(t_data *data)
{
	data->map = NULL;
	data->size.dots = 0;
	data->size.x_max = 0;
	data->size.y_max = 0;
}

void	fill_map(char **argv, t_data *data)
{
	int		i;
	int		fd;
	char	**split;
	t_map	*dots;

	i = 0;
	count_size(argv[1], &data->size);
	dots = (t_map *)malloc (data->size.dots * sizeof(t_map));
	if (!dots)
		error(ERROR_4, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(ERROR_1, NULL);
	while (i < data->size.dots)
	{
		split = ft_split(get_next_line(fd), ' ');
		while (*split)
		{
			fill_dot(&dots[i], *split, data->size, i + 1);
			// printf("fill x = %i fill y = %i\n", dots[i].x, dots[i].y);
			add_to_map(&dots[i], &data->map, data->size);
			split++;
			i++;
		}
	}
}

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
				printf("start down x = %i y = %i\n", start->x, start->y);
				printf("dot x = %i y = %i\n", dot->x, dot->y);
				printf("tmp x = %i y = %i\n", tmp->x, tmp->y);
				dot->left = start;
				dot->up = tmp;
				tmp->down = dot;
				start->right = dot;
			}
		}
	}
}

void	fill_dot(t_map	*dot, char *z, t_size size, int i)
{
	int		y;
	char	*str;
	char	*sub;

	y = 1;
	while (i > size.x_max)
	{
		i -= size.x_max;
		y++;
	}
	dot->x = i;
	dot->y = y;
	str = ft_strnstr(z, ",", ft_strlen(z));
	if (!str)
	{
		dot->z = ft_atoi(z);
		dot->color = "#000000";
	}
	else
	{
		sub = ft_substr(z, 0, ft_strlen(z) - ft_strlen(str));
		dot->z = ft_atoi(sub);
		dot->color = ft_strdup(str);
		free(sub);
	}
	dot->up = NULL;
	dot->down = NULL;
	dot->left = NULL;
	dot->right = NULL;
}

void	count_size(char *file, t_size *size)
{
	char	*line;
	int		fd;
	char	**split;
	int		dots;

	dots = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(ERROR_1, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		free(line);
		dots += count_elements(split);
		size->y_max++;
		if (size->y_max == 1)
			size->x_max = dots;
		free_dp(split);
	}
	size->dots = dots;
	if (close(fd) == -1)
		error(ERROR_3, NULL);
}

int	count_elements(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
