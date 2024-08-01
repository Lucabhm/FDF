/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 10:42:05 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	add_zoom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		data->map[i].x = (data->map[i].x - 1) * data->zoom;
		data->map[i].y = (data->map[i].y - 1) * data->zoom;
		data->map[i].z *= data->zoom;
		data->map[i].x += (650 - (data->size->x_max / 2 * data->zoom));
		data->map[i].y += (450 - (data->size->y_max / 2 * data->zoom));
		i++;
	}
}

void	rotate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		rotate_z(&data->map[i], data->angle_z, *data);
		rotate_x(&data->map[i], data->angle_y, *data);
		rotate_y(&data->map[i], data->angle_x, *data);
		i++;
	}
}

void	rotate_x(t_map *dot, int angle, t_data data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		y;
	int		z;

	rad = angle * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	y = dot->y - (450 - (data.size->y_max / 2));
	z = dot->z;
	dot->y = y * cosa - z * sina;
	dot->z = y * sina + z * cosa;
	dot->y += (450 - (data.size->y_max / 2));
}

void	rotate_y(t_map *dot, int angle, t_data data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		z;

	rad = angle * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x - (650 - (data.size->x_max / 2));
	z = dot->z;
	dot->x = x * cosa - z * sina;
	dot->z = x * sina + z * cosa;
	dot->x += (650 - (data.size->x_max / 2));
}

void	rotate_z(t_map *dot, int angle, t_data data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		y;

	rad = angle * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x - (650 - (data.size->x_max / 2));
	y = dot->y - (450 - (data.size->y_max / 2));
	dot->x = x * cosa - y * sina;
	dot->y = x * sina + y * cosa;
	dot->x += (650 - (data.size->x_max / 2));
	dot->y += (450 - (data.size->y_max / 2));
}
