/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:11:06 by mvann             #+#    #+#             */
/*   Updated: 2018/06/10 13:54:53 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

void  error()
{
	printf("Error\n"); //DELETE ME
	exit(EXIT_FAILURE);
}

void	init_blocks(t_block *blocks)
{
	int	i;

	i = 0;
	while (i < NUM_BLOCKS)
	{
		blocks[i].h = rand() % (MAX_BLOCK_Y - MIN_BLOCK_Y) + MIN_BLOCK_Y;
		blocks[i].x = WIN_X / 3 + BLOCK_SPACING * i;
		i++;
	}
}

void	colorBirdImage(int *buff, int color)
{
	int i;

	i = 0;
	while (i < BIRD_SIZE * BIRD_SIZE)
	{
		buff[i] = color;
		i++;
	}
}

void	init_birds(t_env *env, t_bird *birds)
{
	int	i;
	t_weights *w;
(void)env;
	i = 0;
	while (i < NUM_BIRDS)
	{
		birds[i].h = DEFAULT_BIRD_H;
		birds[i].dy = 0;
		birds[i].alive = 1;
		birds[i].fitness = 0;
		birds[i].color = RED;
		// birds[i].img = mlx_new_image(env->mlx, BIRD_SIZE, BIRD_SIZE);
		// birds[i].imgBuff = (int *)mlx_get_data_addr(birds[i].img, &(birds[i].bpp), &(birds[i].sl), &(birds[i].end));
		// colorBirdImage(birds[i].imgBuff, birds[i].color);
		// printf("bpp: %i, sl: %i, end: %i\n", birds[i].bpp, birds[i].sl, birds[i].end);

		birds[i].w = (t_weights *)ft_memalloc(sizeof(t_weights));
		w = birds[i].w;
		w->w111 = (double)(rand() % 50 + 25) / 100;
		w->w112 = (double)(rand() % 50 + 25) / 100;
		w->w113 = (double)(rand() % 50 + 25) / 100;
		w->w114 = (double)(rand() % 50 + 25) / 100;
		w->w115 = (double)(rand() % 50 + 25) / 100;
		w->w116 = (double)(rand() % 50 + 25) / 100;
		w->w121 = (double)(rand() % 50 + 25) / 100;
		w->w122 = (double)(rand() % 50 + 25) / 100;
		w->w123 = (double)(rand() % 50 + 25) / 100;
		w->w124 = (double)(rand() % 50 + 25) / 100;
		w->w125 = (double)(rand() % 50 + 25) / 100;
		w->w126 = (double)(rand() % 50 + 25) / 100;
		w->w131 = (double)(rand() % 50 + 25) / 100;
		w->w132 = (double)(rand() % 50 + 25) / 100;
		w->w133 = (double)(rand() % 50 + 25) / 100;
		w->w134 = (double)(rand() % 50 + 25) / 100;
		w->w135 = (double)(rand() % 50 + 25) / 100;
		w->w136 = (double)(rand() % 50 + 25) / 100;
		w->w21 = (double)(rand() % 50 + 25) / 100;
		w->w22 = (double)(rand() % 50 + 25) / 100;
		w->w23 = (double)(rand() % 50 + 25) / 100;
		w->w24 = (double)(rand() % 50 + 25) / 100;
		w->w25 = (double)(rand() % 50 + 25) / 100;
		w->w26 = (double)(rand() % 50 + 25) / 100;
		i++;
	}
}

void	init_block_img(t_env *env)
{
	int i;

	env->blockImg = mlx_new_image(env->mlx, BLOCK_WIDTH, 2 * WIN_Y + GAP_SIZE);
	env->blockImgBuff = (int *)mlx_get_data_addr(env->blockImg, &(env->bbpp), &(env->bsl), &(env->bend));
	i = 0;
	while (i < WIN_Y * BLOCK_WIDTH)
	{
		env->blockImgBuff[i] = GREEN;
		i++;
	}
	i += GAP_SIZE * BLOCK_WIDTH;
	while (i < 2 * WIN_Y * BLOCK_WIDTH + GAP_SIZE * BLOCK_WIDTH)
	{
		env->blockImgBuff[i] = GREEN;
		i++;
	}
}

void	init_bird_img(t_env *env)
{
	int i;

	env->birdImg = mlx_new_image(env->mlx, BIRD_SIZE, BIRD_SIZE);
	env->birdImgBuff = (int *)mlx_get_data_addr(env->birdImg, &(env->bibpp), &(env->bisl), &(env->biend));
	i = 0;
	while (i < BIRD_SIZE * BIRD_SIZE)
	{
			env->birdImgBuff[i] = RED;
			i++;
	}
}

void	init_env(t_env **env)
{
	t_env *e;

	if (!(*env = (t_env *)ft_memalloc(sizeof(t_env)))
	|| !((*env)->mlx = mlx_init()))
		error();
	e = *env;
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Neuro Bird");
	e->blocks = (t_block *)ft_memalloc(sizeof(t_block) * NUM_BLOCKS);
	e->nbi = 0;
	e->generation = 0;
	e->birds = (t_bird *)ft_memalloc(sizeof(t_bird) * NUM_BIRDS);
	if (!(e->win) || !(e->blocks) || !(e->birds))
		error();
	init_blocks(e->blocks);
	init_birds(e, e->birds);
	init_block_img(e);
	init_bird_img(e);
	e->fitness = 0;
}

int		main()
{
	t_env *env;

	init_env(&env);
	while (env->generation < 0)
	{
		moveEverything(env);
		checkCollisions(env);
		env->fitness -= DELTA_X;
		nextGeneration(env);
	}
	mlx_hook(env->win, 2, 0, keydown_event, env);
	mlx_loop_hook(env->mlx, loop_event, env);
	mlx_loop(env->mlx);
	return (0);
}
