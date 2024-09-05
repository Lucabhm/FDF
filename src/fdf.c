/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/05 12:53:00 by lbohm            ###   ########.fr       */
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
	mlx_terminate(data->window);
	free_all(data);
	return (0);
}

void	error(char *msg, t_data *data)
{
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
		if (data->size)
			free(data->size);
		free(data);
	}
}
