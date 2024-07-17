/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:26:45 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/11 18:18:12 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connect, fractol->image.image_ptr);
	mlx_destroy_window(fractol->mlx_connect, fractol->mlx_window);
	system("leaks fractol");
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == ON_MOUSEDOWN)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == ON_MOUSEUP)
		fractol->zoom *= 1.05;
	fractol_render(fractol);
	return (0);
}

int	mouse_julia(int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = (map(x, -2, +2, WIDTH) * fractol->zoom)
			+ fractol->x_shift;
		fractol->julia_y = (map(y, -2, +2, WIDTH) * fractol->zoom)
			+ fractol->y_shift;
		fractol_render(fractol);
	}
	return (0);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == KEY_ESCAPE)
		close_handler(fractol);
	if (keysym == KEY_RIGHT)
		fractol->x_shift -= 0.5;
	else if (keysym == KEY_LEFT)
		fractol->x_shift += 0.5;
	else if (keysym == KEY_UP)
		fractol->y_shift -= 0.5;
	else if (keysym == KEY_DOWN)
		fractol->y_shift += 0.5;
	else if (keysym == KEY_PLUS)
		fractol->iter_num += 10;
	else if (keysym == KEY_MINUS)
		fractol->iter_num -= 10;
	fractol_render(fractol);
	return (0);
}
