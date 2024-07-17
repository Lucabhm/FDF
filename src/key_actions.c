/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/17 17:24:10 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	controll(void *param)
{
	t_data	*data;

	data = param;
	mlx_scroll_hook(data->window, scroll, data);
	mlx_key_hook(data->window, key, data);
}

void	key(mlx_key_data_t code, void *param)
{
	t_data	*data;

	data = param;
	if (code.key == MLX_KEY_ESCAPE && code.action == 1)
		mlx_close_window(data->window);
	else if (code.key == MLX_KEY_EQUAL && (code.action == 1 || code.action == 2))
	{
		data->zoom++;
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		rotate(data);
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_MINUS && (code.action == 1 || code.action == 2))
	{
		data->zoom--;
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		rotate(data);
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_RIGHT && (code.action == 1 || code.action == 2))
	{
		data->angle_z += 2;
		printf("angle = %i\n", data->angle_z);
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		for (int i = 0; i < data->size.dots; i++)
		{
			rotate_z(&data->dots[i], data->angle_z, *data);
			// rotate_x(&data->dots[i], 45);
		}
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_LEFT && (code.action == 1 || code.action == 2))
	{
		data->angle_z -= 2;
		printf("angle = %i\n", data->angle_z);
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		for (int i = 0; i < data->size.dots; i++)
		{
			rotate_z(&data->dots[i], data->angle_z, *data);
			// rotate_x(&data->dots[i], 45);
		}
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
}

void	scroll(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	xdelta = 0;
	if (ydelta > 0)
	{
		data->zoom++;
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		rotate(data);
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (ydelta < 0)
	{
		data->zoom--;
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		rotate(data);
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
}
