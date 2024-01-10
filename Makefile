NAME=lib_printf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror

#https://github.com/mcombeau/ft_printf

BIN_DIR=./bin
SRC_DIR=./src
INC_DIR=./inc
LIBFT_DIR=./libft
LIBFT_LIB=${LIBFT_DIR}/libft.a

SRC_FILES=$(wildcard ${SRC_DIR}/*.c)
OBJ_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.o)

all: ${LIBFT_LIB} ${NAME}

${LIBFT_LIB}:
	make -C ${LIBFT_DIR}

${NAME}: ${OBJ_FILES}
	ar -crs ${NAME} ${OBJ_FILES} 

${BIN_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} -I ${} -o $@ -c $^

clean:
	rm -f ${BIN_DIR}/*

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${LIBFT_LIB}