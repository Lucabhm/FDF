/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:40:38 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/05 15:29:07 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	max(t_data *data, char coord)
{
	int	i;
	int	max;

	i = 0;
	if (coord == 'x')
		max = data->map[i].x;
	else if (coord == 'y')
		max = data->map[i].y;
	else
		max = data->map[i].z;
	while (i < data->size->dots)
	{
		i++;
		if (coord == 'x')
		{
			if (max < data->map[i].x)
				max = data->map[i].x;
		}
		else if (coord == 'y')
		{
			if (max < data->map[i].y)
				max = data->map[i].y;
		}
		else
		{
			if (max < data->map[i].z)
				max = data->map[i].z;
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
	else if (coord == 'y')
		min = data->map[i].y;
	else
		min = data->map[i].z;
	while (i < data->size->dots)
	{
		i++;
		if (coord == 'x')
		{
			if (min > data->map[i].x)
				min = data->map[i].x;
		}
		else if (coord == 'y')
		{
			if (min > data->map[i].y)
				min = data->map[i].y;
		}
		else
		{
			if (min > data->map[i].z)
				min = data->map[i].z;
		}
	}
	return (min);
}

void	translate_to_center(t_data *data)
{
	int	i;
	int	translation_x;
	int	translation_y;

	i = 0;
	translation_x = data->size->center.x
		- (min(data, 'x') + max(data, 'x')) / 2;
	translation_y = data->size->center.y
		- (min(data, 'y') + max(data, 'y')) / 2;
	while (i < data->size->dots)
	{
		data->map[i].x += translation_x;
		data->map[i].y += translation_y;
		// printf("z = %i\n", data->map[i].z);
		i++;
	}
}
