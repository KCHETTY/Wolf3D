/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:24:11 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/26 12:55:41 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		loop_calc_3(t_glob *g)
{
	if (g->ray.side_dist_x < g->ray.side_dist_y)
	{
		g->ray.side_dist_x += g->ray.delta_dist_x;
		g->p.map_x += g->p.step_x;
		g->ray.side = 0;
	}
	else
	{
		g->ray.side_dist_y += g->ray.delta_dist_y;
		g->p.map_y += g->p.step_y;
		g->ray.side = 1;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] > 0)
		g->ray.detect_wall = 1;
	if (g->ray.side == 0)
		g->ray.perp_wall_dist = (g->p.map_x - g->ray.ray_pos_x +
				(1 - g->p.step_x) / 2) / g->ray.ray_dir_x;
	else
		g->ray.perp_wall_dist = (g->p.map_y - g->ray.ray_pos_y +
				(1 - g->p.step_y) / 2) / g->ray.ray_dir_y;
	g->ray.line_height = (int)(WIN_H / g->ray.perp_wall_dist);
	g->ray.draw_start = -g->ray.line_height / 2 + WIN_H / 2;
}

void		loop_calc_2(t_glob *g)
{
	if (g->ray.ray_dir_x < 0)
	{
		g->p.step_x = -1;
		g->ray.side_dist_x = (g->ray.ray_pos_x - g->p.map_x) *
			g->ray.delta_dist_x;
	}
	else
	{
		g->p.step_x = 1;
		g->ray.side_dist_x = (g->p.map_x + 1.0 - g->ray.ray_pos_x) *
			g->ray.delta_dist_x;
	}
	if (g->ray.ray_dir_y < 0)
	{
		g->p.step_y = -1;
		g->ray.side_dist_y = (g->ray.ray_pos_y - g->p.map_y) *
			g->ray.delta_dist_y;
	}
	else
	{
		g->p.step_y = 1;
		g->ray.side_dist_y = (g->p.map_y + 1.0 - g->ray.ray_pos_y) *
			g->ray.delta_dist_y;
	}
}

void		loop_calc_1(t_glob *g, float *x)
{
	g->ray.camera_x = 2 * *x / WIN_W - 1;
	g->ray.ray_pos_x = g->p.pos_x;
	g->ray.ray_pos_y = g->p.pos_y;
	g->ray.ray_dir_x = g->p.dir_x + g->ray.plane_x * g->ray.camera_x;
	g->ray.ray_dir_y = g->p.dir_y + g->ray.plane_y * g->ray.camera_x;
	g->p.map_x = (int)g->ray.ray_pos_x;
	g->p.map_y = (int)g->ray.ray_pos_y;
	g->ray.delta_dist_x = sqrt(1 + (g->ray.ray_dir_y * g->ray.ray_dir_y) /
			(g->ray.ray_dir_x * g->ray.ray_dir_x));
	g->ray.delta_dist_y = sqrt(1 + (g->ray.ray_dir_x * g->ray.ray_dir_x) /
			(g->ray.ray_dir_y * g->ray.ray_dir_y));
	g->ray.detect_wall = 0;
}

void		loops_hook(t_glob *g)
{
	float		x;
	int			y;

	x = 0;
	while (x < WIN_W)
	{
		loop_calc_1(g, &x);
		loop_calc_2(g);
		while (g->ray.detect_wall == 0)
		{
			loop_calc_3(g);
			if (g->ray.draw_start < 0)
				g->ray.draw_start = 0;
			g->ray.draw_end = g->ray.line_height / 2 + WIN_H / 2;
			if (g->ray.draw_end >= WIN_H)
				g->ray.draw_end = WIN_H - 1;
		}
		y = g->ray.draw_start;
		while (y <= g->ray.draw_end)
		{
			ft_colors(g, x, y);
			y++;
		}
		x += 0.5;
	}
}
