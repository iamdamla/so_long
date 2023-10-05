/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:52:10 by derblang          #+#    #+#             */
/*   Updated: 2023/06/05 10:18:30 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collectible(void *param)
{
	t_game	*sl;
	int		i;

	i = 0;
	sl = param;
	if (sl->map[(sl->img.img_hero->instances[0].y)
			/ 64][(sl->img.img_hero->instances[0].x) / 64] == 'C')
	{
		sl->coin -= 1;
		while (i < sl->nb_coin)
		{
			if (sl->img.img_coin->instances[i].y
				== sl->img.img_hero->instances[0].y
				&& sl->img.img_coin->instances[i].x
				== sl->img.img_hero->instances[0].x)
			{
				sl->img.img_coin->instances[i].enabled = false;
			}
			i++;
		}
		sl->map[(sl->img.img_hero->instances[0].y)
			/ 64][(sl->img.img_hero->instances[0].x) / 64] = '0';
	}
}

void	ft_enemy(void *param)
{
	t_game	*sl;

	sl = param;
	if (sl->map[(sl->img.img_hero->instances[0].y)
			/ 64][(sl->img.img_hero->instances[0].x) / 64] == 'M')
	{
		write(1, "You've Lost!", 12);
		ft_delete_img(&sl->img);
		mlx_close_window(sl->mlx);
	}
}

void	ft_game_end(void *param)
{
	t_game	*sl;

	sl = param;
	if (sl->map[(sl->img.img_hero->instances[0].y)
			/ 64][(sl->img.img_hero->instances[0].x) / 64] == 'E'
			&& sl->coin == 0)
	{
		write(1, "\nYou Win!\n", 8);
		ft_delete_img(&sl->img);
		mlx_close_window(sl->mlx);
	}
	else if (sl->map[(sl->img.img_hero->instances[0].y)
			/ 64][(sl->img.img_hero->instances[0].x) / 64] == 'E'
			&& sl->coin != 0)
		mlx_put_string(sl->mlx, "Grab all the coins first", 20, 20);
}
