/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:57:49 by lucabohn          #+#    #+#             */
/*   Updated: 2024/08/01 21:31:46 by lucabohn         ###   ########.fr       */
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