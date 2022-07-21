/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:00:03 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/20 22:14:24 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void basenham(t_session *id, int xi, int yi, int xf, int yf)
{
	float dx;
	float dy;
	float x;
	float y;
	float inc;
	dx = xf - xi; 
	dy = yf - yi;
	if (dx > dy)
	{
		inc = fabs(yf - yi)/fabs(xf - xi);
		y = (float)yi;
		while (xi < xf)
		{
			mlx_pixel_put(id->init ,id->window, xi, floor(y) ,0xf8f8ff);
			y += inc;
			xi++;
		}
	}
	else
	{
		inc = fabs(xf - xi)/fabs(yf - yi);
		x = (float)xi;
		while (yi < yf)		
		{
			mlx_pixel_put(id->init ,id->window, floor(x), yi ,0xf8f8ff);
			yi++;
			x = x + inc;
		}
	}
}

void draw_map(int fd, int space, t_session *id)
{
	int row;
	int col;
	int x_init;
	int y_init;
	int  n_line;
	char *line;
	char **split_line;
	int val;
	
	line = "";
	n_line = 0;
	y_init = 100;
	val = 0;
	while (line != NULL)
	{
		x_init = 300;
		col = 0;
		line = get_next_line(fd);
		if (line != NULL)
			split_line = ft_split(line, ' ');
		if(line == NULL)
			val = 1;
		while (split_line[col])
		{
			basenham(id ,x_init ,y_init , (x_init + space) , y_init);
			if(!val)
				basenham(id ,x_init ,y_init , x_init , (y_init + space));
			x_init += space;
			col++;
		}
		if(!val)
			basenham(id ,x_init ,y_init , x_init , (y_init + space));
		y_init += space;
		n_line++;
	}
}
int **read_map(int fd, t_session *id)
{
	int		n_line;
	int		col;
	char	*line;
	char	**split_line;
	int		**split_int;
	int 	***map;
	
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			split_line = ft_split(line, ' ');
		split_int = malloc(sizeof(split_line) * 4);
		map = malloc(n_line * col * sizeof(int));
		while (split_line[col])
		{
			split_int[col] = split_line[col];
			col++;
		}
		n_line++;
	}
	return map;
}

