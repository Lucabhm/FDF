/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateOrtho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:11:54 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/05 15:02:52 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_ortho(t_data *data)
{
	int	i;

	i = 0;
	data->ortho.l = -1.0;
	data->ortho.r = 1.0;
	data->ortho.b = -1.0;
	data->ortho.t = 1.0;
	data->ortho.n = 0.0;
	data->ortho.f = 0.0;
	while (i < data->size->dots)
	{
		if (data->map[i].coords.z <= data->ortho.n)
			data->ortho.n = data->map[i].coords.z;
		if (data->map[i].coords.z >= data->ortho.f)
			data->ortho.f = data->map[i].coords.z;
		i++;
	}
}

void	rotate_ortho(t_data *data)
{
	int		i;
	t_ortho	v;

	i = 0;
	v.r = 2.0 / (data->ortho.r - data->ortho.l);
	v.l = (data->ortho.r + data->ortho.l) / (data->ortho.r - data->ortho.l);
	v.t = 2.0 / (data->ortho.t - data->ortho.b);
	v.b = (data->ortho.t + data->ortho.b) / (data->ortho.t - data->ortho.b);
	v.f = 2.0 / (data->ortho.f - data->ortho.n);
	v.n = (data->ortho.f + data->ortho.n) / (data->ortho.f - data->ortho.n);
	while (i < data->size->dots)
	{
		data->map[i].coords.x = (v.r * data->map[i].coords.x) - v.l;
		data->map[i].coords.y = (v.t * data->map[i].coords.y) - v.b;
		data->map[i].coords.z = -(v.f * data->map[i].coords.z) - v.n;
		i++;
	}
}

void	draw_map_ortho(t_data *data)
{
	reset_check(data);
	add_zoom(data);
	rotate(data);
	rotate_ortho(data);
	draw_loop(data);
}

void	key_ortho(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_T && code.action == 1)
	{
		data->size->angle_x = 0;
		data->size->angle_y = 0;
		data->size->projection = true;
		change_projection_img(data);
	}
	else if (code.key == MLX_KEY_F && code.action == 1)
	{
		data->size->angle_x = 90 * (M_PI / 180);
		data->size->angle_y = 0;
		data->size->angle_z = 0;
		data->size->projection = true;
		change_projection_img(data);
	}
}
