# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 18:33:52 by greus-ro          #+#    #+#              #
#    Updated: 2024/01/24 22:26:59 by greus-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -MMD -MP
#CFLAGS+= -g

BIN_DIR=./bin
SRC_DIR=./src
INC_DIR=./inc

LIBFT_HEADER=libft.h
FT_PRINTF_HEADER=ft_printf.h

LIBFT_DIR=./libft
LIBFT_LIB=${LIBFT_DIR}/libft.a

#SRC_FILES=$(wildcard ${SRC_DIR}/*.c)
SOURCES=	ft_printf.c\
			ft_printf_char.c \
			ft_printf_dec.c \
			ft_printf_format.c \
			ft_printf_hex.c \
			ft_printf_int.c \
			ft_printf_low_hex.c \
			ft_printf_percent.c \
			ft_printf_ptr.c \
			ft_printf_str.c \
			ft_printf_usgn.c \
			ft_printf_up_hex.c 

SRC_FILES=$(addprefix ${SRC_DIR}/, ${SOURCES})
OBJ_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.o)

DEP_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.d)
DEP_LIBFT=${LIBFT_DIR}/*.d

all: ${NAME}

${LIBFT_LIB}:
	make bonus -C ${LIBFT_DIR}
	
${NAME}: ${LIBFT_LIB} ${BIN_DIR} ${OBJ_FILES} 
	ar -crs ${NAME} ${LIBFT_DIR}/*.o ${OBJ_FILES}
#	ar -crsT ${NAME} ${LIBFT_LIB} ${OBJ_FILES}
#	ar -crsT ${NAME} ${OBJ_FILES}
#	ar -crsT ${NAME} ${NAME} ${LIBFT_LIB}

${BIN_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	${CC} ${CFLAGS} -o $@ -c $<

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

clean:
	rm -f ${BIN_DIR}/*.o
	rm -f ${BIN_DIR}/*.d

fclean: clean
	rm -f ${NAME}

re: libft_re fclean all 

libft_re:
	make re -C ${LIBFT_DIR}

-include ${DEP_FILES}

#tests: ${LIBFT_LIB} ${NAME}
#	make -C ./tests/

#tests_re: ${LIBFT_LIB} ${NAME}
#	make re -C ./tests/

#.PHONY: all clean fclean re ${LIBFT_LIB} tests tests_re

.PHONY: all clean fclean re libft_re