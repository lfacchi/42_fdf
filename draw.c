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
	while (line != NULL)
	{
		x_init = id->map.x_init;
		col = 0;
		line = get_next_line(id->map.fd);
		if (line != NULL)
			split_line = ft_split(line, ' ');
		if(line == NULL)
			val = 1;
		while (split_line[col])
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
	}
}

int **read_map(t_session *id)
{
	t_rdmap rdmap;
	
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
			rdmap.col++;
		rdmap.row++;
	}
	close(id->map.fd);
	rdmap.matrix = matrix_allocate(rdmap.row, rdmap.col);
	id->map.fd = open(id->map.path, O_RDONLY);
	rdmap.row = 0;
	while (rdmap.line != NULL)
	{
		rdmap.col = 0;
		rdmap.line = get_next_line(id->map.fd);
		if (rdmap.line != NULL)
		{
			rdmap.split_line = ft_split(rdmap.line, ' ');
			while (rdmap.split_line[rdmap.col])
			{
				rdmap.matrix[rdmap.row][rdmap.col] = ft_atoi(rdmap.split_line[rdmap.col]);
				rdmap.col++;
			}
			rdmap.row++;
		}
	}
	return (rdmap.matrix);
}

int **matrix_allocate(int x , int y)
{
	int **matrix;

	matrix  = ft_calloc(x, sizeof(int *));
	while (x > 0)
	{
		matrix[x] = ft_calloc(y ,sizeof(int));
		x--;
	}
	return (matrix);
}

void print_matrix(int **matrix)
{
	int i = 0;
	int j;

	while(matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			printf("- %d -",matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}