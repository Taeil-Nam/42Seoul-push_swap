# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:17:47 by tnam              #+#    #+#              #
#    Updated: 2023/02/28 15:11:46 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror

RM				=	rm -f

LIBFTPRINTF_DIR	=	ft_printf/
LIBFTPRINTF		=	libftprintf.a
LIBFTPRINTF_C	=	-L$(LIBFTPRINTF_DIR) -lftprintf

INCLUDES		=	includes/

SRCS_M			=	srcs/push_swap_main.c				\
					srcs/push_swap_init.c				\
					srcs/push_swap_atoi.c				\
					srcs/push_swap_stack.c				\
					srcs/push_swap_instruction_p.c		\
					srcs/push_swap_instruction_s.c		\
					srcs/push_swap_instruction_r.c		\
					srcs/push_swap_instruction_rr.c		\
					srcs/push_swap_sequencing.c			\
					srcs/push_swap_algorithm.c	\
									
SRCS_B			=	
					
OBJS_M			=	$(SRCS_M:.c=.o)
OBJS_B			=	$(SRCS_B:.c=.o)

BONUS_MODE = $(findstring $(MAKECMDGOALS),bonus)

ifeq ($(BONUS_MODE), )
    OBJS = $(OBJS_M)
else
    OBJS = $(OBJS_B)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C $(LIBFTPRINTF_DIR) 
	$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) $(LIBFTPRINTF_C) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re