# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enennige <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 08:13:57 by enennige          #+#    #+#              #
#    Updated: 2018/04/24 20:46:59 by enennige         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = srcs/
SRC_NAME = printf.c parse_string.c parse_arg.c initialize_struct.c
SRC_NAME += set_widths_and_flags.c set_type_and_data.c
SRC_NAME += set_modifiers_and_specifier.c
SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(patsubst %.c, %.o, $(SRC_NAME))
LIB_NAME = libft
LIB_OPT = -L ./libft/ -lft
LIB_HEADER = -I ./libft/includes/
INCLUDES = -I includes/ $(LIB_HEADER)
TC = $(addsuffix .check, $(NAME))

all: $(NAME)

$(NAME):
	make -C $(LIB_NAME)/
	cp $(LIB_NAME)/libft.a ./$(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

examples:
	make -C $(LIB_NAME)/
	$(CC) $(INCLUDES) -g -c $(SRCS) srcs/main.c
	$(CC) $(OBJS) main.o $(LIB_OPT)

something:
	make -C $(LIB_NAME)/
	$(CC) $(INCLUDES) -g $(SRCS) srcs/main.c -fsanitize=address $(LIB_OPT) -o bob

clean:
	make clean -C $(LIB_NAME)/
	rm -f $(OBJS) main.o

fclean: clean
	make fclean -C $(LIB_NAME)/
	rm -f $(NAME)

re: fclean all
