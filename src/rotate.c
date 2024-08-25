/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/23 17:22:51 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		rotateZ(&data->map[i], data);
		rotateX(&data->map[i], data);
		rotateY(&data->map[i], data);
		i++;
	}
}

void	rotateX(t_map *dot, t_data *data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		y;
	int		z;

	rad = data->angle_y * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	y = dot->y - (450 - (data->size.y_max / 2));
	z = dot->z;
	dot->y = y * cosa - z * sina;
	dot->z = y * sina + z * cosa;
	dot->y += (450 - (data->size.y_max / 2));
}

void	rotateY(t_map *dot, t_data *data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		z;

	rad = data->angle_x * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x - (650 - (data->size.x_max / 2));
	z = dot->z;
	dot->x = x * cosa - z * sina;
	dot->z = x * sina + z * cosa;
	dot->x += (650 - (data->size.x_max / 2));
}

void	rotateZ(t_map *dot, t_data *data)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		y;

	rad = data->angle_z * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x - (650 - (data->size.x_max / 2));
	y = dot->y - (450 - (data->size.y_max / 2));
	dot->x = x * cosa - y * sina;
	dot->y = x * sina + y * cosa;
	dot->x += (650 - (data->size.x_max / 2));
	dot->y += (450 - (data->size.y_max / 2));
}
