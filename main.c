/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:43:00 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/28 05:44:48 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include <stdio.h>



int	main(void)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;
	void	*par;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hello");
	i = -2 * 10;
	while (i < 2 * 10)
	{
		j = -2 * 10;
		while (j < 2 * 10)
		{
			mlx_pixel_put(mlx, win, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
