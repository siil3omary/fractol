/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:09:15 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/13 00:12:24 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_utils(t_fractol *fractol, int keycode)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 18)
		fractol->max_iter += 10;
	if (keycode == 78 || keycode == 19)
		fractol->max_iter -= 10;
	if (keycode == 123)
		fractol->shift_x -= 0.1;
	if (keycode == 124)
		fractol->shift_x += 0.1;
	if (keycode == 126)
		fractol->shift_y -= 0.1;
	if (keycode == 125)
		fractol->shift_y += 0.1;
	if (keycode == 24)
		fractol->zoom *= 1.1;
	key_utils2(fractol, keycode);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode)
		key_utils(fractol, keycode);
	if (keycode == 49)
		fractol->color += 500;
	if (keycode == 15)
		init(fractol);
	if (keycode == 4)
		return (string_put(fractol));
	if (fractol->set == 1)
		draw_mandelbrot(fractol);
	if (fractol->set == 2)
		draw_julia(fractol);
	if (fractol->set == 3)
		draw_brurningship(fractol);
	return (0);
}

int	string_put(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->win);
	mlx_string_put(fractol->mlx, fractol->win, 10, 10, 0xFFFFFF,
		"Press m for Mandelbrot");
	mlx_string_put(fractol->mlx, fractol->win, 10, 30, 0xFFFFFF,
		"Press j for Julia");
	mlx_string_put(fractol->mlx, fractol->win, 10, 50, 0xFFFFFF,
		"Press b for Brurningship");
	mlx_string_put(fractol->mlx, fractol->win, 10, 90, 0xFFFFFF,
		"Press + or - for zoom");
	mlx_string_put(fractol->mlx, fractol->win, 10, 130, 0xFFFFFF,
		"Press r for rest");
	mlx_string_put(fractol->mlx, fractol->win, 10, 90, 0xFFFFFF,
		"Press + or - for zoom");
	mlx_string_put(fractol->mlx, fractol->win, 10, 110, 0xFFFFFF,
		"Press arrow keys for shift");
	mlx_string_put(fractol->mlx, fractol->win, 10, 70, 0xFFFFFF,
		"Press ESPACE for color");
	mlx_string_put(fractol->mlx, fractol->win, 10, 150, 0xFFFFFF,
		"Press ESC for exit");
	return (0);
}
