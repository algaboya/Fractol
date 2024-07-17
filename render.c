/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:23:08 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/11 16:08:23 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_my_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bit_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	mandel_or_julia(t_compl *z, t_compl *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->rx = fractol->julia_x;
		c->iy = fractol->julia_y;
	}
	else
	{
		c->rx = z->rx;
		c->iy = z->iy;
		z->rx = 0;
		z->iy = 0;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	int		i;
	int		color;
	t_compl	z;
	t_compl	c;

	i = 0;
	z.rx = (map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->x_shift;
	z.iy = (map(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->y_shift;
	mandel_or_julia(&z, &c, fractol);
	while (i < fractol->iter_num)
	{
		z = sum_comp(square_comp(z), c);
		if ((z.rx * z.rx) + (z.iy * z.iy) > fractol->escape_val)
		{
			color = map(i, BLACK, WHITE, fractol->iter_num);
			put_my_pixel(x, y, &fractol->image, color);
			return ;
		}
		i++;
	}
	put_my_pixel(x, y, &fractol->image, BLACK);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connect, fractol->mlx_window,
		fractol->image.image_ptr, 0, 0);
}
