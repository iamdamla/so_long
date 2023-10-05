/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:03:14 by derblang          #+#    #+#             */
/*   Updated: 2023/06/05 11:07:09 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/derblang/Desktop/MLX42/include/MLX42/MLX42.h"
//# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <memory.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct s_image
{
	t_vector		size;
	mlx_texture_t	*wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*hero;
	mlx_image_t		*img_hero;
	mlx_texture_t	*coin;
	mlx_image_t		*img_coin;
	mlx_texture_t	*exit;
	mlx_image_t		*img_exit;
	mlx_texture_t	*sky;
	mlx_image_t		*img_sky;
	mlx_texture_t	*enmy;
	mlx_image_t		*img_enmy;
	mlx_texture_t	*banner;
	mlx_image_t		*img_banner;
	mlx_image_t		*text;
}					t_image;

typedef struct s_game
{
	mlx_t			*mlx;
	t_vector		size;
	t_image			img;
	t_vector		gate;
	char			**map;
	char			**map_fill;
	void			*win;
	int				coin;
	int				exit;
	int				start_pos;
	int				nb_coin;
	int				nb_steps;
	int				score;
	char			*move;
	int				enemy;
	int				h;
	int				l;
}					t_game;

char				**ft_map_reader(char *filename);
void				ft_prop_init(t_game *sl);
void				check_args(char argc);
int					ft_prop_counter(char **map);
int					ft_map_parser(char **map);
char				*unknown_element(char **map, char c);
void				check_file_extension(char *file);
t_vector			calc_window_size(char **map);
void				ft_new_img(t_game *sl);
void				ft_new_img_finish(t_game *sl);
void				ft_put_img_to_map(t_game *sl, int l, int h);
void				ft_put_img(t_game *sl);
void				game_init(t_game *sl);
void				ft_move(mlx_key_data_t keydata, void *param);
void				move_right(void *param);
void				check_collectible(void *param);
void				ft_game_end(void *param);
void				ft_enemy(void *param);
void				ft_put_background(t_game *sl);
void				fill(char **map, t_vector cur, int l, int h);
void				flood_fill(char **map, t_vector begin, int l, int h);
t_vector			find_p(char **map);
void				check_map_error(char **map);
char				**dup_map(char **map, int x, int y);
int					ft_open_fd(char *filename);
void				ft_delete_img(t_image *img);

#endif
