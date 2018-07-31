/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:58 by mvann             #+#    #+#             */
/*   Updated: 2018/02/07 10:34:53 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

void	checkCollisions(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < NUM_BLOCKS)
	{
		if (!(env->blocks[i].x > BIRD_X + BIRD_SIZE || env->blocks[i].x + BLOCK_WIDTH < BIRD_X))
		{
			// env->nbi = i + 1 % NUM_BLOCKS;
			j = 0;
			while (j < NUM_BIRDS)
			{
				if (env->birds[j].alive && (env->birds[j].h <= env->blocks[i].h - GAP_SIZE || env->birds[j].h + BIRD_SIZE >= env->blocks[i].h))
				{
					env->birds[j].alive = 0;
					env->birds[j].fitness = env->fitness - abs(env->blocks[env->nbi].h - (GAP_SIZE / 2) - env->birds[j].h);// - abs(env->blocks[env->nbi].h - (GAP_SIZE / 2) - env->birds[j].h);
					printf("hit block\t\tj: %i,\t\tfit: %i,\t\tnbix: %i\n", j, env->birds[j].fitness, env->blocks[env->nbi].x);
				}
				j++;
			}
		}
		i++;
	}
	j = 0;
	while (j < NUM_BIRDS)
	{
		if (env->birds[j].alive && (env->birds[j].h < 0 || env->birds[j].h + BIRD_SIZE > WIN_Y))
		{
			env->birds[j].alive = 0;
			// env->birds[j].fitness = env->fitness - abs(env->blocks[env->nbi].h - (GAP_SIZE / 2) - env->birds[j].h) - (env->blocks[env->nbi].x - BIRD_X);
			env->birds[j].fitness = env->fitness - abs(env->blocks[env->nbi].h - (GAP_SIZE / 2) - env->birds[j].h);// - (env->blocks[env->nbi].x - BIRD_X);
			printf("hit side\t\tj: %i,\t\tfit: %i,\t\tnbix: %i\n", j, env->birds[j].fitness, env->blocks[env->nbi].x);
		}
		j++;
	}
}
