#ifndef RENDER_H
# define RENDER_H

# include "gamestate.h"
# include "raycasting.h"
# include "mlx.h"

int		render(t_gamewindow *gw);
int		build_argb(int a, int r, int g, int b);
t_gamestate_perspective *raycasting_perspective_init();

void	img_pix_put(t_gamewindow *gw, t_mlx_image *img, int x, int y, int color);
void	draw_column(t_gamewindow *gw, int x);
#endif