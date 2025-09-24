/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:49:56 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/23 18:36:38 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*create_window(t_window *wind, int width, int height)
{
	wind->mlx = mlx_init();
	wind->win = mlx_new_window(wind->mlx, width, height, "FdF Canva");
	wind->width = width;
	wind->height = height;
	return (wind->mlx);
}

void	paint_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
	Draw a circle centered on screen
	radius is in pixels.
*/

void	rotate_about_x(int *y, float theta)
{
	*y = *y * cos(theta);
}

void	draw_circle(int radius, t_data *data , t_window *wind)
{
	float	theta;
	float	dtheta = 2 * M_PI / data->line_length;
	int		x;
	int		y;
	
	theta = 0.0;
	while (theta < 2 * M_PI)
	{
		x = (int)radius * cos(theta);
		y = (int)radius * sin(theta);
		theta += dtheta;
		//x = x - wind->width/2;
		//y = wind->height/2 - y;
		paint_pixel(data, x - wind->width/2, wind->height/2 - y, 0xFFFFFF);
		rotate_about_x(&y, 45*M_PI/180.0);
		paint_pixel(data, x - wind->width/2, wind->height/2 - y, 0x007df9);
	}
}

