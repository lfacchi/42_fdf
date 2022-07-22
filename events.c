/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:59:56 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/19 01:58:40 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int print_key_value(int key, t_session *id)
{
	printf("%d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(id->init, id->window);
		mlx_destroy_display(id->init);
		exit(0);
	}
}
