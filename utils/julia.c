/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:23:39 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/31 23:59:05 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(fractol_s *fractol, double cr, double ci)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WH, WH, "Julia Set");
	fractol->img.img = mlx_new_image(fractol->mlx, WH, WH);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
											&fractol->img.bits_per_pixel,
											&fractol->img.line_length,
											&fractol->img.endian);
	init(fractol);
    printf("%f\t %f" , cr, ci);
	fractol->ci = ci;
	fractol->cr = cr;
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_hook(fractol->win, 2, 1L << 0, key_hook, fractol);
	draw_julia(fractol);
	mlx_loop(fractol->mlx);
}

int	draw_julia(fractol_s *fractol)
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

static void	drawit(fractol_s *fractol)
{
	int i;

	i = 0;
	fractol->zr = (scalefractol(fractol->x, 0, 800, -2, 2) / fractol->zoom)
		+ fractol->shift_x;
	fractol->zi = (scalefractol(fractol->y, 0, 800, -2, 2) / fractol->zoom)
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
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, 0xFFFFFF);
	else
		my_mlx_pixel_put(fractol, fractol->x, fractol->y, scalefractol(i * 1.01,
					fractol->color, fractol->max_iter, 0, 0xFFFFFF));
}