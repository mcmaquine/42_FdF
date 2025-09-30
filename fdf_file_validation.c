/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:13:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/30 17:38:44 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
int	validate_file(int fd)
{
	char	*line;
	int		wc;
	int		last_wc;
	char	**split;

	wc = 0;
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	last_wc = ft_free_split(split);
	while(line)
	{
		split = ft_split(line, ' ');
		wc = ft_free_split(split);
		if(wc != last_wc)
		{
			wc = 0;
			gnl_gc(fd);
			break ;
		}
		last_wc = wc;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (wc);
}

/*

*/
void	validate_element(char **spl, int x, t_window *w)
{
	int			y;
	int			z;
	t_point		*p;
	__uint32_t	color;

	y = 0;
	while (spl[y])
	{
		z = atoi(spl[y]);
		color = get_color_param(spl[y]);
		p = new_point(x, y, z, color);
		if (!w->lpts)
			w->lpts = ft_lstnew(p);
		else
			ft_lstadd_back(&(w->lpts), ft_lstnew(p));
		y++;
	}
	ft_free_split(spl);
}

/*
Read every point from a file and stores it in a struct
*/
int	read_points(char *file_name, t_window *w)
{
	char	*line;
	int		x;
	char	**spl;
	int		fd;

	x = 0;
	fd = open(file_name, O_RDONLY);
	if (!validate_file(fd))
		return (0);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		spl = ft_split(line, ' ');
		validate_element(spl, x, w);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	close(fd);
	return (x);
}

/*
Free memory allocated to struct s_point. To be used, also, by function
ft_lstclear.
*/
void	free_points(void *point)
{
	free(point);
}
