/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/03 21:24:22 by lucabohn         ###   ########.fr       */
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
	drawMapChanged(data);
}

void	key(mlx_key_data_t code, void *param)
{
	t_data	*data;
	char	*str;
	static int	check = 0;

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
		data->angle_z -= 2;
	else if (code.key == MLX_KEY_LEFT && (code.action == 1 || code.action == 2))
		data->angle_z += 2;
	else if (code.key == MLX_KEY_UP && (code.action == 1 || code.action == 2))
		data->angle_y += 2;
	else if (code.key == MLX_KEY_DOWN && (code.action == 1 || code.action == 2))
		data->angle_y -= 2;
	else if (code.key == MLX_KEY_I && code.action == 1)
	{
		data->angle_z = 45;
		data->angle_y = 45;
	}
	else if (code.key == MLX_KEY_R && code.action == 1)
	{
		data->angle_z = 45;
		data->angle_y = 45;
		data->angle_x = 0;
		data->zoom = 31;
		data->dpi = 40;
		mlx_delete_image(data->window, data->menu[9]);
		str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
		data->menu[9] = mlx_put_string(data->window, str, 0, 180);
		free(str);
	}
	else if (code.key == MLX_KEY_P && code.action == 1)
	{
		resetCheck(data);
		if (!check)
		{
			initOrtho(data);
			check = 1;
		}
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		addZoom(data);
		data->angle_z = 45;
		data->angle_x = 30;
		for (int i = 0; i < data->size.dots; i++)
		{
			rotateX(&data->map[i], data);
			rotateY(&data->map[i], data);
			rotateZ(&data->map[i], data);
		}
		rotateOrtho(data);
		drawLoop(data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_T && code.action == 1)
	{
		resetCheck(data);
		if (!check)
		{
			initOrtho(data);
			check = 1;
		}
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		data->angle_x = 0;
		data->angle_y = 0;
		addZoom(data);
		rotateOrtho(data);
		drawLoop(data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_F && code.action == 1)
	{
		resetCheck(data);
		if (!check)
		{
			initOrtho(data);
			check = 1;
		}
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		addZoom(data);
		data->angle_y = 90;
		for (int i = 0; i < data->size.dots; i++)
			rotateX(&data->map[i], data);
		rotateOrtho(data);
		drawLoop(data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
	else if (code.key == MLX_KEY_S && code.action == 1)
	{
		resetCheck(data);
		if (!check)
		{
			initOrtho(data);
			check = 1;
		}
		mlx_delete_image(data->window, data->img_map);
		data->img_map = mlx_new_image(data->window, 1300, 900);
		addZoom(data);
		data->angle_x = 90;
		data->angle_y = 90;
		for (int i = 0; i < data->size.dots; i++)
		{
			rotateX(&data->map[i], data);
			rotateY(&data->map[i], data);
		}
		rotateOrtho(data);
		drawLoop(data);
		mlx_image_to_window(data->window, data->img_map, 300, 0);
	}
}

void	scroll(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	xdelta = 0;
	if (ydelta > 0 && xdelta == 0)
		data->zoom++;
	else if (ydelta < 0)
	{
		if (data->zoom - 1 > 0)
			data->zoom--;
	}
}

void	cursor(t_data *data)
{
	int	nowX;
	int	nowY;
	static int	mouseX = 0;
	static int	mouseY = 0;

	mlx_get_mouse_pos(data->window, &nowX, &nowY);
	if (!mouseX && !mouseY)
	{
		mouseX = nowX / data->dpi;
		mouseY = nowY / data->dpi;
	}
	else
	{
		if (mlx_is_mouse_down(data->window, MLX_MOUSE_BUTTON_LEFT))
		{
			data->angle_z -= (nowX / data->dpi) - mouseX;
			data->angle_y -= (nowY / data->dpi) - mouseY;
		}
		else
		{
			mouseX = 0;
			mouseY = 0;
		}
	}
}
