/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 08:39:07 by jumarque          #+#    #+#             */
/*   Updated: 2025/03/24 09:42:38 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1600
# define HEIGHT 900
/* Colors                     */
# define WHITE 0xFFFFFF
# define BLACK 0X000000
# define GREY 0X636363
/* Keycodes                   */
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_MENUS 65453
# define KEY_PLUS 65451
# define KEY_Q 113
# define KEY_E 101
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_P 112
# define KEY_F 102
# define KEY_PAD0 65460
# define KEY_PAD7 65457
# define KEY_PAD2 65462
# define KEY_PAD5 65459

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_smem
{
	int		**array;
	int		**color;
	char	**line;
	t_list	*list;
	int		len;
	int		wid;
}			t_smem;

typedef struct s_img
{
	void	*img_ptr;
	char	*img;
	int		bpp;
	int		sl;
	int		endian;
}			t_img;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		**array;
	int		length;
	int		width;
	double	height;
	double	scale;
	int		z_max;
	int		z_min;
	double	z_mid;
	double	x_offset;
	double	y_offset;
	double	x_origin;
	double	y_origin;
	int		**color;
	int		cnum;
	int		tpro;
	int		wire;
	double	cte1;
	double	cte2;
	double	cte3;
	double	cte4;
	int		x;
	int		y;
	int		z;
	t_img	img;
	double	pasx;
	double	pasy;
	double	pasy1;
	double	pasy2;
	double	pasz;
	double	pasz1;
	double	pasz2;
	t_smem	*mem;
}			t_env;

typedef struct s_color
{
	int		color1;
	int		color2;
}			t_color;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}			t_coord;

typedef struct s_mcoord
{
	t_coord	p1;
	t_coord	p2;
	t_coord	p3;
	t_coord	p4;
}			t_mcoord;

////    display.c    ////
void	ft_displaytab(t_smem *mem);
void	ft_line(t_env *e, t_coord *c1, t_coord *c2);
void	ft_mlx_fill_image(t_env *e);
int		ft_exposehook(t_env *e);
void	ft_displaymenu(t_env *e);

////    parallel.c    ////
void	ft_parallel(t_env *e);

////    isometric.c    ////
void	ft_isometric(t_env *e);
void	ft_isometricf(t_env *e);

////    command.c    ////
void	ft_revarray(t_env *e, int dir, t_smem *mem);
void	ft_getcolor(t_smem *mem, char **argv, int argc);
int		*ft_putcolor(t_smem *mem, int r, int g, int b);
int		**ft_tabmalloc(int x, int y);

////    env.c    ////
t_env	ft_initenv(t_smem *mem);
void	ft_getminmax(t_env *e);
void	ft_absarray(t_env *e);
void	ft_initimg(t_env *e);
void	ft_initsmem(t_smem *mem);

////    color.c    ////
int		ft_getlevel(t_env *e, double z);
float	ft_fabs(float value);
int		ft_abs(int result);

////    height.c    ////
void	ft_horline(t_env *e, t_coord *p1, t_coord *p2, int x);

////    eventkey.c    //// 
int		ft_eventkey(t_env *e, int keycode, t_smem *mem);
void	ft_eventkey2(t_env *e, int keycode);
void	ft_displayparam(t_env *e);

////    draw_triangle.c    ////
void	ft_pixelput(t_env *e, int x, int y, int color);
void	ft_drawtriangle(t_coord *p1, t_coord *p2, t_coord *p3, t_env *e);

////    fdf.c    ////
void	ft_getarray(int fd, t_smem *mem);
t_list	*get_lstfile(int fd, int *len);
int		ft_tablen(char **array);
int		*put_array(t_smem *mem);

////    error.c    ////
void	ft_error(t_smem *mem, int value);
void	ft_free(char **buff01, char **buff02);
int 	ft_close_window(t_env *data);

////	clean.c    //// 
int		**ft_freearray(int **array, int wid, int len);
int		**ft_freecolor(int **color);
char	**ft_freeline(char **line);

////    draw.c    ////
void	ft_drawline(t_env *e, t_coord *p1, t_coord *p2);

#endif
