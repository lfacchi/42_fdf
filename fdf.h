/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:22:24 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/21 08:11:24 by lucdos-s         ###   ########.fr       */
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
# define WIDHT 1200
# define HEIGHT 600



/*
** Structs that are usage in project 
*/

typedef struct t_map{
	int x_init;
	int y_init;
	int space;
	int fd;
	char *path;
	int max_widht;
	int max_height;
} t_map;

typedef struct t_rdmap{
	int col;
	int  row;
	char *line;
	char **split_line;
	int **matrix;
} t_rdmap;


typedef struct t_session{
	void *init;
	void *window;
    t_map map;
}t_session;

/*FUNCTIONS ON DRAW.C */
void basenham(t_session *id, int xi, int yi, int xf, int yf);
void draw_map(t_session *id);
void print_matrix(int **matrix);
int **matrix_allocate(int x , int y);
int **read_map(t_session *id);


/*FUNCTIONS ON EVENTS.C */
int print_key_value(int key, t_session *id);



#endif