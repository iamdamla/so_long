/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:35:12 by derblang          #+#    #+#             */
/*   Updated: 2023/06/05 10:17:10 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(void *param)
{
	t_game	*sl;
	char	*str;

	sl = param;
	if (mlx_is_key_down(sl->mlx, MLX_KEY_D))
	{
		if (sl->map[(sl->img.img_hero->instances[0].y)
				/ 64][(sl->img.img_hero->instances[0].x + 1 * 64) / 64] != '1')
		{
			mlx_delete_image(sl->mlx, sl->img.text);
			ft_putnbr_fd(sl->nb_steps, 1);
			write(1, " STEPS\n", 7);
			sl->img.img_hero->instances[0].x += 1 * 64;
			str = ft_itoa(sl->nb_steps++);
			sl->move = ft_strjoin(str, " NB STEPS\n");
			sl->img.text = mlx_put_string(sl->mlx, sl->move, 0, 0);
			free(sl->move);
		}
	}
}

void	move_left(void *param)
{
	t_game	*sl;
	char	*str;

	sl = param;
	if (mlx_is_key_down(sl->mlx, MLX_KEY_A))
	{
		if (sl->map[(sl->img.img_hero->instances[0].y)
				/ 64][(sl->img.img_hero->instances[0].x - 1 * 64) / 64] != '1')
		{
			mlx_delete_image(sl->mlx, sl->img.text);
			ft_putnbr_fd(sl->nb_steps, 1);
			write(1, " STEPS\n", 7);
			sl->img.img_hero->instances[0].x -= 1 * 64;
			str = ft_itoa(sl->nb_steps++);
			sl->move = ft_strjoin(str, " NB STEPS\n");
			sl->img.text = mlx_put_string(sl->mlx, sl->move, 0, 0);
			free(sl->move);
		}
	}
}

void	move_up(void *param)
{
	t_game	*sl;
	char	*str;

	sl = param;
	if (mlx_is_key_down(sl->mlx, MLX_KEY_W))
	{
		if (sl->map[(sl->img.img_hero->instances[0].y - 1 * 64)
				/ 64][(sl->img.img_hero->instances[0].x) / 64] != '1')
		{
			mlx_delete_image(sl->mlx, sl->img.text);
			ft_putnbr_fd(sl->nb_steps, 1);
			write(1, " STEPS\n", 7);
			sl->img.img_hero->instances[0].y -= 1 * 64;
			str = ft_itoa(sl->nb_steps++);
			sl->move = ft_strjoin(str, " NB STEPS\n");
			sl->img.text = mlx_put_string(sl->mlx, sl->move, 0, 0);
			free(sl->move);
		}
	}
}

void	move_down(void *param)
{
	t_game	*sl;
	char	*str;

	sl = param;
	if (mlx_is_key_down(sl->mlx, MLX_KEY_S))
	{
		if (sl->map[(sl->img.img_hero->instances[0].y + 1 * 64)
				/ 64][(sl->img.img_hero->instances[0].x) / 64] != '1')
		{
			mlx_delete_image(sl->mlx, sl->img.text);
			ft_putnbr_fd(sl->nb_steps, 1);
			write(1, " STEPS\n", 7);
			sl->img.img_hero->instances[0].y += 1 * 64;
			str = ft_itoa(sl->nb_steps++);
			sl->move = ft_strjoin(str, " NB STEPS\n");
			sl->img.text = mlx_put_string(sl->mlx, sl->move, 0, 0);
			free(sl->move);
		}
	}
}

void	ft_move(mlx_key_data_t keydata, void *param)
{
	t_game	*sl;

	(void)keydata;
	sl = param;
	if (mlx_is_key_down(sl->mlx, MLX_KEY_ESCAPE))
	{
		ft_delete_img(&sl->img);
		mlx_close_window(sl->mlx);
	}
	move_right(sl);
	move_left(sl);
	move_up(sl);
	move_down(sl);
	check_collectible(sl);
	ft_game_end(sl);
	ft_enemy(sl);
}
