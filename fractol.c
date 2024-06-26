/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:45:48 by aelomari          #+#    #+#             */
/*   Updated: 2024/04/13 09:26:08 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	vars;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		mandelbrot(&vars);
	else if ((ac == 2 || ac == 4) && !ft_strncmp(av[1], "julia", 5))
	{
		if (ac == 2)
			julia(&vars, -0.4, 0.6);
		else
			julia(&vars, ft_atod(&vars, av[2]), ft_atod(&vars, av[3]));
	}
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 11))
		brurningship(&vars);
	else
	{
		write(2, "\033[0;31mUsage: \e[0m\n", 19);
		write(2, " ./fractol [mandelbrot | julia | burningship]", 46);
		exit(EXIT_FAILURE);
	}
	return (0);
}
