/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/05 14:40:28 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	rotate(t_data *data)
{
	int		i;
	int		center_x;
	int		center_y;
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
	get_full_r(m, data->size->angle_x, \
		data->size->angle_y, data->size->angle_z);
	while (i < data->size->dots)
	{
		data->map[i].coords = r_vec(m, data->map[i].coords);
		i++;
	}
	translate_to_center(data);
}

t_vec	r_vec(float m[3][3], t_vec v)
{
	t_vec	result;

	result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
	result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
	result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;
	return (result);
}

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
