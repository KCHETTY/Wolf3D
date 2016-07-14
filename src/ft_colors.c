/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:10:44 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/26 13:05:35 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_extend_2(t_glob *g, float x, int y)
{
	if (g->env.map[g->p.map_x][g->p.map_y] == 4)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 235;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 247;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 141;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 5)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 247;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 141;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 185;
	}
}

void	ft_colors_2(t_glob *g, float x, int y)
{
	if (g->ray.side == 0)
	{
		if (g->env.map[g->p.map_x][g->p.map_y] == 1)
		{
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 242;
			g->env.data[((int)x * 4) + (y * g->env.size_line)] = 105;
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 90;
		}
		if (g->env.map[g->p.map_x][g->p.map_y] == 2)
		{
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 106;
			g->env.data[((int)x * 4) + (y * g->env.size_line)] = 247;
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 106;
		}
		if (g->env.map[g->p.map_x][g->p.map_y] == 3)
		{
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 129;
			g->env.data[((int)x * 4) + (y * g->env.size_line)] = 131;
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 247;
		}
		ft_extend_2(g, x, y);
	}
}

void	ft_extend(t_glob *g, float x, int y)
{
	if (g->env.map[g->p.map_x][g->p.map_y] == 4)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 162;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 227;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 32;
	}
	if (g->env.map[g->p.map_x][g->p.map_y] == 5)
	{
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 212;
		g->env.data[((int)x * 4) + (y * g->env.size_line)] = 15;
		g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 90;
	}
}

void	ft_colors(t_glob *g, float x, int y)
{
	if (g->ray.side == 1)
	{
		if (g->env.map[g->p.map_x][g->p.map_y] == 1)
		{
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 242;
			g->env.data[((int)x * 4) + (y * g->env.size_line)] = 70;
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 17;
		}
		if (g->env.map[g->p.map_x][g->p.map_y] == 2)
		{
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 29;
			g->env.data[((int)x * 4) + (y * g->env.size_line)] = 222;
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 29;
		}
		if (g->env.map[g->p.map_x][g->p.map_y] == 3)
		{
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 29;
			g->env.data[((int)x * 4) + (y * g->env.size_line)] = 58;
			g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 222;
		}
		ft_extend(g, x, y);
	}
	ft_colors_2(g, x, y);
}
