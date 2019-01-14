/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:57:17 by evogel            #+#    #+#             */
/*   Updated: 2019/01/14 19:26:43 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

# include <strings.h>
# include <stdarg.h>
# include <stdlib.h>

# include <stdio.h> //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<dont forget to remove

# define RES fmt->res
# define RET fmt->ret

# define PRECI fmt->preci
# define WIDTH fmt->width

# define HASH fmt->flag[0]
# define ZERO fmt->flag[1]
# define MINUS fmt->flag[2]
# define PLUS fmt->flag[3]
# define SPACE fmt->flag[4]

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

typedef struct		s_format
{
	char	*res;
	int		ret;

	char	conv;
	char	supp[14]; //%diouxXcspfFb
	char	type[5][10]; //5 lists of convs corresponding to a type
	int		(*treat_type[5])(va_list*, struct s_format*);
	char	caps[4]; //X

	int		width;
	int		preci;

	int		flag[5];
	int		length[5];

	int		neg;
	int		cap;
	char	base[26];
}					t_format;

int					ft_printf(const char *fmt, ...);
int					converter(va_list *ap, const char **format);
t_format			*get_format(va_list *ap, const char **format);
int					treatment(va_list *ap, t_format *fmt);

int					treat_int(va_list *ap, t_format *fmt);
int					treat_uns(va_list *ap, t_format *fmt);
int					treat_chr(va_list *ap, t_format *fmt);
int					treat_str(va_list *ap, t_format *fmt);
int					treat_flt(va_list *ap, t_format *fmt);
long long			get_int(va_list *ap, t_format *fmt);
unsigned long long	get_uns(va_list *ap, t_format *fmt);
long double			get_flt(va_list *ap, t_format *fmt);
int					set_preci(t_format *fmt);
int					set_prefx(t_format *fmt);
int					set_width(t_format *fmt);

char				*ft_itoabase(unsigned long long n, char *base);
char				*ft_malloc_c(size_t size, char c);
int					error_1(void);
int					error_2(void);

#endif
