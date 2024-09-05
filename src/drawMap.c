/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:40 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/05 12:43:14 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_map(t_data *data)
{
	add_zoom(data);
	rotate(data);
	draw_loop(data);
}

void	draw_map_changed(t_data *data)
{
	reset_check(data);
	mlx_delete_image(data->window, data->img_map);
	data->img_map = \
	mlx_new_image(data->window, data->size->width - 300, data->size->height);
	if (!data->size->projection)
		draw_map(data);
	else
		draw_map_ortho(data);
	mlx_image_to_window(data->window, data->img_map, 300, 0);
	data->size->moved = false;
}

void	add_zoom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		data->map[i].x = (data->map[i].x - 1) * data->size->zoom;
		data->map[i].y = (data->map[i].y - 1) * data->size->zoom;
		data->map[i].z *= data->size->zoom * data->size->z_zoom;
		i++;
	}
}

void	reset_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size->dots)
	{
		data->map[i] = data->default_map[i];
		i++;
	}
}
