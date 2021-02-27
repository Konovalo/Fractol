#include "fractol.h"

void	color2(t_fractal *fractal, int *k1, int *k2, int *k3)
{
	fractal->b = 0xff;
	*k2 = 0;
	if (fractal->g > 0 && *k2 == 0)
		fractal->g -= 5;
	else if (*k2 == 0)
	{
		fractal->g = 0xff;
		*k3 = 0;
	}
	if (fractal->r > 0 && *k3 == 0)
		fractal->r -= 5;
	else if (*k3 == 0)
		fractal->r = 0xff;
	*k1 = 0;
}

int		color(int col_iter, t_fractal *fractal)
{
	int k1;
	int k2;
	int k3;
	int i;

	k1 = 0;
	i = 0;
	fractal->r = 0xff;
	fractal->g = 0xff;
	fractal->b = 0xff;
	while (i < col_iter)
	{
		if (fractal->b > 0 && k1 == 0)
		{
			fractal->b -= 5;
			k2 = 1;
			k3 = 1;
		}
		else
			color2(fractal, &k1, &k2, &k3);
		i++;
	}
	return (fractal->r * 256 * 256 + fractal->g * 256 + fractal->b);
}
