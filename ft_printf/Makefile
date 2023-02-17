# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 15:14:38 by tnam              #+#    #+#              #
#    Updated: 2023/02/17 17:12:13 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= cc
CFLAG			= -Wall -Wextra -Werror

COPY			= cp

RM				= rm -f

AR				= ar
ARFLAG			= crs

LIBFT_DIR	=	libft/
LIBFT		=	libft.a

SRCS_M			= ft_printf.c				\
				  ft_printf_c.c				\
				  ft_printf_d_i.c			\
				  ft_printf_p.c				\
				  ft_printf_percent.c		\
				  ft_printf_s.c				\
				  ft_printf_u.c				\
				  ft_printf_x.c				\
				  ft_printf.c				\

OBJS_M			= $(SRCS_M:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_M)
	$(MAKE) all -C $(LIBFT_DIR)
	$(COPY) $(LIBFT_DIR)$(LIBFT) $(NAME)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_M)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re