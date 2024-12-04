/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:24:48 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/04 20:46:39 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	add_to_map(t_map *dot, t_map **map, t_size *size)
{
	t_map	*start;
	t_map	*tmp;

	tmp = NULL;
	start = *map;
	if (!start)
		*map = dot;
	else
	{
		if (dot->coords.y == 1)
		{
			while (start->right)
				start = start->right;
			dot->left = start;
			start->right = dot;
		}
		else if (dot->coords.y <= size->y_max)
			add_to_map_2(dot, start, tmp);
	}
}

void	add_to_map_2(t_map *dot, t_map *start, t_map *tmp)
{
	if (dot->coords.x == 1)
	{
		while (start->down)
			start = start->down;
		dot->up = start;
		start->down = dot;
	}
	else
		add_to_map_3(dot, start, tmp);
}

void	add_to_map_3(t_map *dot, t_map *start, t_map *tmp)
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

void	check_value(char *value, t_data *data)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (ft_strnstr(value, ",", ft_strlen(value)))
		len = ft_strlen(ft_strnstr(value, ",", ft_strlen(value)));
	while (i < (int)ft_strlen(value) - len && value[i] != '\n')
	{
		if (!ft_isdigit(value[i]) && value[0] != '-' && i == 0)
			error(ERROR_7, data);
		i++;
	}
}

char	*clean_line(char *line)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[i] == '\t' || line[i] == '\v'
				|| line[i] == '\f' || line[i] == '\r' || line[i] == '\n')
				line[i] = ' ';
			i++;
		}
	}
	return (line);
}
