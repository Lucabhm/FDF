/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:57:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/08/01 20:51:14 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = initData();
	parsing(argc, argv, data);
	drawMenu(data);
	drawMap(data);
	mlx_loop_hook(data->window, controll, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	freeAll(data);
	return (0);
}

void	error(char *msg, t_data *data)
{
	freeAll(data);
	ft_putstr_fd(msg, 2);
	exit (1);
}

void	freeDp(char **arr)
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
