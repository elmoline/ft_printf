/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:38:26 by evogel            #+#    #+#             */
/*   Updated: 2019/01/15 18:00:16 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "libftprintf.h"

#define RED_T col->colors[0][0]
#define RED_C col->colors[0][1]

#define BRED_T col->colors[1][0]
#define BRED_C col->colors[1][1]

#define GREEN_T col->colors[2][0]
#define GREEN_C col->colors[2][1]

#define BGREEN_T col->colors[3][0]
#define BGREEN_C col->colors[3][1]

#define YELLOW_T col->colors[4][0]
#define YELLOW_C col->colors[4][1]

#define BYELLOW_T col->colors[5][0]
#define BYELLOW_C col->colors[5][1]

#define BLUE_T col->colors[6][0]
#define BLUE_C col->colors[6][1]

#define BBLUE_T col->colors[7][0]
#define BBLUE_C col->colors[7][1]

#define MAGENTA_T col->colors[8][0]
#define MAGENTA_C col->colors[8][1]

#define BMAGENTA_T col->colors[9][0]
#define BMAGENTA_C col->colors[9][1]

#define CYAN_T col->colors[10][0]
#define CYAN_C col->colors[10][1]

#define BCYAN_T col->colors[11][0]
#define BCYAN_C col->colors[11][1]

#define RESET_T col->colors[12][0]
#define RESET_C col->colors[12][1]

void	init_colors1(t_colors *col)
{
	ft_strcpy(RED_T, "red");	
	ft_strcpy(BRED_T, "bold red");	
	ft_strcpy(GREEN_T, "green");	
	ft_strcpy(BGREEN_T, "bold green");	
	ft_strcpy(YELLOW_T, "yellow");	
	ft_strcpy(BYELLOW_T, "bold yellow");	
	ft_strcpy(BLUE_T, "blue");	
	ft_strcpy(BBLUE_T, "bold blue");	
	ft_strcpy(MAGENTA_T, "magenta");	
	ft_strcpy(BMAGENTA_T, "bold magenta");	
	ft_strcpy(CYAN_T, "cyan");	
	ft_strcpy(BCYAN_T, "bold cyan");	
	ft_strcpy(RESET_T, "eoc");	
}

void	init_colors2(t_colors *col)
{
	ft_strcpy(RED_C, "\033[0;31m");
	ft_strcpy(BRED_C, "\033[1;31m");	
	ft_strcpy(GREEN_C, "\033[0;32m");
	ft_strcpy(BGREEN_C, "\033[1;32m");
	ft_strcpy(YELLOW_C, "\033[0;33m");
	ft_strcpy(BYELLOW_C, "\033[1;33m");
	ft_strcpy(BLUE_C, "\033[0;34m");
	ft_strcpy(BBLUE_C, "\033[1;34m");
	ft_strcpy(MAGENTA_C, "\033[0;35m");
	ft_strcpy(BMAGENTA_C, "\033[1;35m");
	ft_strcpy(CYAN_C, "\033[0;36m");
	ft_strcpy(BCYAN_C, "\033[1;36m");
	ft_strcpy(RESET_C, "\033[0m");
}

void	color_manager(const char **format)
{
	t_colors	*col;
	int 		i;

	i = 0;
	col = (t_colors*)ft_memalloc(sizeof(t_colors));
	init_colors1(col);
	init_colors2(col);
	while (!ft_strnstr(*format, col->colors[i][0], 20) && i < 13)
		i++;
	if (i == 13)
		return ;
	ft_putstr(col->colors[i][1]);
	while (**format != '}')
		(*format)++;
}
