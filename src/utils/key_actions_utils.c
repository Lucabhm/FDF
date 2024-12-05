/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:33:02 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/05 14:50:38 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	wasdqe(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_W && (code.action == 1 || code.action == 2))
		data->size->zoom++;
	else if (code.key == MLX_KEY_S && (code.action == 1 || code.action == 2))
	{
		if (data->size->zoom - 1 > 0)
			data->size->zoom--;
	}
	if (code.key == MLX_KEY_A && (code.action == 1 || code.action == 2))
		data->size->center.x -= 10;
	else if (code.key == MLX_KEY_D && (code.action == 1 || code.action == 2))
		data->size->center.x += 10;
	else if (code.key == MLX_KEY_Q && (code.action == 1 || code.action == 2))
		data->size->center.y -= 10;
	else if (code.key == MLX_KEY_E && (code.action == 1 || code.action == 2))
		data->size->center.y += 10;
	else
		return ;
	change_center_img(data);
}

void	reset(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_R && code.action == 1)
	{
		data->size->angle_z = 45;
		data->size->angle_y = 0;
		data->size->angle_x = atan(sqrt(0.5));
		data->size->zoom = data->size->scale;
		data->size->center.x = (data->window->width - data->size->ratio) / 2;
		data->size->center.y = data->window->height / 2;
		data->size->dpi = 40;
		data->size->z_zoom = 1;
		data->size->projection = false;
		change_projection_img(data);
		change_center_img(data);
		change_mouse_img(data);
	}
}

void	set_dpi(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_EQUAL
		&& (code.action == 1 || code.action == 2))
	{
		data->size->dpi++;
		change_mouse_img(data);
	}
	else if (code.key == MLX_KEY_MINUS
		&& (code.action == 1 || code.action == 2))
	{
		if (data->size->dpi > 1)
		{
			data->size->dpi--;
			change_mouse_img(data);
		}
	}
}

void	z_altitude(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_1 && (code.action == 1 || code.action == 2))
		data->size->z_zoom += 0.5;
	if (code.key == MLX_KEY_3 && (code.action == 1 || code.action == 2))
		data->size->z_zoom -= 0.5;
}
