#ifndef RENDER_H
# define RENDER_H

# include "gamestate.h"
# include "mlx.h"

int		render(t_gamewindow *gw);
void	img_pix_put(t_gamewindow *gw, t_mlx_image *img, int x, int y, int color);

#endif