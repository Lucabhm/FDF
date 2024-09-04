/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:30 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/04 22:15:37 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_menu(t_data *data)
{
	char	*str;

	data->menu[0] = mlx_put_string(data->window, "Controls", 0, 0);
	data->menu[1] = mlx_put_string(data->window, "Mous left: z axis", 0, 40);
	data->menu[2] = mlx_put_string(data->window, "Zoom In / Out:", 0, 65);
	data->menu[3] = mlx_put_string(data->window, "W, Mous wheel / S, Mous wheel", 0, 90);
	data->menu[4] = mlx_put_string(data->window, \
	"Mouse sensitivity: +,-", 0, 115);
	data->menu[5] = mlx_put_string(data->window, "Reset: R", 0, 140);
	data->menu[6] = mlx_put_string(data->window, "Isometric: I", 0, 165);
	data->menu[7] = mlx_put_string(data->window, "Move X axis: A / D", 0, 190);
	data->menu[8] = mlx_put_string(data->window, "Move Y axis: Q / E", 0, 215);
	data->menu[9] = mlx_put_string(data->window, "Close Window: ESC", 0, 240);
	data->menu[10] = mlx_put_string(data->window, \
	"------------------------------", 0, 280);
	data->menu[11] = mlx_put_string(data->window, "Stats", 0, 320);
	str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
	data->menu[12] = mlx_put_string(data->window, str, 0, 345);
	free(str);
	str = "Projection: Isometric";
	data->menu[13] = mlx_put_string(data->window, str, 0, 370);
}

void	delete_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		mlx_delete_image(data->window, data->menu[i]);
		i++;
	}
}

void	change_mouse_img(t_data *data)
{
	char	*str;

	mlx_delete_image(data->window, data->menu[12]);
	str = ft_strjoin("Mouse sensitivity: ", ft_itoa(data->dpi));
	data->menu[12] = mlx_put_string(data->window, str, 0, 345);
	free(str);
}

void	change_projection_img(t_data *data)
{
	char	*str;

	mlx_delete_image(data->window, data->menu[13]);
	if (!data->projection)
		str = "Projection: Isometric";
	else
		str = "Projection: Parallel";
	data->menu[13] = mlx_put_string(data->window, str, 0, 370);
}