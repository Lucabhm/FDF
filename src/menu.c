/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:30 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/19 14:50:51 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_menu(t_data *data)
{
	char	*str;

	data->str[0] = mlx_put_string(data->window, "Controls", 0, 0);
	data->str[1] = mlx_put_string(data->window, "Mous left: z,x axis", 0, 20);
	data->str[2] = mlx_put_string(data->window, "Mous wheel: zoom", 0, 40);
	data->str[3] = mlx_put_string(data->window, "Mouse sensitivity: +,-", 0, 60);
	data->str[4] = mlx_put_string(data->window, "Reset: R", 0, 80);
	data->str[5] = mlx_put_string(data->window, "Isometric: I", 0, 100);
	data->str[6] = mlx_put_string(data->window, "------------------------------", 0, 120);
	data->str[7] = mlx_put_string(data->window, "Stats", 0, 140);
	str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
	data->str[8] = mlx_put_string(data->window, str, 0, 160);
	free(str);
}

void	delete_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		mlx_delete_image(data->window, data->str[i]);
		i++;
	}
}
