/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:10:52 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/22 14:48:03 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_window(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (1);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3d");
	if (!cub->win)
		return (1);
	return (0);
}
