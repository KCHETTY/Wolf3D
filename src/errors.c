/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:23:40 by kchetty           #+#    #+#             */
/*   Updated: 2016/06/26 12:56:02 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_error(int err)
{
	if (err == 1)
	{
		ft_putstr("Encountered a malloc error\n");
	}
	if (err == 2)
	{
		ft_putstr("Invalid map file\n");
		ft_putstr("Usage ./wolf3d map.txt\n");
	}
	if (err == 3)
	{
		ft_putstr("Error opening file\n");
	}
	exit(1);
}
