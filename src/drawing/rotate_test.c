/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:36:45 by lucabohn          #+#    #+#             */
/*   Updated: 2024/12/04 21:33:26 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	get_full_r(float result[3][3], float x, float y, float z)
{
	float	mx[3][3];
	float	my[3][3];
	float	mz[3][3];
	float	tmp[3][3];

	z = (((int)z % 360) + 360) % 360;
	z = z / 360;
	z = ((z * 2) - 1) * 180;
	// x = x * (M_PI / 180);
	y = y * (M_PI / 180);
	z = z * (M_PI / 180);
	rotate_x(mx, x);
	rotate_y(my, y);
	rotate_z(mz, z);
	multi_m(tmp, mx, my);
	multi_m(result, tmp, mz);
}

void	rotate_x(float m[3][3], float angle)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cos(angle);
	m[1][2] = -sin(angle);
	m[2][0] = 0;
	m[2][1] = sin(angle);
	m[2][2] = cos(angle);
}

void	rotate_y(float m[3][3], float angle)
{
	m[0][0] = cos(angle);
	m[0][1] = 0;
	m[0][2] = sin(angle);
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = -sin(angle);
	m[2][1] = 0;
	m[2][2] = cos(angle);
}

void	rotate_z(float m[3][3], float angle)
{
	m[0][0] = cos(angle);
	m[0][1] = -sin(angle);
	m[0][2] = 0;
	m[1][0] = sin(angle);
	m[1][1] = cos(angle);
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}

void	multi_m(float result[3][3], float m1[3][3], float m2[3][3])
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			result[i][j] = 0;
			result[i][j] += m1[i][0] * m2[0][j]
				+ m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j];
			j++;
		}
		i++;
	}
}

t_vec	r_vec(float m[3][3], t_vec v)
{
	t_vec	result;

	result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
	result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
	result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;
	return (result);
}