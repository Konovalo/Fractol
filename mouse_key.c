#include "fractol.h"

void			key_one2(int key, t_fractal *fractal)
{
	if (key == 18)
		fractal->dju = (fractal->dju + 1) % 2;
	else if (key == 19)
		fractal->col_iter += 50;
	else if (key == 12)
		fractal->type = 1;
	else if (key == 13)
		fractal->type = 2;
	else if (key == 14)
		fractal->type = 3;
}

int				key_one(int key, t_fractal *fractal)
{
	if (key == KEY_ESC)
	{
		free(fractal->p);
		free(fractal);
		exit(0);
	}
	if (key == 126 && fractal->pr < 100)
		fractal->mv_x = fractal->mv_x + 0.1;
	if (key == 125 && fractal->pr < 100)
		fractal->mv_x = fractal->mv_x - 0.1;
	if (key == 123 && fractal->pr < 100)
		fractal->mv_y = fractal->mv_y - 0.1;
	if (key == 124 && fractal->pr < 100)
		fractal->mv_y = fractal->mv_y + 0.1;
	key_one2(key, fractal);
	mlx_clear_window(fractal->p->w, fractal->p->index_w);
	iter(fractal);
	mlx_put_image_to_window(fractal->p->w, fractal->p->index_w, \
			fractal->p->ptr_img, 0, 0);
	return (0);
}

int				mouse_move(int x, int y, t_fractal *fractal)
{
	if (x > 0 && y > 0 && x < fractal->widht && y < fractal->height \
			&& fractal->type == 1 && fractal->dju == 0)
	{
		fractal->k1 = ((x % fractal->widht) - fractal->widht / 2) * 0.004;
		fractal->k2 = (y - fractal->widht / 2) * (-0.004);
		mlx_clear_window(fractal->p->w, fractal->p->index_w);
		iter(fractal);
		mlx_put_image_to_window(fractal->p->w, fractal->p->index_w, \
				fractal->p->ptr_img, 0, 0);
	}
	return (0);
}

int				mouse_zoom(int button, int x, int y, t_fractal *fr)
{
	if (x > 0 && y > 0 && x < fr->widht && y < fr->height && button == 5)
	{
		fr->mv_x += ((x - fr->widht / 2) * 0.004 / fr->pr * 1.1 + fr->mv_x) - \
		((x - fr->widht / 2) * 0.004 / fr->pr + fr->mv_x);
		fr->mv_y += ((y - fr->widht / 2) * (-0.004) / fr->pr * 1.1 + fr->mv_y) \
					- ((y - fr->widht / 2) * (-0.004) / fr->pr + fr->mv_y);
		fr->pr = fr->pr * 1.1;
	}
	else if (x > 0 && y > 0 && x < fr->widht && y < fr->height && button == 4)
	{
		fr->mv_x += ((x - fr->widht / 2) * 0.004 / fr->pr / 1.1 + fr->mv_x) - \
		((x - fr->widht / 2) * 0.004 / fr->pr + fr->mv_x);
		fr->mv_y += ((y - fr->widht / 2) * (-0.004) / fr->pr / 1.1 + fr->mv_y) \
					- ((y - fr->widht / 2) * (-0.004) / fr->pr + fr->mv_y);
		fr->pr = fr->pr / 1.1;
	}
	mlx_clear_window(fr->p->w, fr->p->index_w);
	iter(fr);
	mlx_put_image_to_window(fr->p->w, fr->p->index_w, \
	fr->p->ptr_img, 0, 0);
	return (0);
}
