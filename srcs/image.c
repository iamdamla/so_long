/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:03:29 by derblang          #+#    #+#             */
/*   Updated: 2023/06/05 11:06:52 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_new_img(t_game *sl)
{
	sl->img.sky = mlx_load_png("/Users/derblang/Desktop/so_long/img/color.png");
	sl->img.wall = mlx_load_png("/Users/derblang/Desktop/so_long/img/wall.png");
	sl->img.coin = mlx_load_png("/Users/derblang/Desktop/so_long/img/coin.png");
	sl->img.exit = mlx_load_png("/Users/derblang/Desktop/so_long/img/exit.png");
	sl->img.hero = mlx_load_png("/Users/derblang/Desktop/so_long/img/hero.png");
	sl->img.enmy = mlx_load_png("/Users/derblang/Desktop/so_long/img/enmy.png");
	if (!(sl->img.wall) || !(sl->img.hero) || !(sl->img.coin)
		|| !(sl->img.exit) || !(sl->img.enmy) || !(sl->img.img_sky))
		ft_puterror("Image doesn't exist");
	ft_new_img_finish(sl);
}

void	ft_new_img_finish(t_game *sl)
{
	sl->img.img_sky = mlx_texture_to_image(sl->mlx, sl->img.sky);
	sl->img.img_wall = mlx_texture_to_image(sl->mlx, sl->img.wall);
	sl->img.img_coin = mlx_texture_to_image(sl->mlx, sl->img.coin);
	sl->img.img_exit = mlx_texture_to_image(sl->mlx, sl->img.exit);
	sl->img.img_hero = mlx_texture_to_image(sl->mlx, sl->img.hero);
	sl->img.img_enmy = mlx_texture_to_image(sl->mlx, sl->img.enmy);
	if (!(sl->img.img_wall) || !(sl->img.img_hero) || !(sl->img.img_coin)
		|| !(sl->img.img_exit) || !(sl->img.img_enmy) || !(sl->img.img_sky))
		ft_puterror("Image doesn't exist");
}

void	ft_put_background(t_game *sl)
{
	int	h;
	int	l;

	h = 0;
	while (h < sl->size.y / 64)
	{
		l = 0;
		while (l < sl->size.x / 64)
		{
			mlx_image_to_window(sl->mlx, sl->img.img_sky, l * 64, h * 64);
			l++;
		}
		h++;
	}
}

void	ft_put_img(t_game *sl)
{
	int	h;
	int	l;

	h = 0;
	while (h < sl->size.x / 64)
	{
		l = 0;
		while (l < sl->size.y / 64)
		{
			ft_put_img_to_map(sl, l, h);
			l++;
		}
		h++;
	}
}

void	ft_put_img_to_map(t_game *sl, int h, int l)
{
	if (sl->map[h][l] == '1')
		mlx_image_to_window(sl->mlx, sl->img.img_wall, l * 64, h * 64);
	else if (sl->map[h][l] == 'C')
		mlx_image_to_window(sl->mlx, sl->img.img_coin, l * 64, h * 64);
	else if (sl->map[h][l] == 'E')
		mlx_image_to_window(sl->mlx, sl->img.img_exit, l * 64, h * 64);
	else if (sl->map[h][l] == 'M')
		mlx_image_to_window(sl->mlx, sl->img.img_enmy, l * 64, h * 64);
	else if (sl->map[h][l] == 'P')
		mlx_image_to_window(sl->mlx, sl->img.img_hero, l * 64, h * 64);
	else if (sl->map[h][l] == '0')
		;
	else
		ft_puterror("Image Error");
}
