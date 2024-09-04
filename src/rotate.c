/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 22:11:17 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		rotate_z(&data->map[i], data);
		rotate_x(&data->map[i], data);
		rotate_y(&data->map[i], data);
		i++;
	}
	translate_to_center(data);
}

void	rotate_x(t_map *dot, t_data *data)
{
	double	rad;
	int		y;
	int		z;

	rad = data->angle_y * 3.14 / 180.0;
	y = dot->y;
	z = dot->z;
	dot->y = y * cos(rad) - z * sin(rad);
	dot->z = y * sin(rad) + z * cos(rad);
}

void	rotate_y(t_map *dot, t_data *data)
{
	double	rad;
	int		x;
	int		z;

	rad = data->angle_x * 3.14 / 180.0;
	x = dot->x;
	z = dot->z;
	dot->x = x * cos(rad) - z * sin(rad);
	dot->z = x * sin(rad) + z * cos(rad);
}

void	rotate_z(t_map *dot, t_data *data)
{
	double	rad;
	int		x;
	int		y;

	rad = data->angle_z * 3.14 / 180.0;
	x = dot->x;
	y = dot->y;
	dot->x = x * cos(rad) - y * sin(rad);
	dot->y = x * sin(rad) + y * cos(rad);
}

int	max(t_data *data, char coord)
{
	int	i;
	int	max;

	i = 0;
	if (coord == 'x')
		max = data->map[i].x;
	else
		max = data->map[i].y;
	while (i < data->size.dots)
	{
		i++;
		if (coord == 'x')
		{
			if (max < data->map[i].x)
				max = data->map[i].x;
		}
		else
		{
			if (max < data->map[i].y)
				max = data->map[i].y;
		}
	}
	return (max);
}

int	min(t_data *data, char coord)
{
	int	i;
	int	min;

	i = 0;
	if (coord == 'x')
		min = data->map[i].x;
	else
		min = data->map[i].y;
	while (i < data->size.dots)
	{
		i++;
		if (coord == 'x')
		{
			if (min > data->map[i].x)
				min = data->map[i].x;
		}
		else
		{
			if (min > data->map[i].y)
				min = data->map[i].y;
		}
	}
	return (min);
}

void	translate_to_center(t_data *data)
{
	int	min_x = min(data, 'x');
	int	max_x = max(data, 'x');
	int	min_y = min(data, 'y');
	int	max_y = max(data, 'y');

	int	center_x = (min_x + max_x) / 2;
	int	center_y = (min_y + max_y) / 2;

	int	translation_x = data->size.center.red - center_x;
	int	translation_y = data->size.center.green - center_y;

	int	i = 0;
	while (i < data->size.dots)
	{
		data->map[i].x += translation_x;
		data->map[i].y += translation_y;
		i++;
	}
}
