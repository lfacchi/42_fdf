/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:00:03 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/15 18:29:36 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void create_ver(int x_init, int y_init, int y_final, void *id, void *wnd)
{
	while(y_init < y_final)
	{
		mlx_pixel_put(id, wnd, x_init,y_init, 0xf8f8ff);
		y_init++;
	}
}

void create_hor(int x_init, int y_init, int x_final, void *id, void *wnd)
{
	while (x_init < x_final)
	{
		mlx_pixel_put(id, wnd, x_init, y_init, 0xf8f8ff);
		x_init++;
	}
}

void t_create_square(t_square sq, void *id, void *wnd)
{
	create_hor(sq.x_init, sq.y_init, (sq.x_init + sq.side),id,wnd);
	create_hor(sq.x_init,(sq.y_init + sq.side),(sq.x_init + sq.side),id,wnd);
	create_ver(sq.x_init, sq.y_init, (sq.y_init + sq.side),id,wnd);
	create_ver((sq.x_init + sq.side), sq.y_init, (sq.y_init + sq.side),id,wnd);
}

void create_matrix(t_square sq,int n_row,int n_col, void *id, void *wnd)
{
	int base = sq.x_init;
	int i = 0;
	int j = 0;

	while (i < n_row)
	{
		while (j < n_col)
		{
			t_create_square(sq, id, wnd);
			sq.x_init += sq.side;
			j++;
		}
		sq.y_init += sq.side;
		sq.x_init = base;
		j = 0;
		i++;
	}
}
