#include "fdf.h"

int	key_press_event(int keycode, t_window *t_wind)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(t_wind->mlx, t_wind->win);
		exit(0);
	}
	return (0);
}

void	fdf_usage(void)
{
	ft_printf("Fdf program usage:\n");
	ft_printf("./fdf <map_file.fdf\n");
}

int	wc(char	*line)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	if (!line)
		return (0);
	while (line[pos] && line[pos] != '\n')
	{
		if ((line[pos] != ' ' && pos == 0)
			|| (pos != 0 && line[pos-1] == ' ' && line[pos] != ' '))
			count++;
		pos++;
	}
	return (count);
}

/*
Verify if every line as the same number of 'words'
*/
int	validate_file(char *file_name)
{
	int		fd;
	char	*line;
	int		words;
	int		last_wc;

	words = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
		return (0);
	line = get_next_line(fd);
	last_wc = wc(line);
	while(line)
	{
		words = wc(line);
		if (last_wc != words)
		{
			words = 0;
			break ;
		}
		last_wc = words;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (words);
}

int	main(int argc, char **argv)
{
	/*t_window	wind;
	t_data		img;*/

	if (argc < 2)
	{
		fdf_usage();
		exit(0);
	}
	ft_printf("%d\n", validate_file(argv[1]));
	/*create_window(&wind, 1280, 720);
	img.img = mlx_new_image(wind.mlx, wind.width, wind.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	draw_circle(200, &img, &wind);
	mlx_put_image_to_window(wind.mlx, wind.win, img.img, 0, 0);
	mlx_hook(wind.win, 2, 1L<<0, key_press_event, &wind);
	mlx_loop(wind.mlx);*/
}
