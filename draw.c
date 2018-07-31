/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:39:27 by mvann             #+#    #+#             */
/*   Updated: 2018/01/15 14:41:34 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

void	drawRectangle(t_env *env, int x, int y, int width, int height, int color)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_pixel_put(env->mlx, env->win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	drawBirds(t_env *env, t_bird *birds)
{
	int i;

	i = 0;
	while (i < NUM_BIRDS)
	{
		if (birds[i].alive)
			mlx_put_image_to_window(env->mlx, env->win, env->birdImg, BIRD_X, birds[i].h);
		i++;
	}
}

void	drawBlocks(t_env *env, t_block *blocks)
{
	int i;

	i = 0;
	while (i < NUM_BLOCKS)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->blockImg, blocks[i].x, blocks[i].h - WIN_Y - GAP_SIZE);
		i++;
	}
}

void	drawEverything(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	drawBlocks(env, env->blocks);
	drawBirds(env, env->birds);
	char gen[50];
	sprintf(gen, "Generation: %i", env->generation);
	mlx_string_put(env->mlx, env->win, 10, 10, 0xFFFFFF, gen);
}
