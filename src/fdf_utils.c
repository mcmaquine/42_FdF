/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:41:49 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/01 16:16:10 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_hex_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	else if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	else
		return (0);
}

__uint32_t	atoi_16(char *ptr)
{
	int	i;
	__uint32_t result;

	if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
		ptr += 2;
	result = 0;
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		result = 16 * result + get_hex_value(ptr[i]);
		i++;
	}
	return (result);
}

t_point	*new_point(int x, int y, int z, __uint32_t color)
{
	t_point	*p;

	p = ft_calloc(1, sizeof(t_point));
	p->color = color;
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

/*
Create a matrix initilizing its values with zero
*/
t_matrix	*create_matrix(int rows, int cols)
{
	int			i;
	t_matrix	*m;

	if (!rows || !cols)
		return (NULL);
	i = 0;
	m = ft_calloc(1, sizeof(t_matrix));
	if (!m)
		return (NULL);
	m->a = ft_calloc(rows, sizeof(double *));
	if (!m->a)
		return (NULL);
	while (i < rows)
	{
		m->a[i] = ft_calloc(cols, sizeof(double));
		i++;
	}
	m->col = cols;
	m->row = rows;
	return (m);
}

void	free_matrix(t_matrix *m)
{
	int i;
	if (!m)
		return ;
	i = 0;
	while (i < m->row)
	{
		free(m->a[i]);
		i++;
	}
	free(m->a);
	free(m);
}
