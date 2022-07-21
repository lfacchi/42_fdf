/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:00:03 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/21 08:10:50 by lucdos-s         ###   ########.fr       */
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

void draw_map(t_map map, t_session *id)
{
	int col;
	int x_init;
	int y_init;
	int  n_line;
	char *line;
	char **split_line;
	int val;
	
	line = "";
	n_line = 0;
	y_init = map.y_init;
	val = 0;
	while (line != NULL)
	{
		x_init = map.x_init;
		col = 0;
		line = get_next_line(map.fd);
		if (line != NULL)
			split_line = ft_split(line, ' ');
		if(line == NULL)
			val = 1;
		while (split_line[col])
		{
			basenham(id ,x_init ,y_init , (x_init + map.space) , y_init);
			if(!val)
				basenham(id ,x_init ,y_init , x_init , (y_init + map.space));
			x_init += map.space;
			col++;
		}
		if(!val)
			basenham(id ,x_init ,y_init , x_init , (y_init + map.space));
		y_init += map.space;
		n_line++;
	}
}
void resize_map(int fd, t_session *id)
{
	mlx_clear_window(id->init, id->window);
	
}