/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:24:00 by algaboya          #+#    #+#             */
/*   Updated: 2024/07/07 20:25:40 by algaboya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_compl	sum_comp(t_compl a, t_compl b)
{
	t_compl	res;

	res.rx = a.rx + b.rx;
	res.iy = a.iy + b.iy;
	return (res);
}

t_compl	square_comp(t_compl z)
{
	t_compl	res;

	res.rx = (z.rx * z.rx) - (z.iy * z.iy);
	res.iy = 2 * z.rx * z.iy;
	return (res);
}
