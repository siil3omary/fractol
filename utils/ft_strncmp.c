/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:16:22 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/28 00:22:01 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;

	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	while (n--)
	{
		if (*str != *ptr)
			return (*str - *ptr);
		if (*str == '\0' || *ptr == '\0')
			return (0);
		str++;
		ptr++;
	}
    if(*str == '\0' && *ptr == '\0')
        return (0);
	return (1);
}