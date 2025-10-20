/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:24:37 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/20 13:25:32 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*init_color_step(t_point *p_st, t_point *p_end, int *dxdy)
{
	t_color	*clr;
	int		dx;
	int		dy;

	clr = ft_calloc(1, sizeof(t_color));
	dx = abs(dxdy[0]);
	dy = abs(dxdy[1]);
	if (dx < dy)
		dx = dy;
	clr->tpcy = get_transparency(p_st->color);
	clr->red = get_red(p_st->color);
	clr->green = get_green(p_st->color);
	clr->blue = get_blue(p_st->color);
	clr->tpcy = (double)(get_transparency(p_end->color)
			- get_transparency(p_st->color)/dx);
	clr->step_r = (double)(get_red(p_end->color) - get_red(p_st->color))/dx;
	clr->step_g = (double)(get_green(p_end->color) - get_green(p_st->color))/dx;
	clr->step_b = (double)(get_blue(p_end->color) - get_blue(p_st->color))/dx;
	return (clr);
}

unsigned int	get_step_color(t_color *c)
{
	int				transparency;
	int				red;
	int				green;
	int				blue;
	unsigned int	color;

	c->tpcy += c->step_tpcy;
	c->red += c->step_r;
	c->green += c->step_g;
	c->blue += c->step_b;
	transparency = (int)c->tpcy;
	red = (int)c->red;
	green = (int)c->green;
	blue = (int)c->blue;
	color = set_color(transparency, red, green, blue);
	return (color);
}