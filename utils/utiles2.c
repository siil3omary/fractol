/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:05:51 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/13 00:10:01 by aelomari         ###   ########.fr       */
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
