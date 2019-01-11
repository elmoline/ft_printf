/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:40:46 by evogel            #+#    #+#             */
/*   Updated: 2019/01/11 16:34:47 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int		main(void)
{
//	char 	*test = "[%05c]\n";
//	unsigned int	d = 4294967295;
//	void	*p = &test;
	double	f = 2.987;

		printf("printf\t\t: [%10.2f]\n", f);
	ft_printf("ft_printf\t: [%10.2f]\n", f);
	return (0);
}

//NOTES:
//- BONUS: make printf to any base with * agr being base chars
//- make and ft_usage for checking that all the flags are in order and if they aren't, print a "usgae" instruction and exit
