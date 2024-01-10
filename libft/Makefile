# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 01:34:53 by greus-ro          #+#    #+#              #
#    Updated: 2024/01/04 23:56:43 by greus-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
BIN_DIR=./bin


SRC_FILES=$(wildcard *.c)
#OBJ_FILES=$(SRC_FILES:%.c=${BIN_DIR}/%.o)

#LIBFT_SRC_FILES=$(wildcard *.c)
#LIBFT_OBJ_FILES=$(LIBFT_SRC_FILES:%.c=${BIN_DIR}/%.o)

BONUS_SRC_FILES= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c   
BONUS_SRC_FILES+= ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
BONUS_SRC_FILES+= ft_lstmap.c
BONUS_OBJ_FILES=$(BONUS_SRC_FILES:%.c=${BIN_DIR}/%.o)


LIBFT_SRC_FILES=$(filter-out $(BONUS_SRC_FILES),$(SRC_FILES))
LIBFT_OBJ_FILES=$(LIBFT_SRC_FILES:%.c=${BIN_DIR}/%.o)

all:${NAME}
	
${NAME}: ${LIBFT_OBJ_FILES}
	ar -rc ${NAME} ${LIBFT_OBJ_FILES}

${BIN_DIR}/%.o:%.c
	mkdir -p ${BIN_DIR}
	cc ${CFLAGS} -o $@ -c $^

clean:
	-rm -rf ${BIN_DIR}

fclean: clean 
	-rm ${NAME}
	
re: fclean all

bonus: ${BONUS_OBJ_FILES}
	ar -rcs ${NAME} ${BONUS_OBJ_FILES}

.PHONY= all clean fclean re bonus