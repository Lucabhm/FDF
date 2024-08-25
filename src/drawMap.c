/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:57:49 by lucabohn          #+#    #+#             */
/*   Updated: 2024/08/23 17:22:59 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	drawMap(t_data *data)
{
	addZoom(data);
	rotate(data);
	drawLoop(data);
}

void	drawMapChanged(t_data *data)
{
	resetCheck(data);
	mlx_delete_image(data->window, data->img_map);
	data->img_map = mlx_new_image(data->window, 1300, 900);
	drawMap(data);
	mlx_image_to_window(data->window, data->img_map, 300, 0);
}

void	addZoom(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size.dots)
	{
		data->map[i].x = (data->map[i].x - 1) * data->zoom;
		data->map[i].y = (data->map[i].y - 1) * data->zoom;
		data->map[i].z *= data->zoom;
		data->map[i].x += (650 - (data->size.x_max / 2 * data->zoom));
		data->map[i].y += (450 - (data->size.y_max / 2 * data->zoom));
		i++;
	}
}
