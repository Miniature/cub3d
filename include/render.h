#ifndef RENDER_H
# define RENDER_H

# include "gamestate.h"
# include "raycasting.h"
# include "mlx.h"

int		render_raycasting(t_gamewindow *gw);
int		get_colour(t_gamewindow *gw, int x, int y, int i);

t_gamestate_perspective *raycasting_perspective_init();

void	b_img_pix_put(t_gamewindow *gw, int x, int y, int color);
void	draw_column(t_gamewindow *gw, int x);
#endif
