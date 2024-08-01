/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:06:45 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 11:10:07 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc (sizeof(t_data));
	if (!data)
		error(ERROR_4, NULL);
	data->map = NULL;
	data->default_map = NULL;
	data->size.dots = 0;
	data->size.x_max = 0;
	data->size.y_max = 0;
	data->size.width = 1600;
	data->size.height = 900;
	data->window = NULL;
	data->img_map = NULL;
	data->img_menu = NULL;
	data->zoom = 31;
	data->angle_z = 45;
	data->angle_y = 45;
	data->angle_x = 0;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->dpi = 40;
	return (data);
}
