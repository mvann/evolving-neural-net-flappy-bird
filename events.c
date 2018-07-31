/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:48:12 by mvann             #+#    #+#             */
/*   Updated: 2018/02/07 10:52:37 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

int		keydown_event(int keycode, t_env *env)
{
	// printf("keycode %i\n", keycode);
	if (keycode == KEY_ESC)
			exit(EXIT_SUCCESS);
	else if (keycode == KEY_SPACE)
			env->birds[0].dy = JUMP_DY;
	return (loop_event(env));
}

int		loop_event(t_env *env)
{
	moveEverything(env);
	checkCollisions(env);
	if (env->blocks[env->nbi].x + BLOCK_WIDTH < BIRD_X)
		env->nbi = env->nbi >= NUM_BLOCKS ? 0 : env->nbi;
	// printf("\tnbix: %i\n", env->blocks[env->nbi].x);
	env->fitness -= DELTA_X;
	// if (env->generation % 10 == 0)
		drawEverything(env);
	nextGeneration(env);
	return (0);
}
