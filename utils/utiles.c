/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:13:52 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/30 23:24:11 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, fractol_s *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	old_zoom;

	mouse_x = scalefractol(x, 0, WH, -2, 2) / fractol->zoom + fractol->shift_x;
	mouse_y = scalefractol(y, 0, WH, -2, 2) / fractol->zoom + fractol->shift_y;
	old_zoom = fractol->zoom;
	if (button == 4)
	{
		fractol->zoom *= 1.1;
		fractol->shift_x -= (mouse_x * fractol->zoom / old_zoom)
			- scalefractol(x, 0, WH, -2, 2);
		fractol->shift_y -= (mouse_y * fractol->zoom / old_zoom)
			- scalefractol(y, 0, WH, -2, 2);
		draw_mandelbrot(fractol);
	}
	if (button == 5)
	{
		fractol->zoom /= 1.1;
		fractol->shift_x -= (mouse_x * fractol->zoom / old_zoom)
			- scalefractol(x, 0, WH, -2, 2);
		fractol->shift_y -= (mouse_y * fractol->zoom / old_zoom)
			- scalefractol(y, 0, WH, -2, 2);
		draw_mandelbrot(fractol);
	}
	return (0);
}
double	scalefractol(int value, int oldmin, int oldmax, int newmin, int newmax)
{
	double	new;

	new = (((double)(value - oldmin) / (oldmax - oldmin)) * (newmax - newmin))
		+ newmin;
	return (new);
}

void	my_mlx_pixel_put(fractol_s *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->img.addr + (y * fractol->img.line_length + x
			* (fractol->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	is_in_range(double zr, double zi)
{
	if (((zr * zr) + (zi * zi)) <= 4)
		return (1);
	return (0);
}

int	key_hook(int keycode, fractol_s *fractol)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 4)
		fractol->zoom *= 1.1;
	if (keycode == 5)
		fractol->zoom /= 1.1;
	if (keycode == 69)
		fractol->max_iter += 10;
	if (keycode == 78)
		fractol->max_iter -= 10;
	if (keycode == 123)
		fractol->shift_x += 0.1;
	if (keycode == 124)
		fractol->shift_x -= 0.1;
	if (keycode == 126)
		fractol->shift_y += 0.1;
	if (keycode == 125)
		fractol->shift_y -= 0.1;
	if (keycode == 48)
		fractol->color -= 0x0000FF;
	if (keycode == 24)
		fractol->zoom *= 1.1;
	if (keycode == 27)
		fractol->zoom /= 1.1;
	if (keycode == 49)
		fractol->color += 0x0000FF;
	draw_mandelbrot(fractol);
	return (0);
}
void	init(fractol_s *fractol)
{
	fractol->zoom = 1;
	fractol->color = 0x000000;
	fractol->max_iter = 10;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
}

double	ft_atod(char *str)
{
	double results;
	double sign;
	
}
int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}