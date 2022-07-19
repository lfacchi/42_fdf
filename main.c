/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:55:04 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/18 23:49:08 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int max(int a, int b)
{
	if (a > b)
		return(a);
	else
	{
		return(b);
	}
}

void basenham(t_session *id, int xi, int yi, int xf, int yf)
{


	float dx;
	float dy;
	float x;
	float y;
	float inc;
	dx = xf - xi; // 100 - 50 = 50
	dy = yf - yi;	// 200 - 30 = 170
	// int xi = 200;
	// int  yi = 200;
	// int xf = 500; 
	// int yf  = 900;

	dx = xf - xi;
	dy = yf - yi;	
	printf("dx: %f - dx:%f\n", dx , dy);
	if (dx > dy)
	{
		inc = fabs(yf - yi)/fabs(xf - xi);
		y = (float)yi;
		while (xi < xf)
		{
			mlx_pixel_put(id->init ,id->window, xi, floor(y) ,0xf8f8ff);
			y += inc;
			printf("incdy%d - %f  - ", xi, y);
			printf("%f\n", inc);
			xi++;
		}
		return;
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
			printf("incdx:%f - %d - ", x, yi);
			printf("%f\n", inc);
			
		}
		
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int 	width = 1021;
	int 	height = 621;
	int row;
	int col;
	char *str;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "EAE GOSTOSAS");
	t_session t_session1;
	t_session1.init = mlx;
	t_session1.window = mlx_win;
	basenham(&t_session1,50 , 30, 900 ,500);
	
	mlx_loop(mlx);
}
