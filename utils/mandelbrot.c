/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:23:10 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/30 03:03:54 by aelomari         ###   ########.fr       */
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
	fractol->cr = scalefractol(fractol->x, 0, 800, -2, 2) / fractol->zoom + fractol->shift_x;
	fractol->ci = scalefractol(fractol->y, 0, 800, -2, 2) / fractol->zoom + fractol->shift_y;
	while (i < fractol->max_iter && is_in_range(fractol->zr, fractol->zi))
	{
		fractol->tmp = ((fractol->zr * fractol->zr) - (fractol->zi
					* fractol->zi)) + fractol->cr;
		fractol->zi = 2 * fractol->zr * fractol->zi + fractol->ci;
		fractol->zr = fractol->tmp;
		i++;
	}
	if (i == fractol->max_iter)
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, 0);
	else
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, scalefractol(i * 1.01,
				fractol->color, fractol->max_iter, 0, 0x0A75AD));
}

int	draw_mandelbrot(fractol_s *fractol)
{
	fractol->x = 0;
	while (fractol->x < WH)
	{
		fractol->y = 0;
		while (fractol->y < WH)
		{
			drawit(fractol);
			fractol->y++;
		}
		fractol->x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}
void	mandelbrot(fractol_s *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WH, WH, "Mandelbrot");
	fractol->img.img = mlx_new_image(fractol->mlx, WH, WH);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	fractol->zoom = 1;
	fractol->color = 0x000000;
	fractol->max_iter = 330;
    fractol->shift_x = 0.0;
    fractol->shift_y = 0.0;
	mlx_key_hook(fractol->win, key_hook, fractol);
	// mlx_hook(fractol->win, 2, 1L << 0, key_hook, &fractol);
	draw_mandelbrot(fractol);	
	// mlx_loop_hook(fractol->mlx, draw_mandelbrot, &fractol);
	mlx_loop(fractol->mlx);
}
