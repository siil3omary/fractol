#if !defined(FRACTOL_H)
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
// cc -I /usr/X11/include -g -L /usr/X11/lib fractol.c -lX11 -lmlx -lXex -framework OpenGL -framework AppKit
# define WH 800

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	t_img	img;
	double	zoom;
	double zr;
	double zi;
	double cr;
	double ci;
	int x;
	int y;
	double tmp;
	int		max_iter;
	int		color;
	void	*mlx;
	void	*win;
}			fractol_s;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		mandelbrot(fractol_s *fractol);
void		julia(fractol_s *fractol);
int	key_hook(int keycode, fractol_s *vars);
void	drawit(fractol_s *fractol);
int	draw_mandelbrot(fractol_s *fractol);	

#endif // FRACTOL_H
