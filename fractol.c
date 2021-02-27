#include "fractol.h"

void			proverca(t_fractal *fractal, int i, int j)
{
	if (fractal->type == 2)
		fractol_mandelbrot(fractal, i, j);
	if (fractal->type == 1)
		fractol_julia(fractal, i, j);
	if (fractal->type == 3)
		fractol_julia3(fractal, i, j);
}

void			write_command(void)
{
	ft_putstr("Julia        argument 1\n");
	ft_putstr("Mandelbrot   argument 2\n");
	ft_putstr("Burning Ship argument 3\n");
}

void			fractal_init(t_fractal *fractal)
{
	fractal->height = 1000;
	fractal->widht = 1000;
	fractal->pr = 1.0;
	fractal->k1 = 0.285;
	fractal->k2 = 0.01;
	fractal->mv_x = 0;
	fractal->mv_y = 0;
	fractal->dju = 0;
	fractal->col_iter = 50;
	fractal->p->w = mlx_init();
	fractal->p->index_w = mlx_new_window(fractal->p->w, fractal->widht, \
			fractal->height, "Tata");
	fractal->p->ptr_img = mlx_new_image(fractal->p->w, fractal->widht, \
			fractal->height);
	fractal->f = (int*)mlx_get_data_addr(fractal->p->ptr_img, \
			&(fractal->p->bits_per_pixel), &(fractal->p->size_line), \
			&(fractal->p->endian));
}

void			fractal_type_op(char *str, t_fractal *fractal)
{
	if ((ft_strcmp(str, "1")) == 0)
		fractal->type = 1;
	if ((ft_strcmp(str, "2")) == 0)
		fractal->type = 2;
	if ((ft_strcmp(str, "3")) == 0)
		fractal->type = 3;
}

int				main(int argc, char *argv[])
{
	t_fractal	*fractal;

	if (argc != 2 || ((ft_strcmp(argv[1], "1")) != 0 && \
	(ft_strcmp(argv[1], "2")) != 0 && (ft_strcmp(argv[1], "3")) != 0))
		write_command();
	else
	{
		if (!(fractal = (t_fractal*)malloc(sizeof(t_fractal))))
			return (0);
		if (!(fractal->p = (t_fr*)malloc(sizeof(t_fr))))
			return (0);
		fractal_init(fractal);
		fractal_type_op(argv[1], fractal);
		iter(fractal);
		mlx_key_hook(fractal->p->index_w, key_one, fractal);
		mlx_hook(fractal->p->index_w, 6, 0, mouse_move, fractal);
		mlx_hook(fractal->p->index_w, 4, 0, mouse_zoom, fractal);
		mlx_put_image_to_window(fractal->p->w, fractal->p->index_w, \
		fractal->p->ptr_img, 0, 0);
		mlx_loop(fractal->p->w);
	}
	return (0);
}
