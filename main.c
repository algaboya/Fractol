/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:01:04 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/11 18:23:45 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		{
			fractol.julia_x = ft_atodbl(argv[2]);
			fractol.julia_y = ft_atodbl(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connect);
	}
	else
		exit(EXIT_FAILURE);
	system("leaks fractol");
}
