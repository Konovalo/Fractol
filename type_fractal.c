#include "fractol.h"

void	fractol_mandelbrot(t_fractal *fractal, int i, int j)
{
	int	col_iter;

	fractal->x0 = (i - 500) / 250.0 / fractal->pr + fractal->mv_x;
	fractal->y0 = (j - 500) / (-250.0) / fractal->pr + fractal->mv_y;
	fractal->xn = fractal->x0;
	fractal->yn = fractal->y0;
	col_iter = 0;
	while (col_iter < fractal->col_iter && ((fractal->xn * fractal->xn + \
					fractal->yn * fractal->yn) <= 4))
	{
		fractal->xk = fractal->xn * fractal->xn - fractal->yn * \
		fractal->yn + fractal->x0;
		fractal->yk = 2 * fractal->xn * fractal->yn + fractal->y0;
		fractal->xn = fractal->xk;
		fractal->yn = fractal->yk;
		col_iter++;
	}
	if (col_iter == 50)
	{
		fractal->f[i * fractal->widht + j] = 0x00ff00;
	}
	else
		fractal->f[i * fractal->widht + j] = color(col_iter, fractal);
}

void	fractol_julia3(t_fractal *fractal, int i, int j)
{
	int	col_iter;

	fractal->x0 = (i - 500) / 250.0 / fractal->pr - fractal->mv_y;
	fractal->y0 = (j - 500) / (-250.0) / fractal->pr - fractal->mv_x;
	fractal->xn = fractal->x0;
	fractal->yn = fractal->y0;
	col_iter = 0;
	while (col_iter < fractal->col_iter && ((fractal->xn * fractal->xn + \
					fractal->yn * fractal->yn) <= 4))
	{
		fractal->xk = fabs(fractal->xn * fractal->xn) - fabs(fractal->yn * \
				fractal->yn) + fractal->x0;
		fractal->yk = 2 * fabs(fractal->xn * fractal->yn) - fractal->y0;
		fractal->xn = fractal->xk;
		fractal->yn = fractal->yk;
		col_iter++;
	}
	if (col_iter == 50)
	{
		fractal->f[j * fractal->widht + i] = 0x00ff00;
	}
	else
		fractal->f[j * fractal->widht + i] = color(col_iter, fractal);
}

void	fractol_julia(t_fractal *fractal, int i, int j)
{
	int	col_iter;

	fractal->x0 = (i - 500) / 250.0 / fractal->pr - fractal->mv_y;
	fractal->y0 = (j - 500) / (-250.0) / fractal->pr - fractal->mv_x;
	fractal->xn = fractal->x0;
	fractal->yn = fractal->y0;
	col_iter = 0;
	while (col_iter < fractal->col_iter && ((fractal->xn * fractal->xn + \
					fractal->yn * fractal->yn) <= 4))
	{
		fractal->xk = fractal->xn * fractal->xn - fractal->yn * \
		fractal->yn + fractal->k1;
		fractal->yk = 2 * fractal->xn * fractal->yn + fractal->k2;
		fractal->xn = fractal->xk;
		fractal->yn = fractal->yk;
		col_iter++;
	}
	if (col_iter == 50)
	{
		fractal->f[j * fractal->widht + i] = 0x00ff00;
	}
	else
		fractal->f[j * fractal->widht + i] = color(col_iter, fractal);
}

void	iter(t_fractal *fractal)
{
	int	i;
	int	j;

	i = 0;
	while (i < fractal->widht)
	{
		j = 0;
		while (j < fractal->height)
		{
			proverca(fractal, i, j);
			j++;
		}
		i++;
	}
}
