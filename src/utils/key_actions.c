/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/06 10:48:34 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	controll(void *param)
{
	t_data	*data;

	data = param;
	mlx_scroll_hook(data->window, scroll, data);
	mlx_resize_hook(data->window, resize, data);
	cursor(data);
	mlx_key_hook(data->window, key, data);
	if (data->size->moved)
		draw_map_changed(data);
}

void	key(mlx_key_data_t code, void *param)
{
	t_data		*data;

	data = param;
	if (code.key == MLX_KEY_ESCAPE && code.action == 1)
	{
		mlx_close_window(data->window);
		return ;
	}
	else if (code.key == MLX_KEY_I && code.action == 1)
	{
		data->size->angle_z = 45;
		data->size->angle_y = 0;
		data->size->angle_x = atan(sqrt(0.5));
		data->size->projection = false;
		change_projection_img(data);
	}
	set_dpi(code, data);
	reset(code, data);
	wasdqe(code, data);
	key_ortho(code, data);
	z_altitude(code, data);
	data->size->moved = true;
}

void	scroll(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	xdelta = 0;
	if (ydelta > 0 && xdelta == 0)
	{
		data->size->zoom++;
	}
	else if (ydelta < 0)
	{
		if (data->size->zoom - 1 > 0)
			data->size->zoom--;
	}
	data->size->moved = true;
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
		mousex = nowx / data->size->dpi;
		mousey = nowy / data->size->dpi;
	}
	else
	{
		if (mlx_is_mouse_down(data->window, MLX_MOUSE_BUTTON_LEFT))
		{
			data->size->angle_z -= (nowx / data->size->dpi) - mousex;
			data->size->moved = true;
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
	int		i;
	bool	enable;

	data = param;
	i = 0;
	if (width * 0.25 >= 300)
	{
		data->size->ratio = 300;
		enable = true;
	}
	else
	{
		data->size->ratio = 0;
		enable = false;
	}
	while (i < 17)
	{
		data->menu[i]->enabled = enable;
		i++;
	}
	data->size->center.x = (width - data->size->ratio) / 2;
	data->size->center.y = height / 2;
	data->size->moved = true;
}
