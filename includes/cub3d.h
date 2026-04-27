/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:53:10 by alejandj          #+#    #+#             */
/*   Updated: 2026/04/27 14:44:54 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		player_count;
}			t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

// Ray info
typedef struct s_ray
{
	double	camera_x;		// Escala que determina la inclinacion de cada rayo (Izq: -1, Centro: 0, Derecha: 1)
	double	ray_dir_x;		// Direccion del rayo (eje X)
	double	ray_dir_y;		// Direccion del rayo (eje Y)
	
	int	map_x;				// Posicion X del rayo en el mapa
	int	map_y;				// Posicion X del rayo en el mapa
	
	double	delta_dist_x;	// Distancia que recorre el rayo para avanzar 1 unidad (eje X)
	double	delta_dist_y;	// Distancia que recorre el rayo para avanzar 1 unidad (eje Y)
	
	double	side_dist_x;	// Distancia que hay desde pj hasta donde esta ahora mismo el rayo (eje X)
	double	side_dist_y;	// Distancia que hay desde pj hasta donde esta ahora mismo el rayo (eje Y)

	int		step_x;			// Hacia donde va el rayo (Izq: -1, Der: 1, Arriba: -1, Abajo: 1)
	int		step_y;

	int		side;			// Indica con que cara de la pared se ha chocado (cara: norte/sur, cara: este/oeste)

	double	real_dist;		// Distancia real
}				t_ray;

typedef struct s_cub
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor_color;
	int			ceiling_color;
	int			elements_found; // Tracks if we hit the magic number 6
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
}				t_cub;

// debug.c (Must erase at end)
void	print_cub_debug(t_cub *cub);

// file_parser.c
void	check_file_extension(const char *path);
void	parse_file(int fd, t_cub *cub);

// map_extraction.c
void	extract_map_line(char *line, t_cub *cub);
void	pad_map(t_cub *cub);

// map_validation.c
void	validate_cub_map(t_cub *cub);

// set_visuals.c
int		parse_element(char *line, t_cub *cub);

// window.c
int		create_window(t_cub *cub);
int		close_window(t_cub *cub);

// events.c
int		handle_key(int keycode, void *param);

// raycast.c
void	raycast_loop(t_cub *cub);

// cub3d_utils.c
void	free_cub(t_cub *cub);
void	err_exit(t_cub *cub, char *message);

#endif