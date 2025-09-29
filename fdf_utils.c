/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:41:49 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/29 16:57:07 by mmaquine         ###   ########.fr       */
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
	while (ptr[i])
	{
		result = 16 * result + get_hex_value(ptr[i]);
		i++;
	}
	return (result);
}