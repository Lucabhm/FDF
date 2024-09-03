/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:30 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/03 21:23:02 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	drawMenu(t_data *data)
{
	char	*str;

	data->menu[0] = mlx_put_string(data->window, "Controls", 0, 0);
	data->menu[1] = mlx_put_string(data->window, "Mous left: z,x axis", 0, 20);
	data->menu[2] = mlx_put_string(data->window, "Mous wheel: zoom", 0, 40);
	data->menu[3] = mlx_put_string(data->window, \
	"Mouse sensitivity: +,-", 0, 60);
	data->menu[4] = mlx_put_string(data->window, "Reset: R", 0, 80);
	data->menu[5] = mlx_put_string(data->window, "Isometric: I", 0, 100);
	data->menu[6] = mlx_put_string(data->window, "Close Window: ESC", 0, 120);
	data->menu[7] = mlx_put_string(data->window, \
	"------------------------------", 0, 140);
	data->menu[8] = mlx_put_string(data->window, "Stats", 0, 160);
	str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
	data->menu[9] = mlx_put_string(data->window, str, 0, 180);
	free(str);
}

void	deleteImg(t_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		mlx_delete_image(data->window, data->menu[i]);
		i++;
	}
}
