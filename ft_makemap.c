/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:02:51 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/22 14:31:14 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

char	**ft_makemap(char **tab, size_t size)
{
	size_t	i;
	size_t	j;

	if (tab)
		ft_strdel(tab);
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * size + 1)))
		ft_puterror("error");
	while (i < size)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * size + 1)))
			ft_puterror("error");
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
		tab[i++][j] = 0;
	}
	i = 0;
	tab[size] = NULL;
	return (tab);
}
