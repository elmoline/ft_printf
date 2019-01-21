/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:40:46 by evogel            #+#    #+#             */
/*   Updated: 2019/01/21 17:35:25 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

void	test_colors(void)
{
	int i;

	i = 0;
	while (i < 256)
	{
		ft_printf("{#}[%3d", i, i);
		ft_printf("{black}{##}%3c]{eoc} ", i, ' ');
		if ((i % 6 == 3 && i > 15) || (i < 15 && i % 6 == 0) || i == 15)
			ft_putchar('\n');
		if (i % 36 == 15)
			ft_putchar('\n');
		i++;
	}
}

int		main(void)
{
	printf("printf\t\t: |%0#x|\n", 12345);
	ft_printf("{bb_red}ft_printf\t:{eoc} {magenta}|%0#x|{eoc}\n", 12345);
	test_colors();
	return (0);
}
