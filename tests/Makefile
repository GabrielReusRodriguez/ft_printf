BIN_DIR=./bin
NAME= ${BIN_DIR}/test_ft_printf.out
CFLAGS=-Wall -Wextra -Werror -g
LIBFT_PRINTF=../libftprintf.a
LIBFT=../libft/libft.a

SRC_FILES=$(wildcard *.c)
OBJ_FILES=$(SRC_FILES:%.c=${BIN_DIR}/%.out)

${BIN_DIR}/%.out:%.c
	cc ${CFLAGS} -o $@ $< ${LIBFT_PRINTF}  ${LIBFT} 

all: ${BIN_DIR} ${OBJ_FILES} ${LIBFT_PRINTF} ${LIBFT}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}
clean:
	rm -f ${BIN_DIR}/*.out 

re: clean all

${LIBFT}:
	make -C ../libft

${LIBFT_PRINTF}:
	make -C ../

.PHONY: all clean re
