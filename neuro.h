/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neuro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:19:03 by mvann             #+#    #+#             */
/*   Updated: 2018/02/05 13:55:24 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEURO_H
# define NEURO_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_X 2000
# define WIN_Y 1000

# define NUM_BLOCKS 3
# define NUM_BIRDS 25

# define DEFAULT_BIRD_H 500
# define BIRD_SIZE 50
# define BIRD_X 150
# define BLOCK_SPACING 700
# define GAP_SIZE 250

# define MAX_MUTATION 105
# define MIN_MUTATION 95

# define MIN_BLOCK_Y GAP_SIZE + 100
# define MAX_BLOCK_Y WIN_Y - 300
# define BLOCK_WIDTH 15
# define GRAVITY 1
# define DELTA_X -10
# define JUMP_DY -20

# define RED 0xFF0000
# define GREEN 0x00FF00

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_SPACE 49
# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_T 17
# define KEY_Y 16

typedef struct	s_block
{
	int			h;
	int			x;
}				t_block;

typedef struct	s_weights
{
	double		w111;
	double		w112;
	double		w113;
	double		w114;
	double		w115;
	double		w116;
	double		w121;
	double		w122;
	double		w123;
	double		w124;
	double		w125;
	double		w126;
	double		w131;
	double		w132;
	double		w133;
	double		w134;
	double		w135;
	double		w136;
	double		w21;
	double		w22;
	double		w23;
	double		w24;
	double		w25;
	double		w26;
}				t_weights;

typedef struct	s_bird
{
	int			h;
	int			dy;
	int			alive;
	int			fitness;
	int			color;
	// void		*img;
	// int			*imgBuff;
	// int			bpp;
	// int			sl;
	// int			end;
	t_weights	*w;
}				t_bird;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_block		*blocks;
	int			nbi; // next block index
	int			generation;
	t_bird		*birds;
	int			fitness;
	void		*blockImg;
	int			*blockImgBuff;
	int			bbpp;
	int			bsl;
	int			bend;
	void		*birdImg;
	int			*birdImgBuff;
	int			bibpp;
	int			bisl;
	int			biend;
}				t_env;

void	init_blocks(t_block *blocks);
void	colorBirdImage(int *buff, int color);

int		keydown_event(int keycode, t_env *env);
int		loop_event(t_env *env);

void	drawEverything(t_env *env);

void	moveEverything(t_env *env);

void	checkCollisions(t_env *env);

int		doesJump(t_env *env, t_bird bird);

void	nextGeneration(t_env *env);

void	destroyBirds(t_bird *birds);

#endif
