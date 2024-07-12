/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/12 16:26:53 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	controll(void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	printf("zoom = %i\n", data->zoom);
// 	mlx_scroll_hook(data->window, scroll, data);
// }

// void	key(mlx_key_data_t code, void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	if (code.key == MLX_KEY_ESCAPE && code.action == 1)
// 		mlx_close_window(data->window);
// }

// void	scroll(double xdelta, double ydelta, void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	xdelta = 0;
// 	if (ydelta > 0)
// 	{
// 		data->zoom++;
// 		// printf("zoom = %i\n", data->zoom);
// 		add_zoom(*data);
// 		rotate(*data);
// 		draw_loop(*data);
// 		reset_check(data);
// 	}
// 	else if (ydelta < 0)
// 	{
// 		data->zoom--;
// 		// printf("zoom = %i\n", data->zoom);
// 		add_zoom(*data);
// 		draw_loop(*data);
// 		reset_check(data);
// 	}
// }
