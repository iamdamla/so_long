/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:03:42 by derblang          #+#    #+#             */
/*   Updated: 2023/06/02 10:13:02 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_walls(char **map)
{
	int	i;
	int	j;
	int	line;

	line = ft_strlen(map[0]) - 1;
	i = 0;
	j = -1;
	while (map[0][++j])
	{
		if (map[0][j] != '1')
			return (0);
	}
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][line] != '1')
			return (0);
	}
	j = -1;
	i--;
	while (map[i][++j])
	{
		if (map[i][j] != '1')
			return (0);
	}
	return (1);
}

void	ft_prop_init(t_game *sl)
{
	sl->coin = 0;
	sl->nb_coin = 0;
	sl->exit = 0;
	sl->start_pos = 0;
	sl->enemy = 0;
}

int	ft_prop_counter(char **map)
{
	int		i;
	int		j;
	t_game	sl;

	i = 0;
	j = 0;
	ft_prop_init(&sl);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				sl.coin++;
			else if (map[i][j] == 'E')
				sl.exit++;
			else if (map[i][j] == 'P')
				sl.start_pos++;
			j++;
		}
		j = 0;
		i++;
	}
	if (sl.coin < 1 || sl.exit != 1 || sl.start_pos != 1)
		ft_puterror("Prop Error!");
	return (sl.coin);
}

int	ft_map_parser(char **map)
{
	int		i;
	size_t	line;

	line = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != line)
		{
			ft_puterror("The map is not valid!");
			return (0);
		}
		i++;
	}
	if (ft_prop_counter(map) && ft_check_walls(map))
		return (1);
	else
		ft_puterror("The map isn't valid!");
	return (0);
}

char	**ft_map_reader(char *filename)
{
	char	**arr;
	char	*buf;
	char	*temp;
	int		fd;
	int		i;

	fd = ft_open_fd(filename);
	i = 0;
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	temp = buf;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		buf = ft_strjoin(buf, temp);
		free(temp);
	}
	arr = ft_split(buf, '\n');
	free(buf);
	close(fd);
	return (arr);
}
