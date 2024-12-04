/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/04 21:04:03 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotate(t_data *data)
{
	int	i;
	int	center_x;
	int	center_y;
	float	m[3][3];

	i = 0;
	center_x = ((data->size->x_max - 1) * data->size->zoom) / 2;
	center_y = ((data->size->y_max - 1) * data->size->zoom) / 2;
	while (i < data->size->dots)
	{
		data->map[i].coords.x -= center_x;
		data->map[i].coords.y -= center_y;
		i++;
	}
	i = 0;
	get_full_r(m, data->size->angle_x, data->size->angle_y, data->size->angle_z);
	while (i < data->size->dots)
	{
		data->map[i].coords = r_vec(m, data->map[i].coords);
		i++;
	}
	translate_to_center(data);
}

// void	rotate_x(t_map *dot, t_data *data)
// {
// 	double	rad;
// 	int		y;
// 	int		z;

// 	rad = data->size->angle_y * (M_PI / 180.0);
// 	y = dot->y;
// 	z = dot->z;
// 	dot->y = y * cos(rad) - z * sin(rad);
// 	dot->z = y * sin(rad) + z * cos(rad);
// }

// void	rotate_y(t_map *dot, t_data *data)
// {
// 	double	rad;
// 	int		x;
// 	int		z;

// 	// rad = data->size->angle_x * (M_PI / 180.0);
// 	rad = data->size->angle_x;
// 	x = dot->x;
// 	z = dot->z;
// 	dot->x = x * cos(rad) - z * sin(rad);
// 	dot->z = x * sin(rad) + z * cos(rad);
// }

// void	rotate_z(t_map *dot, t_data *data)
// {
// 	double	rad;
// 	int		x;
// 	int		y;

// 	data->size->angle_z = ((data->size->angle_z % 360) + 360) % 360;
// 	rad = data->size->angle_z * (M_PI / 180.0);
// 	x = dot->x;
// 	y = dot->y;
// 	dot->x = x * cos(rad) - y * sin(rad);
// 	dot->y = x * sin(rad) + y * cos(rad);
// }

void	translate_to_center(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		data->map[i].coords.x += data->size->center.x;
		data->map[i].coords.y += data->size->center.y;
		i++;
	}
}
