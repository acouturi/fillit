/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:14:30 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/24 10:27:18 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	ft_forme(const char *piece)
{
	int		i;
	int		mem;

	i = 0;
	mem = 0;
	if ((ft_strlen(piece) + 1) % 21 != 0 || ft_strlen(piece) == 0)
		ft_puterror("error");
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (piece[i + 1] == '#')
				mem++;
			if ((i + 1) % 21 < 15)
				if (piece[i + 5] == '#')
					mem++;
		}
		if ((i + 1) % 21 == 20)
		{
			if (mem != 3 && mem != 4)
				ft_puterror("error");
			mem = 0;
		}
		i++;
	}
}

void		ft_valide(const char *piece)
{
	int		i;
	int		mem;

	i = 0;
	mem = 0;
	while (piece[i])
	{
		if ((((i + 1) % 21) % 5) == 0)
		{
			if (piece[i] != '\n')
				ft_puterror("error");
		}
		else if (piece[i] == '#')
			mem++;
		else if (piece[i] != '.')
			ft_puterror("error");
		if ((i++ + 1) % 21 == 20)
		{
			if (mem != 4)
				ft_puterror("error");
			mem = 0;
		}
	}
	ft_forme(piece);
}
