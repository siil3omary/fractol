/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:13:52 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/30 02:49:16 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, fractol_s *fractol)
{
	printf("keycode: %d\n", keycode);
    if (keycode == 53)
        exit(0);
    if (keycode == 69)
        fractol->max_iter += 10;
    if (keycode == 78)
        fractol->max_iter -= 10;
    if(keycode == 126)

    if(keycode == 125)

    if(keycode == 123)

    if(keycode == 124)

    if (keycode == 49)
        fractol->color += 0x0000FF;
    if (keycode == 48)
        fractol->color -= 0x0000FF;
    if(keycode == 24)
        fractol->zoom *= 1.1;
    if(keycode == 27)
        fractol->zoom /= 1.1;
    printf("max_iter: %d\n", fractol->max_iter);
    draw_mandelbrot(fractol);
    
        

	return (0);
}