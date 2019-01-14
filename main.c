/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:40:46 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 19:55:12 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int		main(void)
{
//	char 	*test = NULL;
//	unsigned int	d = 4294967295;
//	void	*p = &test;
	long double	f = -922337203685477580892233720368547758089223372036854775808922337203685477580892233720368547758089223372036854775808922337203685477580892233720368547758089223372036854775808922337203685477580892233720368547758089223372036854775808922337203685477580892233720368547758089223372036854775808.00;

//		printf("printf\t\t: [%Lf]\n", LDBL_MAX);
//		printf("printf\t\t: [%f]\n", DBL_MAX);
		printf("printf\t\t: [%Lf]\n", f);
	ft_printf("ft_printf\t: [%Lf]\n", f);
	return (0);
}

//NOTES:
//- BONUS: make printf to any base with * agr being base chars
//- make and ft_usage for checking that all the flags are in order and if they aren't, print a "usgae" instruction and exit
