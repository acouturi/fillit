/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2017/11/22 14:30:11 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "struct.h"
#include <fcntl.h>
#include <unistd.h>

char	*ft_readfile(char *namefile)
{
	int		fd;
	int		ret;
	char	buff[4096];
	char	*str;

	fd = open(namefile, O_RDONLY);
	if (fd == -1)
		ft_puterror("error");
	ret = read(fd, buff, 4096);
	buff[ret] = '\0';
	if (!(str = ft_strdup(buff)))
		ft_puterror("error");
	return (str);
}
