/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:10 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/19 12:51:26 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/src/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 600
# define HEIGHT 600
# define IMG_SIZE 16
# define ZOOM 4
# define BLOCK 64

typedef struct s_valid
{
	char	c[1];
	int		fd;
	int		bytes_read;
	int		collectible;
	int		exit;
	int		size;
	int		start;
	int		invalid;
	size_t	n;
}	t_valid;

typedef struct s_sprites
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int32_t			x;
	int32_t			y;
}	t_sprites;

typedef struct s_game
{
	size_t			cols;
	size_t			rows;
	int				player_x;
	int				player_y;
	int				collected;
	int				remove_collected;
	int				count_moves;
	int				flag;
	char			buffer[11];
	char			*content;
	char			*aux;
	char			**matrix;
	char			**clone;
	mlx_t			*mlx;
	t_sprites		*player_data;
	t_sprites		*wall_data;
	t_sprites		*bg_data;
	t_sprites		*collect_data;
	t_sprites		*exit_data;
}	t_game;

//validation
int			validate_map(int argc, char **argv, t_game *game);
int			open_file(char *map_file);
int			read_file_content(int fd, t_valid *map, int bytes);
int			check_arguments(int argc, char **argv);
int			check_extension(char *filename);
int			check_content(int fd, t_valid *map);
int			check_content_aux(t_valid *map);
int			check_invalid_char(t_valid	*map);
void		init_variables_game(t_game *game);
void		init_variables_valid(t_valid *valid);
void		error(char *str);

//matrix
int			build_matrix(int fd, t_game *game);
int			surrounded_by_walls(t_game *game);
int			is_rectangle(t_game *game, t_valid *map);
void		free_matrix(char **matrix_delete);
void		free_matrices(t_game *game);

//flood fill
void		flood_fill_aux(t_game *matrix, size_t row, size_t col);
void		flood_fill(t_game *game);
int			check_clone_content(t_game *game);

//images
t_sprites	*init_generic_images(t_game *game, char *path);
void		init_textures(t_game *game);
int			put_images(t_game *game);
int			put_player(t_game *game);
int			put_wall(t_game *game, int c, int l);
int			put_collectible(t_game *game, int c, int l);
int			put_exit(t_game *game, int c, int l);
void		upt_collectible(t_game *game);
void		upt_exit(t_game *game);
void		free_sprite(t_game *game, t_sprites *sprite);

//game
int			window(t_game *game);
int			valid_moves(t_game *game, char position, char op);
void		ft_error(t_game *game);
void		hook_close(void *param);

# define WARNING_1	"Error:\nPlease insert a map.\n"
# define WARNING_2	"Error:\nToo many arguments.\n"
# define WARNING_3	"Error:\nWrong extension.\n"
# define WARNING_4	"Error:\nNon-existent file or error opening the file.\n"
# define WARNING_5	"Error:\nAllocate memory.\n"
# define WARNING_6	"Error:\nInsufficient characters or empty map.\n"
# define WARNING_7	"Error:\nInvalid characters in the map.\n"
# define WARNING_8	"Error:\nNon-rectangular map.\n"
# define WARNING_9	"Error:\nThe player is not positioned correctly.\n"
# define WARNING_10	"Error:\nThe map does not have a valid exit.\n"
# define WARNING_11	"Error:\nAt least 1 collectible.\n"
# define WARNING_12	"Error:\nNot surrounded by walls.\n"
# define WARNING_13	"Error:\nPlayer arrested.\n"
# define WARNING_14	"Error:\nRead the file.\n"
# define WARNING_15	"Error:\nInvalid map.\n"
# define WARNING_16	"Error:\nAllocate image.\n"

#endif
