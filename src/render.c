/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:12:12 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/29 13:54:19 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_square(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(cub->mlx, cub->win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_ray(t_cub *cub, t_ray *ray, int color)
{
	t_line	line;
	int		i;

	// 1. Escalamos a pixeles de la pantalla
	line.x1 = cub->player.x * TILE_SIZE;
	line.y1 = cub->player.y * TILE_SIZE;
	line.x2 = ray->hit_x * TILE_SIZE;
	line.y2 = ray->hit_y * TILE_SIZE;

	// 2. Calculamos distancia
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	
	// 3. Determinamos el numero de pasos en base a la distancia mas larga
	if (fabs(line.dx) > fabs(line.dy))
		line.steps = fabs(line.dx);
	else
		line.steps = fabs(line.dy);

	// 4. Calculamos la distancia que se movera a cada vuelta
	line.move_x = line.dx / line.steps;
	line.move_y = line.dy / line.steps;
	
	// 5. Asigno donde empieza a dibujar
	line.current_x = line.x1;
	line.current_y = line.y1;

	// 6. Dibujo cada pixel de la linea
	i = -1;
	while (++i <= line.steps)
	{
		mlx_pixel_put(cub->mlx, cub->win, line.current_x, line.current_y, color);
		line.current_x += line.move_x;
		line.current_y += line.move_y;
	}
}

void	draw_2d_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			if (cub->map.grid[y][x] == '1')
				draw_square(cub, x * TILE_SIZE, y * TILE_SIZE, 0x0000FF);
			else if (cub->map.grid[y][x] == '0')
				draw_square(cub, x * TILE_SIZE, y * TILE_SIZE, 0x000000);
			x++;
		}
		y++;
	}
	draw_square(cub, (cub->player.x * TILE_SIZE) - TILE_SIZE / 2, (cub->player.y * TILE_SIZE) - TILE_SIZE / 2, 0xFFFF00);
}
