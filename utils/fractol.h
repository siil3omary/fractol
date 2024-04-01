#if !defined(FRACTOL_H)
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

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
	double	shift_y;
	double	shift_x;
	double	smin;
	double	smax;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	int		x;
	int		y;
	double	tmp;
	char	*name;
	int		max_iter;
	int		color;
	void	*mlx;
	void	*win;
}			fractol_s;

void		julia(fractol_s *fractol, double cr, double ci);
double		ft_atod(char *str);
int			ft_isdigit(char c);
int			ft_isspace(int c);
int			draw_julia(fractol_s *fractol);
void		brurningship(fractol_s *fractol);
int			draw_brurningship(fractol_s *fractol);
double		scalefractol(int value, int oldmin, int oldmax, int newmin,
				int newmax);
int			ft_isdigit(char c);
void		my_mlx_pixel_put(fractol_s *fractol, int x, int y, int color);
int			is_in_range(double zr, double zi);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			mouse_hook(int button, int x, int y, fractol_s *fractol);
void		mandelbrot(fractol_s *fractol);
void		julia(fractol_s *fractol, double cr, double ci);
int			key_hook(int keycode, fractol_s *vars);
static void	drawit(fractol_s *fractol);
int			draw_mandelbrot(fractol_s *fractol);
void		init(fractol_s *fractol);
double		scalefractol(int value, int oldmin, int oldmax, int newmin,
				int newmax);

#endif // FRACTOL_H
