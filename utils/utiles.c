/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:13:52 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/09 19:58:59 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	old_zoom;

	mouse_x = scalefractol(x, 0, -2, 2) / fractol->zoom + fractol->shift_x;
	mouse_y = scalefractol(y, 0, -2, 2) / fractol->zoom + fractol->shift_y;
	old_zoom = fractol->zoom;
	if (button == 4)
	{
		fractol->zoom *= 1.1;
		fractol->shift_x -= (mouse_x * fractol->zoom / old_zoom)
			- scalefractol(x, 0, -2, 2);
		fractol->shift_y -= (mouse_y * fractol->zoom / old_zoom)
			- scalefractol(y, 0, -2, 2);
	}
	if (button == 5)
	{
		fractol->zoom /= 1.1;
		fractol->shift_x -= (mouse_x * fractol->zoom / old_zoom)
			- scalefractol(x, 0, -2, 2);
		fractol->shift_y -= (mouse_y * fractol->zoom / old_zoom)
			- scalefractol(y, 0, -2, 2);
	}
	draw_julia(fractol);
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

void	init(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->color = 1000;
	fractol->max_iter = 100;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	exit(EXIT_FAILURE);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	return (0);
}

double	ft_atod(char *str)
{
	double	result;
	double	part;
	double	sign;
	int		i;
	double	place;

	result = 0.0;
	part = 0.0;
	sign = 1;
	i = 0;
	place = 0.1;
	while (ft_isspace(str[i++]))
		;
	if (str[--i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		exit(EXIT_FAILURE);
	while (str[i] && str[i] != '.' && ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		part = part + (str[i++] - '0') * place;
		place /= 10;
	}
	return (sign * (result += part));
}
