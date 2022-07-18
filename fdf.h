/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:22:24 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/16 18:01:25 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Basic libraries for the previous allowed functions: open, read, write, close,
** malloc, free, perror, strerror and exit. 
*/

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
# include "get_next_line.h"

/*
** Allowed libraries: math and minilibx, witch is appended in the project's 
** folder to guarantee usage by testers. 
*/

# include <math.h>
# include "../minilibx-linux/mlx.h"

/*
** Structs that are usage in project 
*/
typedef struct t_square{
	int	x_init;
	int	y_init;
	int	side;
}t_square;

typedef struct t_session{
	void *init;
	void *window;
    t_square bg;
}t_session;



typedef struct t_map{
    
} t_map;
/*
**Functions usage for drar on screen
*/
void create_ver(int x_init, int y_init, int y_final, void *id, void *wnd);
void create_hor(int x_init, int y_init, int x_final, void *id, void *wnd);
void t_create_square(t_square sq, void *id, void *wnd);
void create_matrix(t_square sq,int n_row,int n_col, void *id, void *wnd);


/*
**Function usage for map events
*/
int print_key_value(int key, t_session *id);



#endif