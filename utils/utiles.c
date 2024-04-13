/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:13:52 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/13 00:06:56 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5)
		fractol->zoom *= 1.1;
	else if (button == 4)
		fractol->zoom /= 1.1;
	if (fractol->set == 1)
		draw_mandelbrot(fractol);
	else if (fractol->set == 2)
		draw_julia(fractol);
	else if (fractol->set == 3)
		draw_brurningship(fractol);
	return (0);
}

double	scalefractol(int value, int oldmin, int newmin, int newmax)
{
	double	new;

	new = (((double)(value - oldmin) / (WH - oldmin)) * (newmax - newmin))
		+ newmin;
	return (new);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
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

void	key_utils2(t_fractol *fractol, int keycode)
{
	if (keycode == 27)
		fractol->zoom /= 1.1;
	if (keycode == 11)
		fractol->set = 3;
	if (keycode == 38)
	{
		fractol->ci = 0.4;
		fractol->cr = -0.6;
		fractol->set = 2;
	}
	if (keycode == 46)
		fractol->set = 1;
}
