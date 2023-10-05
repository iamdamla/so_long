/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:47:33 by derblang          #+#    #+#             */
/*   Updated: 2023/06/05 11:06:22 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args(char argc)
{
	if (argc != 2)
		ft_puterror("Put only 2 arguments!");
}

static int	ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
	{
		return (0);
	}
}

void	check_file_extension(char *file)
{
	while (*file)
	{
		if (*file == '.')
		{
			if (ft_strstr(file, ".ber"))
				return ;
		}
		file++;
	}
	ft_puterror("Map extension is wrong!");
	exit(1);
}

int	ft_open_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File doesn't exist!");
		exit(0);
	}
	return (fd);
}

void	ft_delete_img(t_image *img)
{
	mlx_delete_texture(img->sky);
	mlx_delete_texture(img->wall);
	mlx_delete_texture(img->coin);
	mlx_delete_texture(img->exit);
	mlx_delete_texture(img->hero);
	mlx_delete_texture(img->enmy);
}
