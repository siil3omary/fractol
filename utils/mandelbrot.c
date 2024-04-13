/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:23:10 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/13 00:03:05 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	drawit(t_fractol *fractol)
{
	int	i;

	i = 0;
	fractol->zr = 0.0;
	fractol->zi = 0.0;
	fractol->cr = (scalefractol(fractol->x, 0, -2, 2) / fractol->zoom)
		+ fractol->shift_x;
	fractol->ci = (scalefractol(fractol->y, 0, -2, 2) / fractol->zoom)
		+ fractol->shift_y;
	while (i < fractol->max_iter && is_in_range(fractol->zr, fractol->zi))
	{
		fractol->tmp = ((fractol->zr * fractol->zr) - (fractol->zi
					* fractol->zi)) + fractol->cr;
		fractol->zi = 2 * fractol->zr * fractol->zi + fractol->ci;
		fractol->zr = fractol->tmp;
		i++;
	}
	if (i == fractol->max_iter)
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, fractol->color);
	else
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, scalefractol(i,
				fractol->color, i, 0xFFFFFF));
}

int	draw_mandelbrot(t_fractol *fractol)
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

void	mandelbrot(t_fractol *fractol)
{
	fractol->set = 1;
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WH, WH, "Mandelbrot");
	fractol->img.img = mlx_new_image(fractol->mlx, WH, WH);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	init(fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_hook(fractol->win, 2, 1L << 0, key_hook, fractol);
	draw_mandelbrot(fractol);
	mlx_loop(fractol->mlx);
}
