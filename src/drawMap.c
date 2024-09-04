/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:40 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 17:57:17 by lbohm            ###   ########.fr       */
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
	mlx_new_image(data->window, data->size.width - 300, data->size.height);
	if (!data->translate)
		draw_map(data);
	else
		draw_map_ortho(data);
	mlx_image_to_window(data->window, data->img_map, 300, 0);
	data->moved = false;
}

void	add_zoom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		data->map[i].x = (data->map[i].x - 1) * data->zoom;
		data->map[i].y = (data->map[i].y - 1) * data->zoom;
		data->map[i].z *= data->zoom;
		// data->map[i].x += ((data->size.width - 300) - (data->size.x_max * data->zoom)) / 2 + 10;
		// data->map[i].y += (data->size.height - (data->size.y_max * data->zoom)) / 2 + 10;
		i++;
	}
}

void	add_zoom_test(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		data->map[i].x = (data->map[i].x - 1) * data->zoom;
		data->map[i].y = (data->map[i].y - 1) * data->zoom;
		data->map[i].z *= data->zoom;
		data->map[i].x += \
		(((data->size.width - 300) / 2) - (data->size.x_max / 2 * data->zoom));
		data->map[i].y += ((data->size.height / 2) - (data->size.y_max / 2));
		i++;
	}
}
