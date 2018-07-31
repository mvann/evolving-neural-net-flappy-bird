/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:07:16 by mvann             #+#    #+#             */
/*   Updated: 2018/01/15 14:58:01 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

void	moveBlocks(t_block *blocks)
{
	int i;

	i = 0;
	while (i < NUM_BLOCKS)
	{
		blocks[i].x += DELTA_X;
		if (blocks[i].x < 0)
		{
			blocks[i].x = blocks[(i + NUM_BLOCKS - 1) % NUM_BLOCKS].x + BLOCK_SPACING;
			blocks[i].h = rand() % (MAX_BLOCK_Y - MIN_BLOCK_Y) + MIN_BLOCK_Y;
		}
		i++;
	}
}

void	moveBirds(t_env *env, t_bird *birds)
{
	int i;

	i = 0;
	while (i < NUM_BIRDS)
	{
		if (birds[i].alive)
		{
			birds[i].dy += GRAVITY;
			if (doesJump(env, birds[i]))
				birds[i].dy = JUMP_DY;
			birds[i].h += birds[i].dy;
		}
		i++;
	}
}

void	moveEverything(t_env *env)
{
	moveBirds(env, env->birds);
	moveBlocks(env->blocks);
}
