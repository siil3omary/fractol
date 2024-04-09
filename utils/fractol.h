/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:21:12 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/09 19:55:55 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		set;
}			t_fractol;

void		julia(t_fractol *fractol, double cr, double ci);
double		ft_atod(char *str);
int			ft_isdigit(char c);
int			ft_isspace(int c);
int			draw_julia(t_fractol *fractol);
void		brurningship(t_fractol *fractol);
int			draw_brurningship(t_fractol *fractol);
double		scalefractol(int value, int oldmin, int newmin, int newmax);
int			ft_isdigit(char c);
void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
int			is_in_range(double zr, double zi);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);
void		mandelbrot(t_fractol *fractol);
void		julia(t_fractol *fractol, double cr, double ci);
int			key_hook(int keycode, t_fractol *vars);
int			draw_mandelbrot(t_fractol *fractol);
void		init(t_fractol *fractol);

#endif // FRACTOL_H
