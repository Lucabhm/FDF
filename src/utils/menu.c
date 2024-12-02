/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:30 by lbohm             #+#    #+#             */
/*   Updated: 2024/12/02 21:02:17 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	draw_menu(t_data *data)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	draw_menu_2(data);
	data->menu[12] = mlx_put_string(data->window, "Stats", 0, 325);
	tmp = ft_itoa(data->size->dpi);
	str = ft_strjoin("Mouse sensitivity: ", tmp);
	free(tmp);
	data->menu[13] = mlx_put_string(data->window, str, 10, 350);
	free(str);
	str = "Projection: Isometric";
	data->menu[14] = mlx_put_string(data->window, str, 10, 375);
	data->menu[15] = mlx_put_string(data->window, "Image center:", 10, 400);
	tmp = ft_itoa(data->size->center.x);
	str = ft_strjoin("x = ", tmp);
	free(tmp);
	tmp = ft_strjoin(str, ", y = ");
	free(str);
	tmp2 = ft_itoa(data->size->center.y);
	str = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp);
	data->menu[16] = mlx_put_string(data->window, str, 10, 425);
	free(str);
}

void	draw_menu_2(t_data *data)
{
	data->menu[0] = mlx_put_string(data->window, "Controls", 0, 0);
	data->menu[1] = mlx_put_string(data->window, "Mous left: z axis", 10, 40);
	data->menu[2] = mlx_put_string(data->window, "Zoom In / Out:", 10, 65);
	data->menu[3] = mlx_put_string(
			data->window, "W, Mous wheel / S, Mous wheel", 10, 90);
	data->menu[4] = mlx_put_string(
			data->window, "Mouse sensitivity: +,-", 10, 115);
	data->menu[5] = mlx_put_string(data->window, "Reset: R", 10, 140);
	data->menu[6] = mlx_put_string(data->window, "Isometric: I", 10, 165);
	data->menu[7] = mlx_put_string(data->window, "Move X axis: A / D", 10, 190);
	data->menu[8] = mlx_put_string(data->window, "Move Y axis: Q / E", 10, 215);
	data->menu[9] = mlx_put_string(data->window, "Z altitude: 1 / 3", 10, 240);
	data->menu[10] = mlx_put_string(data->window, "Close Window: ESC", 10, 265);
	data->menu[11] = mlx_put_string(
			data->window, "------------------------------", 0, 305);
}

void	delete_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		mlx_delete_image(data->window, data->menu[i]);
		i++;
	}
}