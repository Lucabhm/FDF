/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateOrtho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:24:49 by lucabohn          #+#    #+#             */
/*   Updated: 2024/08/26 18:07:28 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	initOrtho(t_data *data)
{
	int	i;

	i = 0;
	data->ortho.l = 0;
	data->ortho.r = data->size.x_max;
	data->ortho.b = 0;
	data->ortho.t = data->size.y_max;
	data->ortho.n = 0;
	data->ortho.f = 0;
	while (i < data->size.dots)
	{
		if (data->map[i].z <= data->ortho.n)
			data->ortho.n = data->map[i].z;
		if (data->map[i].z >= data->ortho.f)
			data->ortho.f = data->map[i].z;
		i++;
	}
	// printf("l = %i r = %i b = %i t = %i n = %i f = %i\n", data->ortho.l, data->ortho.r, data->ortho.b, data->ortho.t, data->ortho.n, data->ortho.f);
}

void	rotateOrtho(t_data *data)
{
	int	i;
	float	rl;
	float	rl2;
	float	tb;
	float	tb2;
	float	fn;
	float	fn2;

	i = 0;
	rl = 2.0 / (data->ortho.r - data->ortho.l);
	rl2 = (data->ortho.r + data->ortho.l) / (data->ortho.r - data->ortho.l);
	tb = 2.0 / (data->ortho.t - data->ortho.b);
	tb2 = (data->ortho.t + data->ortho.b) / (data->ortho.t - data->ortho.b);
	fn = 2.0 / (data->ortho.f - data->ortho.n);
	fn2 = (data->ortho.f + data->ortho.n) / (data->ortho.f - data->ortho.n);
	while (i < data->size.dots)
	{
		data->map[i].x = (rl * data->map[i].x) - rl2;
		data->map[i].y = (tb * data->map[i].y) - tb2;
		data->map[i].z = -(fn * data->map[i].z) - fn2;
		// printf("x = %i y = %i z = %i\n", data->map[i].x, data->map[i].y, data->map[i].z);
		i++;
	}
}
