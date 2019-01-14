# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evogel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:47:44 by evogel            #+#    #+#              #
#    Updated: 2019/01/14 21:05:38 by evogel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

############
# COMPILER #
############

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

SANITIZE = -fsanitize=address

#########
# FILES #
#########

SRCS = ft_printf.c \
	   ft_itoabase.c \
	   tools.c \
	   get_fmt.c \
	   get_arg.c \
	   treat_int.c \
	   treat_uns.c \
	   treat_chr.c \
	   treat_str.c \
	   treat_flt.c

OBJS = $(SRCS:.c=.o)

SRCS_L = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_islower.c \
	   ft_isprint.c \
	   ft_isupper.c \
	   ft_itoa.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstlen.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_puttab.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_capitalize.c

OBJS_L = $(SRCS_L:.c=.o)

###############
# DIRECTORIES #
###############

INC = includes

P_SRCS = srcs

P_OBJS = objs

D_OBJS = $(addprefix $(P_OBJS)/, $(OBJS))

P_LIB = libft

INC_L = $(P_LIB)/includes

P_SRCS_L = $(P_LIB)/srcs

P_OBJS_L = $(P_LIB)/objs

D_OBJS_L = $(addprefix $(P_OBJS_L)/, $(OBJS_L))

################
# COMPILE TEST #
################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

#########
# RULES #
#########

all: $(NAME)

$(NAME): $(INC) $(P_OBJS) $(P_OBJS_L) $(D_OBJS_L) $(D_OBJS)
	@$(call run_and_test, ar -rc $(NAME) $(D_OBJS_L) $(D_OBJS))
	@ranlib $(NAME)

$(P_OBJS_L)/%.o: $(P_SRCS_L)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(INC_L))

$(P_OBJS)/%.o: $(P_SRCS)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(INC) -I$(INC_L))

$(P_OBJS):
	@$(call run_and_test, mkdir -p $(P_OBJS))

$(P_OBJS_L):
	@$(call run_and_test, mkdir -p $(P_OBJS_L))

test: all
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(P_OBJS)/main.o -c main.c -I$(INC) -I$(INC_L) && $(CC) $(CFLAGS) -o test $(P_OBJS)/main.o -L. -lftprintf)

sanitize: all
	@$(call run_and_test, $(CC) $(CFLAGS) $(SANITIZE) -o $(P_OBJS)/main.o -c main.c -I$(INC) -I$(INC_L) && $(CC) $(CFLAGS) $(SANITIZE) -o test $(P_OBJS)/main.o -L. -lftprintf)

clean:
	@$(call run_and_test, rm -rf $(P_OBJS) $(P_OBJS_L))

fclean: clean
	@$(call run_and_test, rm -f $(NAME))

re: fclean all
