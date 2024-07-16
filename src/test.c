/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:48:58 by lucabohn          #+#    #+#             */
/*   Updated: 2024/07/16 22:13:09 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	cpy_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->default_map)
	{
		data->default_map = (t_map *)malloc (data->size.dots * sizeof(t_map));
		if (!data->default_map)
			error(ERROR_4, data);
	}
	while (i < data->size.dots)
	{
		data->default_map[i] = data->dots[i];
		i++;
	}
}