# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 14:36:01 by nsakanou          #+#    #+#              #
#    Updated: 2024/06/10 14:36:24 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDES = -I ./includes -I ./srcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS =	srcs/init/init_args.c \
		srcs/init/mutex.c \
		srcs/init/init_forks.c \
		srcs/init/init_data.c \
		srcs/utils/print.c \
		srcs/utils/time.c \
		srcs/philo_ft/philo_atoi.c \
		srcs/philo_ft/philo_utils.c \
		srcs/main.c \
		srcs/actions/dinner/thread.c \
		srcs/actions/dinner/check_die.c \
		srcs/actions/dinner/death.c \
		srcs/actions/dinner/start_dinner.c \
		srcs/actions/dinner/routine.c \
		srcs/actions/dinner/end_dinner.c \
		srcs/actions/eat.c \
		srcs/actions/forks.c \
		srcs/actions/think.c \
		srcs/actions/sleep.c

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
