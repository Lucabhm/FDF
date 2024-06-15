/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:07:47 by lucabohn          #+#    #+#             */
/*   Updated: 2024/06/16 00:12:00 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/ft_libft/libft.h";
# include "../lib/ft_printf/ft_printf.h";
# include "../lib/ft_get_next_line/get_next_line.h";

// struct
typedef struct	s_data
{
	char	**map;
}				t_data;

// error msg

# define ERROR_0 "Wrong nbr of Arrguments!\n"
# define ERROR_1 "Open failed\n"


#endif