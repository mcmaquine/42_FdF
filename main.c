#include "fdf.h"

int	windows_close(int keycode, t_window *t_wind)
{
	(void)keycode;
	mlx_destroy_window(t_wind->mlx, t_wind->win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_window	t_w;

	t_w.mlx = mlx_init();
	t_w.win = mlx_new_window(t_w.mlx, 1280, 720, "Hello world!");
	mlx_hook(t_w.win, 2, 1L<<0, windows_close, &t_w);
	mlx_loop(t_w.mlx);
}
