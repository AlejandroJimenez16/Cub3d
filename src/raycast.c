/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:50:36 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/25 21:51:24 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_ray(t_ray *ray, t_cub *cub, int px)
{
	ray->camera_x = 2 * px / (double)WIDTH - 1;	
}

void	raycast_loop(t_cub *cub)
{
	t_ray	ray;
	int		i;

	i = -1;
	while (++i < WIDTH)
	{
		// 1. INIT RAY
		init_ray(&ray, cub, i);
	}
}