/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:48:58 by lucabohn          #+#    #+#             */
/*   Updated: 2024/08/01 20:39:08 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	freeAll(t_data *data)
{
	if (data)
	{
		if (data->default_map)
			free(data->default_map);
		free(data);
	}
}
