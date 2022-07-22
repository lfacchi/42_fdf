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
	int **matrix;


	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1200, 600, "AUTOCAD DE CRIA");
	t_session id;
	id.init = mlx;
	id.window = mlx_win;
	id.map.path = "test_maps/pylone.fdf";
	mlx_key_hook(id.window ,print_key_value , &id);

	matrix = read_map(&id);
	print_matrix(matrix);
	// mlx_loop(mlx);

}
// x^ = (x1 + y1) * cos()
// y^ = (x1 + y1) * sin() - z

// x2^ = (x2 + x1) * cos()
// y2^ = (x2 + y2) * sin() - z
