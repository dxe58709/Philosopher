# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 14:36:01 by nsakanou          #+#    #+#              #
#    Updated: 2024/06/13 18:29:34 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDES = -I ./includes -I ./srcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS =	srcs/actions/dinner/death.c \
		srcs/actions/dinner/one_philo.c \
		srcs/actions/dinner/routine.c \
		srcs/actions/dinner/start_dinner.c \
		srcs/actions/eat.c \
		srcs/actions/relese_forks.c \
		srcs/actions/sleep.c \
		srcs/actions/take_forks.c \
		srcs/actions/think.c \
		srcs/actions/threads/philo_thread.c \
		srcs/actions/threads/thread.c \
		srcs/destroy/delete_data.c \
		srcs/destroy/destroy_mutex.c \
		srcs/init/init_args.c \
		srcs/init/init_mutex.c \
		srcs/init/init_philo_data.c \
		srcs/init/init_thread.c \
		srcs/utils/err_print.c \
		srcs/utils/exit.c \
		srcs/utils/ft_calloc.c \
		srcs/utils/philo_atoi.c \
		srcs/utils/print.c \
		srcs/utils/time.c \
		srcs/main.c
		
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDE) $(CFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
