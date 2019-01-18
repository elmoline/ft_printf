/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:57:17 by evogel            #+#    #+#             */
/*   Updated: 2019/01/18 15:47:06 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

# include <strings.h>
# include <stdarg.h>
# include <stdlib.h>

# include <stdio.h>

/*
** Defines to more easily access struct elements
*/

# define AP *(fmt->ap)
# define RES fmt->res
# define RET fmt->ret

# define PRECI fmt->preci
# define WIDTH fmt->width

# define HASH fmt->flag[0]
# define ZERO fmt->flag[1]
# define MINUS fmt->flag[2]
# define PLUS fmt->flag[3]
# define SPACE fmt->flag[4]
# define FILL fmt->flag[5]
# define MID fmt->flag[6]

# define H fmt->length[0]
# define HH fmt->length[1]
# define L fmt->length[2]
# define LL fmt->length[3]
# define FL fmt->length[4]

# define NEG fmt->neg
# define CAP fmt->cap
# define BASE fmt->base

# define CONV fmt->conv
# define SUPP fmt->supp
# define TYPE fmt->type
# define INTS fmt->type[0]
# define UNSI fmt->type[1]
# define STRI fmt->type[2]
# define CHAR fmt->type[3]
# define FLOT fmt->type[4]
# define TREAT_TYPE fmt->treat_type
# define CAPS fmt->caps
# define LLEN fmt->llen

typedef struct		s_format
{
	va_list *ap;
	char	*res;
	int		ret;

	char	conv;
	char	supp[20];
	char	type[5][10];
	int		(*treat_type[5])(struct s_format*);
	char	caps[5];
	char	llen[5];

	int		width;
	int		preci;

	int		flag[7];
	int		length[5];

	int		neg;
	int		cap;
	char	base[26];
}					t_format;

int					ft_printf(const char *fmt, ...);
int					converter(va_list *ap, const char **format);
int					treatment(t_format *fmt);

t_format			get_format(va_list *ap, const char **format);
int					get_flag(char c, t_format *fmt);
void				get_field(const char **format, t_format *fmt);
void				get_length(const char **format, t_format *fmt);
void				get_converter(const char **format, t_format *fmt);
void				get_base(t_format *fmt);

int					treat_int(t_format *fmt);
int					treat_uns(t_format *fmt);
int					treat_chr(t_format *fmt);
int					treat_str(t_format *fmt);
int					treat_flt(t_format *fmt);

long long			get_int(t_format *fmt);
unsigned long long	get_uns(t_format *fmt);
long double			get_flt(t_format *fmt);

int					set_preci(t_format *fmt);
int					set_prefx(t_format *fmt);
int					set_width(t_format *fmt);

char				*ft_itoabase(unsigned long long n, char *base);
char				*ft_flotoa(long double f, int preci);
char				*ft_malloc_c(size_t size, char c);

/*
** Struct and function for color options
*/

typedef struct		s_colors
{
	char	colors[27][2][20];
}					t_colors;

int					color_manager(va_list *ap, const char **format);

#endif
