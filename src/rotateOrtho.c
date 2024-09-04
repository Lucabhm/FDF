/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateOrtho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:11:54 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 22:17:45 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_ortho(t_data *data)
{
	int	i;

	i = 0;
	data->ortho.l = 0;
	data->ortho.r = 2;
	data->ortho.b = 0;
	data->ortho.t = 2;
	data->ortho.n = 0;
	data->ortho.f = 0;
	while (i < data->size.dots)
	{
		if (data->map[i].z <= data->ortho.n)
			data->ortho.n = data->map[i].z;
		if (data->map[i].z >= data->ortho.f)
			data->ortho.f = data->map[i].z;
		i++;
	}
}

void	rotate_ortho(t_data *data)
{
	int		i;
	float	rl;
	float	rl2;
	float	tb;
	float	tb2;
	float	fn;
	float	fn2;

	i = 0;
	rl = 2.0 / (data->ortho.r - data->ortho.l);
	rl2 = (data->ortho.r + data->ortho.l) / (data->ortho.r - data->ortho.l);
	tb = 2.0 / (data->ortho.t - data->ortho.b);
	tb2 = (data->ortho.t + data->ortho.b) / (data->ortho.t - data->ortho.b);
	fn = 2.0 / (data->ortho.f - data->ortho.n);
	fn2 = (data->ortho.f + data->ortho.n) / (data->ortho.f - data->ortho.n);
	while (i < data->size.dots)
	{
		data->map[i].x = (rl * data->map[i].x) - rl2;
		data->map[i].y = (tb * data->map[i].y) - tb2;
		data->map[i].z = -(fn * data->map[i].z) - fn2;
		i++;
	}
}

void	draw_map_ortho(t_data *data)
{
	reset_check(data);
	mlx_delete_image(data->window, data->img_map);
	data->img_map = mlx_new_image(data->window, data->size.width - 300, 900);
	add_zoom(data);
	rotate(data);
	rotate_ortho(data);
	draw_loop(data);
	mlx_image_to_window(data->window, data->img_map, 300, 0);
}

void	key_ortho(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_P && code.action == 1)
	{
		data->angle_z = 45;
		data->angle_x = 30;
		data->projection = true;
		change_projection_img(data);
	}
	else if (code.key == MLX_KEY_T && code.action == 1)
	{
		data->angle_x = 0;
		data->angle_y = 0;
		data->projection = true;
		change_projection_img(data);
	}
	else if (code.key == MLX_KEY_F && code.action == 1)
	{
		data->angle_y = 90;
		data->projection = true;
		change_projection_img(data);
	}
}
