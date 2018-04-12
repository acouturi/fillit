/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:46:41 by acouturi          #+#    #+#             */
/*   Updated: 2017/11/22 15:29:33 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <string.h>

typedef struct	s_piece
{
	int				size_x;
	int				size_y;
	int				posx;
	int				posy;
	char			valu;
	char			**forme;
	struct s_piece	*next;
}				t_piece;

char			*ft_readfile(char *namefile);
t_piece			*ft_splitchar(char *s);
void			ft_valide(char *piece);
char			**ft_makemap(char **tab, size_t size);
void			ft_affiche(char **map);
int				ft_optipose(char **map, t_piece *piece, int size);

#endif
