/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/10/02 13:27:12 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_data *data)
{
	int	i;

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

	rad = data->size->angle_y * 3.14 / 180.0;
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

	rad = data->size->angle_x * 3.14 / 180.0;
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

	rad = data->size->angle_z * 3.14 / 180.0;
	x = dot->x;
	y = dot->y;
	dot->x = x * cos(rad) - y * sin(rad);
	dot->y = x * sin(rad) + y * cos(rad);
}
