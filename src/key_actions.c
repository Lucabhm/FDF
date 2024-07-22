/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/22 15:18:41 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	controll(void *param)
{
	t_data	*data;

	data = param;
	mlx_scroll_hook(data->window, scroll, data);
	cursor(data);
	mlx_key_hook(data->window, key, data);
}

void	key(mlx_key_data_t code, void *param)
{
	t_data	*data;
	char	*str;

	data = param;
	if (code.key == MLX_KEY_ESCAPE && code.action == 1)
		mlx_close_window(data->window);
	else if (code.key == MLX_KEY_EQUAL && (code.action == 1 || code.action == 2))
	{
		data->dpi++;
		mlx_delete_image(data->window, data->menu[9]);
		str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
		data->menu[9] = mlx_put_string(data->window, str, 0, 180);
		free(str);
	}
	else if (code.key == MLX_KEY_MINUS && (code.action == 1 || code.action == 2))
	{
		if (data->dpi > 1)
		{
			data->dpi--;
			mlx_delete_image(data->window, data->menu[9]);
			str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
			data->menu[9] = mlx_put_string(data->window, str, 0, 180);
			free(str);
		}
	}
	else if (code.key == MLX_KEY_RIGHT && (code.action == 1 || code.action == 2))
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
			rotate_x(&data->dots[i], data->angle_y, *data);
		}
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_LEFT && (code.action == 1 || code.action == 2))
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
			rotate_x(&data->dots[i], data->angle_y, *data);
		}
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_UP && (code.action == 1 || code.action == 2))
	{
		data->angle_y += 2;
		printf("angle = %i\n", data->angle_y);
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		for (int i = 0; i < data->size.dots; i++)
		{
			rotate_z(&data->dots[i], data->angle_z, *data);
			rotate_x(&data->dots[i], data->angle_y, *data);
		}
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_DOWN && (code.action == 1 || code.action == 2))
	{
		data->angle_y -= 2;
		printf("angle = %i\n", data->angle_y);
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		for (int i = 0; i < data->size.dots; i++)
		{
			rotate_z(&data->dots[i], data->angle_z, *data);
			rotate_x(&data->dots[i], data->angle_y, *data);
		}
		draw_loop(*data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_I && code.action == 1)
	{
		data->angle_z = 45;
		data->angle_y = 45;
		reset_check(data);
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		add_zoom(data);
		for (int i = 0; i < data->size.dots; i++)
		{
			rotate_z(&data->dots[i], data->angle_z, *data);
			rotate_x(&data->dots[i], data->angle_y, *data);
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
		if (data->zoom - 1 > 0)
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

void	cursor(t_data *data)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(data->window, &x, &y);
	if (!data->mouse_x && !data->mouse_y)
	{
		data->mouse_x = x / data->dpi;
		data->mouse_y = y / data->dpi;
	}
	else
	{
		if (mlx_is_mouse_down(data->window, MLX_MOUSE_BUTTON_LEFT))
		{
			printf("left button pressed\n");
			printf("dx = %i\n", (x / data->dpi) - data->mouse_x);
			printf("dy = %i\n", (y / data->dpi)  - data->mouse_y);
			data->angle_z -= (x / data->dpi) - data->mouse_x;
			data->angle_y -= (y / data->dpi) - data->mouse_y;
			reset_check(data);
			mlx_delete_image(data->window, data->img_map);
			data->img_map = mlx_new_image(data->window, 1300, 900);
			add_zoom(data);
			for (int i = 0; i < data->size.dots; i++)
			{
				rotate_z(&data->dots[i], data->angle_z, *data);
				rotate_x(&data->dots[i], data->angle_y, *data);
			}
			draw_loop(*data);
			mlx_image_to_window(data->window, data->img_map, 300, 0);
		}
		else
		{
			data->mouse_x = 0;
			data->mouse_y = 0;
		}
	}
}
