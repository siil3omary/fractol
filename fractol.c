/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:45:48 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/28 00:27:20 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/fractol.h"

int	main(int ac , char **av)
{
    if (ac == 2 && !ft_strncmp(av[1] ,"mandelbrot", 10))
    {
        mandelbrot(NULL);
    }
    else if ((ac == 2 || ac == 4 ) && !ft_strncmp(av[1] ,"julia", 5))
    {
        julia(NULL);
    }
    else if (ac == 2 && !ft_strncmp(av[1] ,"burningship", 11))
    {
        printf("burningship\n");
    }
    
	return (0);
}