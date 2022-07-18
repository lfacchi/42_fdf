/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:55:04 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/16 18:05:24 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void basenham(t_session id, int xi, int yi, int xf, int yf)
{
	int x;
	int y;
	int dx;
	int dy;
	int d;
	int incE;
	int incNE;

	dx = xf - xi;
	dy = yf - yi;
	d = 2 * dy - dx;
	incE = 2 * dy;
	incNE = 2 * (dy - dx);
	x = xi;
	y = yi;
	mlx_pixel_put(id.init, id.window ,x, y,0xf8f8ff );
	while (xi < xf)
	{
		if (d <= 0)
		{
			d += incE;
			xi++;
		}
		else
		{
			d += incNE;
			xi++;
			yi++;
		}
		mlx_pixel_put(id.init, id.window ,xi, yi, 0xf8f8ff);
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
	t_session t_session1;
	t_session1.init = mlx;
	t_session1.window = mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "EAE GOSTOSAS");	
	basenham(t_session1, 200,200, 500, 900);
	mlx_loop(mlx);
}
