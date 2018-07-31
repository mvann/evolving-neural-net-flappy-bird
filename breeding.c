/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breeding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:42:16 by mvann             #+#    #+#             */
/*   Updated: 2018/02/05 16:16:15 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

double	mutate()
{
	return (((double)(rand() % (MAX_MUTATION - MIN_MUTATION)) + MIN_MUTATION) / 100);
}

void	getFitBirdIndexes(t_bird *birds, int fitBirdIndexes[10])
{
	int i;
	int birdIndexes[25];
	int sorted;
	int tmp;

	i = 0;
	while (i < NUM_BIRDS)
	{
		birdIndexes[i] = i;
		i++;
	}
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < NUM_BIRDS - 1)
		{
			if (birds[birdIndexes[i]].fitness < birds[birdIndexes[i + 1]].fitness)
			{
				sorted = 0;
				tmp = birdIndexes[i];
				birdIndexes[i] = birdIndexes[i + 1];
				birdIndexes[i + 1] = tmp;
			}
			i++;
		}
	}
	i = 0;
	while (i < 25)
	{
		fitBirdIndexes[i] = birdIndexes[i];
		i++;
	}
}

void	nextGeneration(t_env *env)
{
	int			i;
	int			n;
	int			a;
	int			b;
	int			allDead;
	int			mutation;
	t_bird		*newBirds;
	int			fitBirdIndexes[25];
	t_weights	*w;
	int			indexes[6];

	i = 0;
	while (i < 10)
		fitBirdIndexes[i++] = -1;
	getFitBirdIndexes(env->birds, fitBirdIndexes);
	i = 0;
	allDead = 1;
	while (i < NUM_BIRDS && allDead)
	{
		if (env->birds[i].alive)
			allDead = 0;
		i++;
	}
	if (allDead)
	{
		init_blocks(env->blocks);
		newBirds = (t_bird *)ft_memalloc(sizeof(t_bird) * NUM_BIRDS);
		i = 0;
		while (i < 25)
		{
			newBirds[i].h = DEFAULT_BIRD_H;
			newBirds[i].dy = 0;
			newBirds[i].alive = 1;
			newBirds[i].fitness = 0;
			newBirds[i].color = RED;
			// newBirds[i * 5 + j].img = mlx_new_image(env->mlx, BIRD_SIZE, BIRD_SIZE);
			// newBirds[i * 5 + j].imgBuff = (int *)mlx_get_data_addr(newBirds[i * 5 + j].img, &(newBirds[i * 5 + j].bpp), &(newBirds[i * 5 + j].sl), &(newBirds[i * 5 + j].end));
			// colorBirdImage(newBirds[i * 5 + j].imgBuff, newBirds[i * 5 + j].color);
			newBirds[i].w = (t_weights *)ft_memalloc(sizeof(t_weights));
			w = newBirds[i].w;
			// w->w111 = (env->birds[fitBirdIndexes[i]].w->w111 + env->birds[fitBirdIndexes[5 + j]].w->w111) / 2 * mutate();
			// w->w112 = (env->birds[fitBirdIndexes[i]].w->w112 + env->birds[fitBirdIndexes[5 + j]].w->w112) / 2 * mutate();
			// w->w113 = (env->birds[fitBirdIndexes[i]].w->w113 + env->birds[fitBirdIndexes[5 + j]].w->w113) / 2 * mutate();
			// w->w114 = (env->birds[fitBirdIndexes[i]].w->w114 + env->birds[fitBirdIndexes[5 + j]].w->w114) / 2 * mutate();

			if (env->birds[fitBirdIndexes[0]].fitness == env->birds[fitBirdIndexes[24]].fitness)
			{
				indexes[0] = fitBirdIndexes[i];
				indexes[1] = fitBirdIndexes[i];
				indexes[2] = fitBirdIndexes[i];
				indexes[3] = fitBirdIndexes[i];
				indexes[4] = fitBirdIndexes[i];
				indexes[5] = fitBirdIndexes[i];
				mutation = 1;
			}
			else if (i < 10)
			{
				indexes[0] = fitBirdIndexes[i];
				indexes[1] = fitBirdIndexes[i];
				indexes[2] = fitBirdIndexes[i];
				indexes[3] = fitBirdIndexes[i];
				indexes[4] = fitBirdIndexes[i];
				indexes[5] = fitBirdIndexes[i];
				mutation = 0;
			}
			else if (i < 13)
			{
				n = rand();
				indexes[0] = fitBirdIndexes[(n & 1) > 0];
				indexes[1] = fitBirdIndexes[(n & 2) > 0];
				indexes[2] = fitBirdIndexes[(n & 4) > 0];
				indexes[3] = fitBirdIndexes[(n & 8) > 0];
				indexes[4] = fitBirdIndexes[(n & 16) > 0];
				indexes[5] = fitBirdIndexes[(n & 32) > 0];
				mutation = 1;
			}
			else if (i < 20)
			{
				a = rand() % 10;
				b = rand() % 10;
				n = rand();
				indexes[0] = fitBirdIndexes[n & 1 ? a : b];
				indexes[1] = fitBirdIndexes[n & 2 ? a : b];
				indexes[2] = fitBirdIndexes[n & 4 ? a : b];
				indexes[3] = fitBirdIndexes[n & 8 ? a : b];
				indexes[4] = fitBirdIndexes[n & 16 ? a : b];
				indexes[5] = fitBirdIndexes[n & 32 ? a : b];
				mutation = 1;
			}
			else // i < 25
			{
				a = rand() % 10;
				indexes[0] = fitBirdIndexes[a];
				indexes[1] = fitBirdIndexes[a];
				indexes[2] = fitBirdIndexes[a];
				indexes[3] = fitBirdIndexes[a];
				indexes[4] = fitBirdIndexes[a];
				indexes[5] = fitBirdIndexes[a];
				mutation = 1;
			}


			w->w111 = env->birds[indexes[0]].w->w111 * (mutation ? mutate() : 1);
			w->w121 = env->birds[indexes[0]].w->w121 * (mutation ? mutate() : 1);
			w->w131 = env->birds[indexes[0]].w->w131 * (mutation ? mutate() : 1);
			w->w21 = env->birds[indexes[0]].w->w21 * (mutation ? mutate() : 1);

			w->w112 = env->birds[indexes[1]].w->w112 * (mutation ? mutate() : 1);
			w->w122 = env->birds[indexes[1]].w->w122 * (mutation ? mutate() : 1);
			w->w132 = env->birds[indexes[1]].w->w132 * (mutation ? mutate() : 1);
			w->w22 = env->birds[indexes[1]].w->w22 * (mutation ? mutate() : 1);

			w->w113 = env->birds[indexes[2]].w->w113 * (mutation ? mutate() : 1);
			w->w123 = env->birds[indexes[2]].w->w123 * (mutation ? mutate() : 1);
			w->w133 = env->birds[indexes[2]].w->w133 * (mutation ? mutate() : 1);
			w->w23 = env->birds[indexes[2]].w->w23 * (mutation ? mutate() : 1);

			w->w114 = env->birds[indexes[3]].w->w114 * (mutation ? mutate() : 1);
			w->w124 = env->birds[indexes[3]].w->w124 * (mutation ? mutate() : 1);
			w->w134 = env->birds[indexes[3]].w->w134 * (mutation ? mutate() : 1);
			w->w24 = env->birds[indexes[3]].w->w24 * (mutation ? mutate() : 1);

			w->w115 = env->birds[indexes[3]].w->w115 * (mutation ? mutate() : 1);
			w->w125 = env->birds[indexes[3]].w->w125 * (mutation ? mutate() : 1);
			w->w135 = env->birds[indexes[3]].w->w135 * (mutation ? mutate() : 1);
			w->w25 = env->birds[indexes[3]].w->w25 * (mutation ? mutate() : 1);

			w->w116 = env->birds[indexes[3]].w->w116 * (mutation ? mutate() : 1);
			w->w126 = env->birds[indexes[3]].w->w126 * (mutation ? mutate() : 1);
			w->w136 = env->birds[indexes[3]].w->w136 * (mutation ? mutate() : 1);
			w->w26 = env->birds[indexes[3]].w->w26 * (mutation ? mutate() : 1);


			i++;
		}
		printf("#################\n");
		// printf("w121: %f, w122: %f, w123: %f, w124: %f, mut: %f, dJ: %i\n", newBirds[0].w->w121, newBirds[0].w->w122, newBirds[0].w->w123, newBirds[0].w->w124, mutate(), doesJump(env, newBirds[0]));
		destroyBirds(env->birds);
		env->birds = newBirds;
		env->generation++;
		env->nbi = 0;
		env->fitness = 0;
	}
}
