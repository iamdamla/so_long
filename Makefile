# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: derblang <derblang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 09:10:49 by derblang          #+#    #+#              #
#    Updated: 2023/05/04 14:07:33 by derblang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= srcs/main.c srcs/map.c srcs/check.c srcs/window.c srcs/image.c \
		  srcs/moves.c  srcs/collectible.c srcs/flood_fill.c

OBJS	= $(SRCS:.c=.o)

INC		= -I /Users/$$USER/Desktop/MLX42/include
MLX		=  "/Users/$$USER/Desktop/MLX42/libmlx42.a" -I include -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib" 
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
		@$(MAKE) -C ./libft
		@gcc $(CFLAGS) $(OBJS) $(MLX) libft/libft.a -o $(NAME)
		
.c.o:
	gcc -Wall -Wextra -Werror -c -I./includes -I libft/includes -I./mlx -I "/Users/$$USER/.brew/opt/glfw/include" $< -o ${<:.c=.o}

debug: $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(MLX) libft/libft.a -g3 -fsanitize=address -o $(NAME)

clean:
		@$(RM) libft.a $(OBJS)
		@$(MAKE) clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		@$(MAKE) fclean -C ./libft
		@$(MAKE) clean -C ./mlx
		@$(RM) libmlx.a $(OBJS)

re: fclean all
