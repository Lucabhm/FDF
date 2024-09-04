/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 22:17:26 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	controll(void *param)
{
	t_data	*data;

	data = param;
	mlx_scroll_hook(data->window, scroll, data);
	mlx_resize_hook(data->window, resize, data);
	cursor(data);
	mlx_key_hook(data->window, key, data);
	if (data->moved)
		draw_map_changed(data);
}

void	key(mlx_key_data_t code, void *param)
{
	t_data		*data;

	data = param;
	if (code.key == MLX_KEY_ESCAPE && code.action == 1)
		mlx_close_window(data->window);
	else if (code.key == MLX_KEY_EQUAL
		&& (code.action == 1 || code.action == 2))
	{
		data->dpi++;
		change_mouse_img(data);
	}
	else if (code.key == MLX_KEY_MINUS
		&& (code.action == 1 || code.action == 2))
	{
		if (data->dpi > 1)
		{
			data->dpi--;
			change_mouse_img(data);
		}
	}
	else if (code.key == MLX_KEY_I && code.action == 1)
	{
		data->angle_z = 45;
		data->angle_y = 35;
		data->projection = false;
		change_projection_img(data);
	}
	else if (code.key == MLX_KEY_R && code.action == 1)
	{
		data->angle_z = 45;
		data->angle_y = 35;
		data->angle_x = 0;
		data->zoom = 31;
		data->dpi = 40;
		change_mouse_img(data);
		data->projection = false;
	}
	wasdqe(code, data);
	key_ortho(code, data);
	data->moved = true;
}

void	scroll(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	xdelta = 0;
	if (ydelta > 0 && xdelta == 0)
	{
		data->zoom++;
	}
	else if (ydelta < 0)
	{
		if (data->zoom - 1 > 0)
			data->zoom--;
	}
	data->moved = true;
}

void	cursor(t_data *data)
{
	int			nowx;
	int			nowy;
	static int	mousex = 0;
	static int	mousey = 0;

	mlx_get_mouse_pos(data->window, &nowx, &nowy);
	if (!mousex && !mousey)
	{
		mousex = nowx / data->dpi;
		mousey = nowy / data->dpi;
	}
	else
	{
		if (mlx_is_mouse_down(data->window, MLX_MOUSE_BUTTON_LEFT))
		{
			data->angle_z -= (nowx / data->dpi) - mousex;
			data->moved = true;
		}
		else
		{
			mousex = 0;
			mousey = 0;
		}
	}
}

void	resize(int width, int height, void *param)
{
	t_data	*data;

	data = param;
	data->size.width = width;
	data->size.height = height;
	data->size.center.red = (data->size.width - 300) / 2;
	data->size.center.green = data->size.height / 2;
	data->moved = true;
}

void	wasdqe(mlx_key_data_t code, t_data *data)
{
	if (code.key == MLX_KEY_W && (code.action == 1 || code.action == 2))
		data->zoom++;
	else if (code.key == MLX_KEY_S && (code.action == 1 || code.action == 2))
	{
		if (data->zoom - 1 > 0)
			data->zoom--;
	}
	else if (code.key == MLX_KEY_A && (code.action == 1 || code.action == 2))
		data->size.center.red -= 10;
	else if (code.key == MLX_KEY_D && (code.action == 1 || code.action == 2))
		data->size.center.red += 10;
	else if (code.key == MLX_KEY_Q && (code.action == 1 || code.action == 2))
		data->size.center.green -= 10;
	else if (code.key == MLX_KEY_E && (code.action == 1 || code.action == 2))
		data->size.center.green += 10;
}
