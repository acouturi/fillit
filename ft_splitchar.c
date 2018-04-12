/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:14:05 by lbaumann          #+#    #+#             */
/*   Updated: 2017/11/22 15:24:47 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static void		ft_creaforme(char *str, t_piece *temp, int y, int x)
{
	int		i;
	int		j;
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * y + 1)))
		ft_puterror("error");
	i = 0;
	while (i < y)
	{
		tab[i] = (char*)malloc(sizeof(char) * temp->size_x + 1);
		j = 0;
		while (j < temp->size_x)
		{
			tab[i][j] = str[i * 5 + j + x];
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	tab[i] = 0;
	temp->forme = tab;
}

static void		ft_reducex(char *str, t_piece *temp, int y)
{
	int		size_x;
	int		i;
	int		j;
	int		mem;
	int		x;

	j = -1;
	size_x = 0;
	x = 5;
	while (++j < 4)
	{
		i = y;
		mem = 0;
		while (i-- > 0)
			if (str[i * 5 + j] == '#')
				mem++;
		if (mem > 0)
		{
			size_x++;
			if (x == 5)
				x = j;
		}
	}
	temp->size_x = size_x;
	ft_creaforme(str, temp, y, x);
}

void			ft_splitopti(char *str, t_piece *temp, int i)
{
	char	*mem;
	int		y;

	mem = str;
	while (*str != '#')
		if (*str++ == '\n')
			mem = str;
	str = mem;
	ft_strrev(str);
	while (*str != '#')
		if (*str++ == '\n')
			mem = str;
	str = mem;
	ft_strrev(str);
	i = ft_strlen(str);
	ft_memmove(&str[-1], str, i);
	str--;
	str[i] = '\n';
	i = 0;
	y = 0;
	while (str[i])
		if (str[i++] == '\n')
			y++;
	temp->size_y = y;
	ft_reducex(str, temp, y);
}

static t_piece	*ft_getfirstone(t_piece *list, char *str, char index)
{
	t_piece *temp;

	if (index > 'Z')
		ft_puterror("error");
	if (!(temp = (t_piece *)malloc(sizeof(t_piece))))
		ft_puterror("error");
	ft_splitopti(str, temp, 0);
	temp->next = NULL;
	temp->valu = index;
	if (list)
		list->next = temp;
	return (temp);
}

t_piece			*ft_splitchar(char *s)
{
	char	temp[21];
	int		i;
	int		j;
	t_piece *firstone;
	t_piece *current;

	firstone = NULL;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (j < 20)
			temp[j++] = s[i++];
		temp[j] = '\0';
		if (!firstone)
		{
			firstone = ft_getfirstone(firstone, temp, i / 21 + 'A');
			current = firstone;
		}
		else
			current = ft_getfirstone(current, temp, i / 21 + 'A');
		if (s[i])
			i++;
	}
	return (firstone);
}
