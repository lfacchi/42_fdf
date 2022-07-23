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

void draw_map(t_session *id)
{
	int col;
	int x_init;
	int y_init;
	int  row;
	char *line;
	char **split_line;
	int val;
	
	line = "";
	row = 0;
	y_init = id->map.y_init;
	val = 0;
	while (row <= id->rdmap.row)
	{
		x_init = id->map.x_init;
		col = 0;
		while (col < id->rdmap.col)
		{
			basenham(id ,x_init ,y_init , (x_init + id->map.space) , y_init);
			if(!val)
				basenham(id ,x_init ,y_init , x_init , (y_init + id->map.space));
			x_init += id->map.space;
			col++;
		}
		if(!val)
			basenham(id ,x_init ,y_init , x_init , (y_init + id->map.space));
		y_init += id->map.space;
		row++;
		if(row == id->rdmap.row)
			val = 1;
	}
}

t_rdmap read_map(t_session *id)
{
	t_rdmap rdmap;
	int i;

	rdmap.line = "";
	rdmap.row = 0;
	id->map.fd = open(id->map.path, O_RDONLY);
	while (rdmap.line != NULL)
	{
		rdmap.col = 0;
		rdmap.line = get_next_line(id->map.fd);
		
		if (rdmap.line != NULL)
			rdmap.split_line = ft_split(rdmap.line, ' ');
		while (rdmap.split_line[rdmap.col])
		{
			rdmap.col++;
		}
		rdmap.row++;
	}
	close(id->map.fd);
	rdmap.matrix = matrix_allocate(rdmap.row, rdmap.col);
	id->map.fd = open(id->map.path, O_RDONLY);
	rdmap.line = get_next_line(id->map.fd);
	rdmap.split_line = ft_split(rdmap.line, ' ');
	while(rdmap.line != NULL)
	{
		i = 0;
		while (rdmap.split_line[i])
		{
			rdmap.matrix[rdmap.row][i] = ft_atoi(rdmap.split_line[i]);
			i++;
		}
		rdmap.line = get_next_line(id->map.fd);
		if (rdmap.line != NULL)
			rdmap.split_line = ft_split(rdmap.line, ' ');
	}
	return (rdmap);
}

int **matrix_allocate(int x , int y)
{
	int **matrix;
	int xi;

	xi = x;
	matrix  = ft_calloc(x, sizeof(int *));
	while (x > 0)
	{
		matrix[x] = ft_calloc(y ,sizeof(int));
		x--;
	}
	return (matrix);
}

