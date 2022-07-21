/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:22:24 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/20 20:43:01 by lucdos-s         ###   ########.fr       */
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
# include <stdio.h>
# include "42_libft/get_next_line.h"
# include <math.h>

/*
** Allowed libraries: math and minilibx, witch is appended in the project's 
** folder to guarantee usage by testers. 
*/

# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "42_libft/libft.h"
/*
*  Macros utilizadar para calculo 
*/
# define COS_45 0.707
# define SIN_45 0.707
# define TAN_45 1



/*
** Structs that are usage in project 
*/

typedef struct t_point {
    int x;
    int y;
    int z;
} t_point;

typedef struct t_square{
	t_point p1;
	t_point p2;
	t_point p3;
	t_point p4;  
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
void basenham(t_session *id, int xi, int yi, int xf, int yf);
void draw_map(int fd, int space, t_session *id);


/*
**Function usage for map events
*/
int print_key_value(int key, t_session *id);



#endif