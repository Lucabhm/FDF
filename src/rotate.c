/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/10 17:06:50 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	add_zoom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		data->dots[i].x = (data->dots[i].x - 1) * 50;
		data->dots[i].y = (data->dots[i].y - 1) * 50 + 50;
		data->dots[i].z *= 50;
		i++;
	}
}

void	rotate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		rotate_y(&data->dots[i]);
		rotate_x(&data->dots[i]);
		i++;
	}
}

void	rotate_x(t_map *dot)
{
	double	rad;
	double	cosA;
	double	sinA;
	int		y;
	int		z;

	rad = 35.264 * 3.14 / 180.0;
	cosA = cos(rad);
	sinA = sin(rad);
	y = dot->y;
	z = dot->z;
	dot->y = y * cosA - z * sinA;
	dot->z = y * sinA + z * cosA;
}

void	rotate_y(t_map *dot)
{
	double	rad;
	double	cosA;
	double	sinA;
	t_map	result;
	int		x;
	int		z;

	rad = -45 * 3.14 / 180.0;
	cosA = cos(rad);
	sinA = sin(rad);
	x = dot->x;
	z = dot->z;
	dot->x = x * cosA + z * sinA;
	dot->z = -x * sinA + z * cosA;
}

void	rotate_z(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->size.dots)
	{
		x = data->dots[i].x;
		y = data->dots[i].y;
		data->dots[i].x = (x - y) * cos(0.523599);
		data->dots[i].y = -data->dots[i].z + (x + y) * sin(0.523599);
		i++;
	}
}
