/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/02 12:40:56 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = init_data();
	parsing(argc, argv, data);
	draw_menu(data);
	draw_map(data);
	mlx_loop_hook(data->window, controll, data);
	mlx_loop(data->window);
	if (data->window && data->menu[0])
		delete_img(data);
	mlx_terminate(data->window);
	free_all(data);
	return (0);
}

void	error(char *msg, t_data *data)
{
	if (data->window && data->menu[0])
		delete_img(data);
	if (data->window && data->img_map)
		mlx_delete_image(data->window, data->img_map);
	if (data->window)
	{
		mlx_close_window(data->window);
		mlx_terminate(data->window);
	}
	free_all(data);
	ft_putstr_fd(msg, 2);
	exit (1);
}

void	free_dp(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->default_map)
			free(data->default_map);
		if (data->map)
			free(data->map);
		if (data->size)
			free(data->size);
		free(data);
	}
}
