/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/10 23:19:55 by lucabohn         ###   ########.fr       */
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
		data->dots[i].y = (data->dots[i].y - 1) * 50 + 500;
		data->dots[i].z *= 100;
		i++;
	}
}

void	rotate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		rotate_z(&data->dots[i]);
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
// 35.264
	rad = 55 * 3.14 / 180.0;
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
	int		x;
	int		z;

	rad = 80 * 3.14 / 180.0;
	cosA = cos(rad);
	sinA = sin(rad);
	x = dot->x;
	z = dot->z;
	dot->x = x * cosA + z * sinA;
	dot->z = -x * sinA + z * cosA;
}

void	rotate_z(t_map *dot)
{
	double	rad;
	double	cosA;
	double	sinA;
	int		x;
	int		y;

	rad = 45 * 3.14 / 180.0;
	cosA = cos(rad);
	sinA = sin(rad);
	x = dot->x;
	y = dot->y;
	dot->x = x * cosA + y * sinA;
	dot->y = -x * sinA + y * cosA;
}
