# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 18:16:11 by lucdos-s          #+#    #+#              #
#    Updated: 2022/07/20 19:41:04 by lucdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	@clear
	@gcc main.c draw.c events.c -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -lXext -lX11 -lm 42_libft/libft.a
	@./a.out