/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:23:10 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/30 01:00:01 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
static int	is_in_range(double zr, double zi)
{
	if (((zr * zr) + (zi * zi)) <= 4)
		return (1);
	return (0);
}

void	drawit(fractol_s *fractol)
{
	int	i;

	i = 0;
	fractol->zr = 0.0;
	fractol->zi = 0.0;
	while (i < fractol->max_iter && is_in_range(fractol->zr, fractol->zi))
	{
		fractol->tmp = ((fractol->zr * fractol->zr) - (fractol->zi
					* fractol->zi)) + fractol->cr;
		fractol->zi = 2 * fractol->zr * fractol->zi + fractol->ci;
		fractol->zr = fractol->tmp;
		i++;
	}
	if (i == fractol->max_iter)
	{
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, 0xFD00FF);
	}
	else
		my_mlx_pixel_put(fractol, fractol->x, fractol->y,scalefractol(i,  0 ,fractol->max_iter , 0,0xFD00FF) );
}

void	draw_mandelbrot(fractol_s *fractol)
{
	fractol->x = 0;
	while (fractol->x < WH)
	{
		fractol->y = 0;
		while (fractol->y < WH)
		{
			fractol->cr = scalefractol(fractol->x, 0, 800, -2, 2);
			fractol->ci = scalefractol(fractol->y, 0, 800, -2, 2);
			drawit(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
}
void	mandelbrot(fractol_s *fractol)
{
	fractol->max_iter = 1500;
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 800, 800, "Hello world!");
	fractol->img.img = mlx_new_image(fractol->mlx, 800, 800);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	draw_mandelbrot(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	mlx_loop(fractol->mlx);
}
