/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:28:04 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/24 11:22:12 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "struct.h"
#include <stdio.h>

static char		*ft_check(int argc, char **argv)
{
	char	*content;

	if (argc != 2)
		ft_puterror("error");
	content = ft_readfile(argv[1]);
	if (!content)
		ft_puterror("error");
	return (content);
}

static int		ft_whatsize(char *content, t_piece *firstone)
{
	int		size;
	int		i;
	t_piece	*piece;

	size = 0;
	piece = firstone;
	i = ((ft_strlen(content) + 1) / 21) * 4;
	while (size * size < i)
		size++;
	while (size < 4 && piece)
	{
		if (piece->size_x > size)
			size = piece->size_x;
		if (piece->size_y > size)
			size = piece->size_y;
		piece = piece->next;
	}
	return (size);
}

int				main(int argc, char **argv)
{
	char	**tab;
	t_piece	*firstone;
	char	*content;
	int		size;
	int		ok;

	content = ft_check(argc, argv);
	ft_valide(content);
	firstone = ft_splitchar(content);
	tab = NULL;
	size = ft_whatsize(content, firstone);
	ok = 0;
	while (!ok)
	{
		tab = ft_makemap(tab, size++);
		ok = ft_optipose(tab, firstone, size);
	}
	ft_affiche(tab);
	return (0);
}
