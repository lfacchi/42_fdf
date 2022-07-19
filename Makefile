# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 18:16:11 by lucdos-s          #+#    #+#              #
#    Updated: 2022/07/18 23:44:18 by lucdos-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	@gcc main.c draw.c events.c -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -lXext -lX11 -lm
	@./a.out