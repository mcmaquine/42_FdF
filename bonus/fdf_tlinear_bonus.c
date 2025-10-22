/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tlinear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:31:40 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/22 20:35:52 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*
Same transform apllied on dimetric and isometric transform
*/
static void	*standard_transform(void)
{
	t_matrix	*mat_1;
	t_matrix	*mat_2;
	t_matrix	*mat_3;

	mat_1 = get_rotate_mtx_x(-M_PI / 2);
	mat_2 = get_scale_mtx(1, 1, -1);
	mat_3 = mult_mat(mat_2, mat_1);
	free_matrix(mat_1);
	free_matrix(mat_2);
	return (mat_3);
}

/*
Return a matrix which transforms a view into isometric form.
*/
t_matrix	*get_isometric_mtx_tf(double orientation)
{
	double		deg_rot_x;
	t_matrix	*mat_1;
	t_matrix	*mat_2;
	t_matrix	*mat_3;

	deg_rot_x = atan(1 / sqrt(2));
	mat_2 = get_rotate_mtx_x(deg_rot_x);
	mat_1 = get_rotate_mtx_y(M_PI / 4 + orientation * M_PI / 2);
	mat_3 = mult_mat(mat_1, mat_2);
	free_matrix(mat_1);
	free_matrix(mat_2);
	mat_1 = standard_transform();
	mat_2 = mult_mat(mat_1, mat_3);
	free_matrix(mat_1);
	free_matrix(mat_3);
	return (mat_2);
}

t_matrix	*get_dimetric_mtx_tf(double orientation)
{
	t_matrix	*mat_1;
	t_matrix	*mat_2;
	t_matrix	*mat_3;

	mat_2 = get_rotate_mtx_x(M_PI / 6);
	mat_1 = get_rotate_mtx_y(M_PI / 4 + orientation * M_PI / 2);
	mat_3 = mult_mat(mat_1, mat_2);
	free_matrix(mat_1);
	free_matrix(mat_2);
	mat_1 = standard_transform();
	mat_2 = mult_mat(mat_1, mat_3);
	free_matrix(mat_1);
	free_matrix(mat_3);
	return (mat_2);
}
