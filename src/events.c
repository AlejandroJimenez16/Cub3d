/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:24:57 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/30 14:01:46 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_key_press(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keycode == 65307)
		close_window(cub);
	if (keycode == KEY_W)
		cub->keys.w = 1;
	else if (keycode == KEY_A)
		cub->keys.a = 1;
	else if (keycode == KEY_S)
		cub->keys.s = 1;
	else if (keycode == KEY_D)
		cub->keys.d = 1;
	return (0);
}

int	handle_key_release(int keycode, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (keycode == KEY_W)
		cub->keys.w = 0;
	else if (keycode == KEY_A)
		cub->keys.a = 0;
	else if (keycode == KEY_S)
		cub->keys.s = 0;
	else if (keycode == KEY_D)
		cub->keys.d = 0;
	return (0);
}

static int	move_player(t_cub *cub)
{
	if (cub->keys.w)
		return (
			cub->player.x += cub->player.dir_x * MOVE_SPEED,
			cub->player.y += cub->player.dir_y * MOVE_SPEED, 1
		);
	if (cub->keys.a)
		return (
			cub->player.x -= cub->player.plane_x * MOVE_SPEED,
			cub->player.y -= cub->player.plane_y * MOVE_SPEED, 1
		);
	if (cub->keys.s)
		return (
			cub->player.x -= cub->player.dir_x * MOVE_SPEED,
			cub->player.y -= cub->player.dir_y * MOVE_SPEED, 1
		);
	if (cub->keys.d)
		return (
			cub->player.x += cub->player.plane_x * MOVE_SPEED,
			cub->player.y += cub->player.plane_y * MOVE_SPEED, 1
		);
	return (0);
}

int	handle_move(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (move_player(cub))
	{
		mlx_clear_window(cub->mlx, cub->win);
		draw_2d_map(cub);
		raycast_loop(cub);
	}
	return (0);
}
