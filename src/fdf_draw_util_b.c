#include "fdf.h"

static void	update(int *error, int *start, int *d, int *step)
{
	*error = *error + *d;
	*start = *start + *step;
}

static void	init_step(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

void lineDraw(t_window *w, t_point *p0, t_point *p1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;

	dx = abs(p1->x - p0->x);
	dy = -abs(p1->y - p0->y);
	sx = init_step(p0->x, p1->x);
	sy = init_step(p0->y, p1->y);
	while ((p0->x != p1->x1) && (p0->y != p1->y))
	{
		paint_pixel()
		if ((2 * error) >= dy)
			break ;
		else
			update(&error, &(p0->x), &dy, &sx);
		if ((2 * error) <= dx)
			break ;
		else
			update(&error, &(p0->y), &dx, &sy);
	}
}
