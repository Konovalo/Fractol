#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include "minilibx_macos/mlx.h"
# include <math.h>

# define KEY_ESC 53

typedef struct	s_fr
{
	void		*w;
	void		*index_w;
	int			k;
	void		*ptr_img;
	char		*str;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_fr;

typedef struct	s_fractal
{
	int			*f;
	int			height;
	int			widht;
	double		x0;
	double		y0;
	double		xn;
	double		yn;
	double		xk;
	double		yk;
	int			type;
	double		pr;
	double		k1;
	double		k2;
	double		mv_x;
	double		mv_y;
	int			dju;
	int			col_iter;
	t_fr		*p;
	int			r;
	int			g;
	int			b;
}				t_fractal;

void			iter(t_fractal *fractal);
int				color(int col_iter, t_fractal *fractal);
int				mouse_zoom(int button, int x, int y, t_fractal *fractal);
int				mouse_move(int x, int y, t_fractal *fractal);
int				key_one(int key, t_fractal *fractal);
void			fractol_mandelbrot(t_fractal *fractal, int i, int j);
void			fractol_julia3(t_fractal *fractal, int i, int j);
void			fractol_julia(t_fractal *fractal, int i, int j);
void			proverca(t_fractal *fractal, int i, int j);

#endif
