/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optipose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:41:20 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/24 10:31:52 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft/libft.h"

static int	ft_tryplace(char **map, t_piece *piece)
{
	int x;
	int y;

	y = 0;
	while (piece->forme[y])
	{
		x = 0;
		while (piece->forme[y][x])
		{
			if (map[piece->posy + y][piece->posx + x] != '.')
			{
				if (piece->forme[y][x] != '.')
					return (0);
			}
			else if (piece->forme[y][x] != '.')
				map[piece->posy + y][piece->posx + x] = piece->valu;
			x++;
		}
		y++;
	}
	return (1);
}

static void	ft_remplace(char **map, t_piece *piece)
{
	int x;
	int y;

	y = 0;
	while (piece->forme[y])
	{
		x = 0;
		while (piece->forme[y][x])
		{
			if (map[piece->posy + y][piece->posx + x] == piece->valu)
				map[piece->posy + y][piece->posx + x] = '.';
			x++;
		}
		y++;
	}
}

static int	ft_place(char **map, t_piece *piece, int size)
{
	int		ok;

	ok = 0;
	if (ft_tryplace(map, piece))
	{
		if (!(ok = ft_optipose(map, piece->next, size)))
			ft_remplace(map, piece);
	}
	else
		ft_remplace(map, piece);
	return (ok);
}

int			ft_optipose(char **map, t_piece *piece, int size)
{
	int		ok;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ok = 0;
	if (!piece)
		return (1);
	while (!ok)
	{
		piece->posx = x++;
		piece->posy = y;
		ok = ft_place(map, piece, size);
		if (x + piece->size_x >= size && !ok)
		{
			x = 0;
			y++;
			if (y + piece->size_y >= size)
				return (0);
		}
	}
	return (1);
}
