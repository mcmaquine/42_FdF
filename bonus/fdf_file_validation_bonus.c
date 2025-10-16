/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_validation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:13:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/15 17:13:19 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static __uint32_t	get_color_param(char *param)
{
	char		*comma;
	__uint32_t	color;

	comma = ft_strchr(param, ',');
	if (comma)
	{
		comma++;
		color = atoi_16(comma);
	}
	else
		color = 0xFFFFFF;
	return (color);
}

/*
Verify if every line as the same number of 'words'
Returns total words on every line, zero if they are different.
*/
int	validate_file(int fd, int *rows)
{
	char	*line;
	int		wc;
	int		last_wc;
	char	**split;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	last_wc = ft_free_split(split);
	while (line)
	{
		split = ft_split(line, ' ');
		wc = ft_free_split(split);
		if (wc != last_wc || wc == 0)
		{
			wc = 0;
			gnl_gc(fd);
			break ;
		}
		last_wc = wc;
		free(line);
		line = get_next_line(fd);
		*rows += 1;
	}
	close(fd);
	return (wc);
}

/*

*/
void	validate_element(char **spl, int y, t_window *w)
{
	int	x;

	x = 0;
	while (spl[x])
	{
		w->data.coord[y][x] = atoi(spl[x]);
		w->data.color[y][x] = get_color_param(spl[x]);
		x++;
	}
	ft_free_split(spl);
}

/*
Read every point from a file and stores it in a struct
*/
int	read_points(char *file_name, t_window *w)
{
	char	*line;
	int		y;
	char	**spl;
	int		fd;

	y = 0;
	fd = open(file_name, O_RDONLY);
	w->data.coord = ft_calloc(w->data.ordinate, sizeof(int *));
	w->data.color = ft_calloc(w->data.ordinate, sizeof(unsigned int *));
	line = get_next_line(fd);
	while (line)
	{
		w->data.coord[y] = ft_calloc(w->data.abscissa, sizeof(int));
		w->data.color[y] = ft_calloc(w->data.abscissa, sizeof(unsigned int));
		spl = ft_split(line, ' ');
		validate_element(spl, y, w);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (y);
}
