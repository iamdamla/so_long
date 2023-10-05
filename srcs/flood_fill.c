/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:14:54 by derblang          #+#    #+#             */
/*   Updated: 2023/05/08 12:45:48 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(char **map, t_vector cur, int l, int h)
{
	t_vector	size;

	size.x = l;
	size.y = h;
	if ((map[cur.x][cur.y] != 'P' && map[cur.x][cur.y] != '0'
			&& map[cur.x][cur.y] != 'C' && map[cur.x][cur.y] != 'E') ||
		cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	map[cur.x][cur.y] = 'F';
	fill(map, (t_vector){cur.x - 1, cur.y}, l, h);
	fill(map, (t_vector){cur.x + 1, cur.y}, l, h);
	fill(map, (t_vector){cur.x, cur.y - 1}, l, h);
	fill(map, (t_vector){cur.x, cur.y + 1}, l, h);
}

void	flood_fill(char **map, t_vector begin, int l, int h)
{
	t_vector	size;

	size.x = l;
	size.y = h;
	fill(map, begin, l, h);
}

t_vector	find_p(char **map)
{
	int			i;
	int			j;
	t_vector	begin;

	i = 1;
	j = 0;
	begin.x = 0;
	begin.y = 0;
	while (map[i])
	{
		while (map[i][j] != 'P' && map[i][j])
		{
			if (map[i][j + 1] == 'P' && map[i][j])
			{
				begin.x = i;
				begin.y = j + 1;
				return (begin);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (begin);
}

void	check_map_error(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C')
			{
				ft_puterror("There is no valid road in the game!");
			}
			j++;
		}
		i++;
		j = 0;
	}
}

char	**dup_map(char **map, int x, int y)
{
	int			i;
	int			j;
	char		**map_dup;
	t_vector	size;

	i = 0;
	j = 0;
	x = size.x;
	y = size.y;
	map_dup = ft_calloc(sizeof(char *), x + 1);
	while (map[i])
	{
		map_dup[i] = ft_calloc(sizeof(char), y + 1);
		while (map[i][j])
		{
			map_dup[i][j] = map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (map_dup);
}
