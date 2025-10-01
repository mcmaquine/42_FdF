/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tlinear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:58:56 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/01 17:04:28 by mmaquine         ###   ########.fr       */
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
t_matrix	*get_rotate_mtx_x(float theta)
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
t_matrix	*get_rotate_mtx_y(float theta)
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
t_matrix	*get_rotate_mtx_z(float theta)
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

/*
Return a matrix which transforms a view into isometric form.
*/
t_matrix	*get_isometric_mtx_tf(void)
{
	double		deg_rot_x;
	t_matrix	*mat_rot_tf_1;
	t_matrix	*mat_rot_tf_2;
	t_matrix	*mat_rot_tf_3;

	deg_rot_x = atan(1 / sqrt(2));
	mat_rot_tf_2 = get_rotate_mtx_x(deg_rot_x);
	mat_rot_tf_1 = get_rotate_mtx_y(M_PI / 4);
	mat_rot_tf_3 = matmul(mat_rot_tf_1, mat_rot_tf_2);
	free_matrix(mat_rot_tf_1);
	free_matrix(mat_rot_tf_2);
	mat_rot_tf_1 = get_rotate_mtx_x(- M_PI / 2);
	mat_rot_tf_2 = matmul(mat_rot_tf_1, mat_rot_tf_3);
	free_matrix(mat_rot_tf_1);
	return (mat_rot_tf_2);
}
