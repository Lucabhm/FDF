/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 18:07:51 by lbohm            ###   ########.fr       */
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
}

void	rotate_x(t_map *dot, t_data *data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		y;
	int		z;

	rad = data->angle_y * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	y = dot->y;
	z = dot->z;
	dot->y = y * cosa - z * sina;
	dot->z = y * sina + z * cosa;
}

void	rotate_y(t_map *dot, t_data *data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		z;

	rad = data->angle_x * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x;
	z = dot->z;
	dot->x = x * cosa - z * sina;
	dot->z = x * sina + z * cosa;
}

void	rotate_z(t_map *dot, t_data *data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		y;

	rad = data->angle_z * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x;
	y = dot->y;
	dot->x = x * cosa - y * sina;
	dot->y = x * sina + y * cosa;
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
			if (min < data->map[i].x)
				min = data->map[i].x;
		}
		else
		{
			if (min < data->map[i].y)
				min = data->map[i].y;
		}
	}
	return (min);
}
