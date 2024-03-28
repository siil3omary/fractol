#if !defined(FRACTOL_H)
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
// cc -I /usr/X11/include -g -L /usr/X11/lib fractol.c -lX11 -lmlx -lXext -framework OpenGL -framework AppKit


typedef struct s_fractol
{
	void	*mlx;
	void	*win;
}			fractol_s;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		mandelbrot(fractol_s *fractol);
void		julia(fractol_s *fractol);

#endif // FRACTOL_H
