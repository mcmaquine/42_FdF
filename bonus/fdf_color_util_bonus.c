/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:48:17 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/15 17:12:28 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

unsigned char	get_transparency(unsigned int color)
{
	return ((color >> 24) & 0xFF);
}

unsigned char	get_red(unsigned int color)
{
	return ((color >> 16) & 0xFF);
}

unsigned char	get_green(unsigned int color)
{
	return ((color >> 8) & 0xFF);
}

unsigned char	get_blue(unsigned int color)
{
	return (color & 0xFF);
}

unsigned int	set_color(int t, int r, int g, int b)
{
	unsigned int	color;

	color = t;
	color = (color << 8) + (0xFF & r);
	color = (color << 8) + (0xFF & g);
	color = (color << 8) + (0xFF & b);
	return (color);
}