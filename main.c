/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:40:46 by evogel            #+#    #+#             */
/*   Updated: 2019/01/18 13:45:39 by evogel           ###   ########.fr       */
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
		if ((i % 6 == 3 && i > 15)|| (i < 15 && i % 6 == 0) || i == 15)
			ft_putchar('\n');
		if (i % 36 == 15)
			ft_putchar('\n');
		i++;
	}
}

int		main(void)
{
//	unsigned int	d = 4294967295;
	long double		lf = (long double)ULLONG_MAX;
	double			f = 9.8654563;

							 printf("printf\t\t: |%.f|\n", f);
	ft_printf("{b_white}{##}ft_printf\t:{eoc} {#}|%.f|{eoc}\n", 54, 208, f);
	test_colors();
	return (0);
}
