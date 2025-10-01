#include "fdf.h"
#include <stdio.h>

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
	ft_printf("\t\t\tFdf program usage:\n");
	ft_printf("\t\t\t./fdf <map_file>.fdf\n");
}

int	main(int argc, char **argv)
{
	//t_window	wind;
	//int			fd;
	t_matrix	*a, *b, *c;

	/*wind.lpts = NULL;
	if (argc < 2)
	{
		fdf_usage();
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	close(fd);
	if (fd < 3)
	{
		ft_printf("Error opening file\n");
		return (1);
	}
	if(!read_points(argv[1], &wind))
	{
		ft_printf("File cannot be loaded\n");
		exit(0);
	}//ate aqui eh para valer  
	ft_lstclear(&wind.lpts, free_points);*/
	(void)argc;
	(void)argv;
	a = create_matrix(1, 2);
	b = create_matrix(2, 2);
	a->a[0][0] = 3; a->a[0][1] = 3;
	b->a[0][0] = 6; b->a[0][1] = -7;
	b->a[1][0] = -4; b->a[1][1] = 5;
	c = matmul(a, b);
	for (int i = 0; i < c->row; i++)
	{
		for (int j = 0; j < c->col; j++)
			printf("%.0f ", c->a[i][j]);
		printf("\n");
	}
	free_matrix(a);
	free_matrix(b);
	free_matrix(c);
	// create_window(&wind, 1280, 720);
	// img.img = mlx_new_image(wind.mlx, wind.width, wind.height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// &img.endian);
	// draw_circle(200, &img, &wind);
	// mlx_put_image_to_window(wind.mlx, wind.win, img.img, 0, 0);
	// mlx_hook(wind.win, 2, 1L<<0, key_press_event, &wind);
	// mlx_loop(wind.mlx);
}
