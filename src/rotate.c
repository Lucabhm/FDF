/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:24:01 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/12 16:41:44 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	add_zoom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		data->dots[i].x = (data->dots[i].x - 1) * data->zoom;
		data->dots[i].y = (data->dots[i].y - 1) * data->zoom;
		data->dots[i].z *= 5;
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
		data->dots[i].x += 1300 / 2 - (data->size.x_max * 10 / 2);
		data->dots[i].y += 900 / 2 - (data->size.y_max * 30 / 2);
		i++;
	}
}

void	rotate_x(t_map *dot)
{
	double	rad;
	double	cosa;
	double	sina;
	int		y;
	int		z;

	rad = 45 * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	y = dot->y;
	z = dot->z;
	dot->y = y * cosa - z * sina;
	dot->z = y * sina + z * cosa;
}

void	rotate_y(t_map *dot)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		z;

	rad = 80 * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x;
	z = dot->z;
	dot->x = x * cosa + z * sina;
	dot->z = -x * sina + z * cosa;
}

void	rotate_z(t_map *dot)
{
	double	rad;
	double	cosa;
	double	sina;
	int		x;
	int		y;

	rad = 45 * 3.14 / 180.0;
	cosa = cos(rad);
	sina = sin(rad);
	x = dot->x;
	y = dot->y;
	dot->x = x * cosa - y * sina;
	dot->y = x * sina + y * cosa;
}
