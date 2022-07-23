/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:55:04 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/21 08:13:07 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char 	*str;
	t_map map;
	t_rdmap save_map;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1800, 900, "AUTOCAD DE CRIA");
	t_session id;
	id.init = mlx;
	id.window = mlx_win;
	id.map.x_init = 10;
	id.map.y_init = 10;
	id.map.space = 10;
	id.map.path = "test_maps/42.fdf";

	mlx_key_hook(id.window ,key_value , &id);

	save_map = read_map(&id);
	id.rdmap = save_map;
	printf("matrix  %d x %d -", id.rdmap.row , id.rdmap.col);
	draw_map(&id);
	mlx_loop(mlx);

}

