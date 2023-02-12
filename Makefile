# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:17:47 by tnam              #+#    #+#              #
#    Updated: 2023/02/12 17:16:43 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
RM				=	rm -f

LIBFT_DIR		=	libft/
LIBFT			=	libft.a
LIBFT_C			=	-L$(LIBFT_DIR) -lft

INCLUDES		=	includes/

SRCS_M			=	srcs/push_swap.c					\
									
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
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) $(CFLAG) -I$(INCLUDES) $(OBJS) $(LIBFT_C) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all bonus clean fclean re