/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:05:51 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/13 09:23:39 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	write(2, "Error\n", 6);
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

double	ft_atod(t_fractol *fractol, char *str)
{
	fractol->atod.result = 0.0;
	fractol->atod.part = 0.0;
	fractol->atod.sign = 1.0;
	fractol->atod.i = 0;
	fractol->atod.place = 0.1;
	while (ft_isspace(str[fractol->atod.i++]))
		;
	if (str[--fractol->atod.i] == '-' || str[fractol->atod.i] == '+')
		if (str[fractol->atod.i++] == '-')
			fractol->atod.sign = -1;
	if (!str[fractol->atod.i])
		exit(EXIT_FAILURE);
	while (str[fractol->atod.i] && str[fractol->atod.i] != '.'
		&& ft_isdigit(str[fractol->atod.i]))
		fractol->atod.result = fractol->atod.result * 10
			+ str[fractol->atod.i++] - '0';
	if (str[fractol->atod.i] == '.')
		fractol->atod.i++;
	while (str[fractol->atod.i] && ft_isdigit(str[fractol->atod.i]))
	{
		fractol->atod.part = fractol->atod.part + (str[fractol->atod.i++] - '0')
			* fractol->atod.place;
		fractol->atod.place /= 10;
	}
	return (fractol->atod.sign * (fractol->atod.result += fractol->atod.part));
}
