/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:40:46 by evogel            #+#    #+#             */
/*   Updated: 2019/01/17 21:29:49 by evogel           ###   ########.fr       */
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
		ft_printf("{#}[%d]", i, i);
		ft_printf("{##}[%d]{eoc}", i, i);
		i++;
	}
}

int		main(void)
{
//	char 	*test = NULL;
	unsigned int	d = 4294967295;
//	void	*p = &test;
	double		f = 9.5;

//		printf("printf\t\t: [%Lf]\n", LDBL_MAX);
//		printf("printf\t\t: [%f]\n", DBL_MAX);
	    				  	 printf("printf\t\t: |%.1000f|\n", f);
	ft_printf("{b_white}{##}ft_printf\t:{eoc} {#}|%.1000f|{eoc}\n", 54, 208, f);
//	test_colors();
	return (0);
}
