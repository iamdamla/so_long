/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:40:08 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/08/07 15:16:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game *sl)
{
	ft_new_img(sl);
	ft_put_background(sl);
	ft_put_img(sl);
	sl->nb_steps = 1;
}

int	main(int argc, char **argv)
{
	t_game		sl;
	t_vector	begin;

	check_args(argc);
	check_file_extension(argv[1]);
	sl.map = ft_map_reader(argv[1]);
	if (!sl.map || !ft_map_parser(sl.map))
		ft_puterror("Error!");
	sl.coin = ft_prop_counter(sl.map);
	sl.nb_coin = sl.coin;
	sl.size = calc_window_size(sl.map);
	begin = find_p(sl.map);
	sl.map_fill = dup_map(sl.map, sl.size.y, sl.size.x);
	flood_fill(sl.map_fill, begin, sl.size.x, sl.size.y);
	check_map_error(sl.map_fill);
	sl.mlx = mlx_init(sl.size.x, sl.size.y, "HARRY POTTER!", true);
	game_init(&sl);
	mlx_key_hook(sl.mlx, ft_move, &sl);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	return (0);
}
