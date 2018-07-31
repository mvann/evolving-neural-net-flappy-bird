/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:29:46 by mvann             #+#    #+#             */
/*   Updated: 2018/02/05 14:23:25 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neuro.h"

double	sigmoid(double z)
{
	return (1 / (1 + exp(-z)));
}

int		doesJump(t_env *env, t_bird bird)
{
	double		outcome;
	double		z21;
	double		z22;
	double		z23;
	double		z24;
	double		z25;
	double		z26;
	double		normH;
	double		normDY;
	double		normDX;
	t_weights	*w;

	normH = (double)bird.h / WIN_Y;
	normDY = ((double)env->blocks[env->nbi].h - (double)bird.h) / WIN_Y;
	normDX = ((double)env->blocks[env->nbi].x - (double)BIRD_X) / WIN_X;

	w = bird.w;
	z21 = normH * w->w111 + normDY * w->w121 + normDX * w->w131;
	z22 = normH * w->w112 + normDY * w->w122 + normDX * w->w132;
	z23 = normH * w->w113 + normDY * w->w123 + normDX * w->w133;
	z24 = normH * w->w114 + normDY * w->w124 + normDX * w->w134;
	z25 = normH * w->w115 + normDY * w->w125 + normDX * w->w135;
	z26 = normH * w->w116 + normDY * w->w126 + normDX * w->w136;

	// z21 = normH * w->w121 + normDX * w->w131;
	// z22 = normH * w->w122 + normDX * w->w132;
	// z23 = normH * w->w123 + normDX * w->w133;
	// z24 = normH * w->w124 + normDX * w->w134;

	z21 = sigmoid(z21);
	z22 = sigmoid(z22);
	z23 = sigmoid(z23);
	z24 = sigmoid(z24);
	z25 = sigmoid(z25);
	z26 = sigmoid(z26);

	outcome = (double)(z21 * w->w21 + z22 * w->w22 + z23 * w->w23 + z24 * w->w24 + z25 * w->w25 + z26 * w->w26) / 6;
	// printf("outcome: %f\n", sigmoid(outcome));//, nh: %f, ndx: %f\n", sigmoid(outcome), normH, normDX);

	return (sigmoid(outcome) < .58);
}
