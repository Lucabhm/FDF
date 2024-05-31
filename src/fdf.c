/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:08:07 by lucabohn          #+#    #+#             */
/*   Updated: 2024/05/31 16:21:34 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int argc, char **argv)
{
	if (argc)
	{
		fprintf(stderr, "Hallo\n");
		fprintf(stderr, "argv[0] = %s\n", argv[1]);
	}
	return (0);
}
