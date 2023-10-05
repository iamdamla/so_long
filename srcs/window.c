/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:03:57 by derblang          #+#    #+#             */
/*   Updated: 2023/05/08 13:23:32 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vector	calc_window_size(char **map)
{
	t_vector	size;

	size.x = 0;
	size.y = 0;
	while (map[size.y])
	{
		while (map[size.y][size.x])
			size.x++;
		size.y++;
	}
	size.x *= 64;
	size.y *= 64;
	return (size);
}
