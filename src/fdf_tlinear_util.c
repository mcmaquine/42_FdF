/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tlinear_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:58:56 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/09 15:45:34 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Return a scale matrix for 3 axes.
kx: scale factor to x coordinates.
ky: scale factor to y coordinates.
kz: scale factor to z coordinates.
Returns a scale matrix 3,3.
*/
t_matrix	*get_scale_mtx(double kx, double ky, double kz)
{
	t_matrix	*sm;

	sm = create_matrix(3, 3);
	if (!sm)
		return (NULL);
	sm->a[0][0] = kx;
	sm->a[1][1] = ky;
	sm->a[2][2] = kz;
	return (sm);
}

/*
Return a rotate matrix around x axis
theta: angle in radians
*/
t_matrix	*get_rotate_mtx_x(double theta)
{
	t_matrix	*sm;

	sm = create_matrix(3, 3);
	if (!sm)
		return (NULL);
	sm->a[0][0] = 1.0;
	sm->a[1][1] = cos(theta);
	sm->a[1][2] = sin(theta);
	sm->a[2][1] = -sin(theta);
	sm->a[2][2] = cos(theta);
	return (sm);
}

/*
Return a rotate matrix around y axis
theta: angle in radians
*/
t_matrix	*get_rotate_mtx_y(double theta)
{
	t_matrix	*sm;

	sm = create_matrix(3, 3);
	if (!sm)
		return (NULL);
	sm->a[0][0] = cos(theta);
	sm->a[0][2] = -sin(theta);
	sm->a[1][1] = 1.0;
	sm->a[2][0] = sin(theta);
	sm->a[2][2] = cos(theta);
	return (sm);
}

/*
Return a rotate matrix around z axis
theta: angle in radians
*/
t_matrix	*get_rotate_mtx_z(double theta)
{
	t_matrix	*sm;

	sm = create_matrix(3, 3);
	if (!sm)
		return (NULL);
	sm->a[0][0] = cos(theta);
	sm->a[0][1] = sin(theta);
	sm->a[1][0] = -sin(theta);
	sm->a[1][1] = cos(theta);
	sm->a[2][2] = 1.0;
	return (sm);
}
