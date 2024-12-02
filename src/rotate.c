/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/02 12:04:39 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_data *data)
{
	int	i;
	int	center_x;
	int	center_y;

	i = 0;
	center_x = ((data->size->x_max - 1) * data->size->zoom) / 2;
	center_y = ((data->size->y_max - 1) * data->size->zoom) / 2;
	while (i < data->size->dots)
	{
		data->map[i].x -= center_x;
		data->map[i].y -= center_y;
		i++;
	}
	i = 0;
	while (i < data->size->dots)
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

	rad = data->size->angle_y * (M_PI / 180.0);
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

	rad = data->size->angle_x * (M_PI / 180.0);
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

	rad = data->size->angle_z * (M_PI / 180.0);
	x = dot->x;
	y = dot->y;
	dot->x = x * cos(rad) - y * sin(rad);
	dot->y = x * sin(rad) + y * cos(rad);
}

void	translate_to_center(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		data->map[i].x += data->size->center.x;
		data->map[i].y += data->size->center.y;
		i++;
	}
}
