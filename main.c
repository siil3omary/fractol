/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelomari <aelomari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:43:00 by aelomari          #+#    #+#             */
/*   Updated: 2024/03/29 19:50:12 by aelomari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include <stdio.h>
#include <math.h>

int main() {
    // Define constants
    double Z_real, Z_imag; // Real and imaginary parts of Z
    double C_real = 0, C_imag = 0.65; // Real and imaginary parts of C
    int maxIterations = 1000; // Maximum number of iterations
    int n;
    
    // Start with an initial value of Z (for example, Z = 0)
    Z_real = 0;
    Z_imag = 0;
    
    // Iterate the formula Z_{n+1} = Z_{n}^2 + C
    for (n = 0; n < maxIterations; ++n) {
        // Calculate the next iteration
        double Z_real_next = Z_real * Z_real - Z_imag * Z_imag + C_real;
        double Z_imag_next = 2 * Z_real * Z_imag + C_imag;
        
        // Update Z
        Z_real = Z_real_next;
        Z_imag = Z_imag_next;
        
        // Calculate the magnitude of Z
        double magnitude = sqrt(Z_real * Z_real + Z_imag * Z_imag);
        
        // Check if the magnitude of Z exceeds a certain threshold (e.g., 2)
        if (magnitude > 2.0) {
            printf("Diverges after %d iterations.\n", n);
            break;
        }
    }
    
    // If the loop completes without diverging, Z may be within the Mandelbrot set
    if (n == maxIterations) {
        printf("Likely within the Mandelbrot set.\n");
    }
    
    return 0;
}
