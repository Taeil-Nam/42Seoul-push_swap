# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:17:47 by tnam              #+#    #+#              #
#    Updated: 2023/03/02 14:26:58 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_b			=	checker

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror

RM				=	rm -f

LIBFTPRINTF_DIR	=	ft_printf/
LIBFTPRINTF		=	libftprintf.a
LIBFTPRINTF_C	=	-L$(LIBFTPRINTF_DIR) -lftprintf

INCLUDES		=	includes/

SRCS_M			=	srcs_m/push_swap_main.c					\
					srcs_m/push_swap_init.c					\
					srcs_m/push_swap_atoi.c					\
					srcs_m/push_swap_stack.c				\
					srcs_m/push_swap_instruction_p.c		\
					srcs_m/push_swap_instruction_s.c		\
					srcs_m/push_swap_instruction_r.c		\
					srcs_m/push_swap_instruction_rr.c		\
					srcs_m/push_swap_sequencing.c			\
					srcs_m/push_swap_algorithm.c			\
									
SRCS_B			=	srcs_b/push_swap_main_bonus.c					\
					srcs_b/push_swap_init_bonus.c					\
					srcs_b/push_swap_atoi_bonus.c					\
					srcs_b/push_swap_stack_bonus.c					\
					srcs_b/push_swap_instruction_p_bonus.c			\
					srcs_b/push_swap_instruction_s_bonus.c			\
					srcs_b/push_swap_instruction_r_bonus.c			\
					srcs_b/push_swap_instruction_rr_bonus.c			\
					gnl/get_next_line.c								\
					gnl/get_next_line_utils.c						\
					
OBJS_M			=	$(SRCS_M:.c=.o)
OBJS_B			=	$(SRCS_B:.c=.o)

BONUS_MODE = $(findstring $(MAKECMDGOALS),bonus)

ifeq ($(BONUS_MODE), )
    OBJS = $(OBJS_M)
else
    OBJS = $(OBJS_B)
endif

all: $(NAME)

bonus: $(NAME_b)

$(NAME): $(OBJS)
	$(MAKE) all -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) $(LIBFTPRINTF_C) -o $(NAME)

$(NAME_b): $(OBJS)
	$(MAKE) all -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) $(LIBFTPRINTF_C) -o $(NAME_b)

%.o: %.c
	$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

clean :
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	$(RM) $(NAME)
	$(RM) $(NAME_b)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re