/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:40 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 22:20:40 by lucabohn         ###   ########.fr       */
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
	if (!data->projection)
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
