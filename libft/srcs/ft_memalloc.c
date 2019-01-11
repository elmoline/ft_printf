/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:14:44 by evogel            #+#    #+#             */
/*   Updated: 2018/11/27 18:27:32 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
