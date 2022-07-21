/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:55:04 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/20 20:57:49 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int 	width = 1200;
	int 	height = 600;
	int row;
	int col;
	char *str;
	t_point p1;
	p1.x = 150; 
	p1.y = 150; 
	p1.z = 0; 
	t_point p2;
	p2.x = floor(150 + 500 * 0.7071); 
	p2.y = 150; 
	p2.z = 0; 
	t_point p3;
	p3.x = floor(150 + 500 * 0.7071); 
	p3.y = floor(150 + 500 * 0.7071); 
	p3.z = 0; 
	t_point p4;
	p4.x = 150; 
	p4.y = floor(150 + 500 * 0.7071); 
	p4.z = 0; 
	t_point p5;
	p5.x = p1.x + 500;
	p5.y =  floor(150 + 500 * 0.7071);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "EAE GOSTOSAS");
	t_session t_session1;
	t_session1.init = mlx;
	t_session1.window = mlx_win;
	mlx_key_hook(t_session1.window ,print_key_value , &t_session1);

	int fd = open("test_maps/pylone.fdf", O_RDONLY);
	draw_map(fd, 10 , &t_session1);
	mlx_loop(mlx);

}
// x^ = (x1 + y1) * cos()
// y^ = (x1 + y1) * sin() - z

// x2^ = (x2 + x1) * cos()
// y2^ = (x2 + y2) * sin() - z
