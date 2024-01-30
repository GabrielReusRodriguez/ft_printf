NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -MMD -MP -g
#CFLAGS= -g

BIN_DIR=./bin
SRC_DIR=./src
INC_DIR=./inc

LIBFT_HEADER=libft.h
FT_PRINTF_HEADER=ft_printf.h

LIBFT_DIR=./libft
LIBFT_LIB=${LIBFT_DIR}/libft.a

SRC_FILES=$(wildcard ${SRC_DIR}/*.c)
OBJ_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.o)
DEP_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.d)
LIBFT_OBJ_FILES=$(wildcard ${LIBFT_DIR}/*.o)

all: ${LIBFT_LIB} ${NAME}

${LIBFT_LIB}:
	make -C ${LIBFT_DIR}

${NAME}: ${OBJ_FILES} ${LIBFT_LIB}
	ar -crs ${NAME} ${OBJ_FILES} ${LIBFT_OBJ_FILES}

${BIN_DIR}/%.o: ${SRC_DIR}/%.c ${BIN_DIR} Makefile
	${CC} ${CFLAGS} -o $@ -c $<

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

clean:
	rm -f ${BIN_DIR}/*.o
	rm -f ${BIN_DIR}/*.d

fclean: clean
	rm -f ${NAME}

re: fclean all

tests: ${LIBFT_LIB} ${NAME}
	make -C ./tests/

tests_re: ${LIBFT_LIB} ${NAME}
	make re -C ./tests/

-include ${DEP_FILES}

.PHONY: all clean fclean re ${LIBFT_LIB} tests tests_re