/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:13:58 by mmaquine          #+#    #+#             */
/*   Updated: 2025/09/29 17:05:22 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	split = NULL;
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
			break ;
		}
		last_wc = wc;
		free(line);
		line = get_next_line(fd);
	}
	return (wc);
}

int	validate_element(char **spl, int x, t_window *w)
{
	char	*nl;
	int		z;

	z = 0;
	while (spl[z])
	{
		nl = ft_strchr(spl[z], '\n');
		if (nl)
			*nl = 0;
		nl = ft_strchr(spl[z], ',');
		if (nl)
		{
			if (!w->lpts)
		}
		z++;
	}
	free(spl);	
}

int	read_points(int fd, t_window *w)
{
	char	*line;
	int		count;
	char	**spl;

	(void)w;
	count = 0;
	if (!validate_file(fd))
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		spl = ft_split(line, ' ');
		//validate_element(spl, count, w);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	return (0);
}
