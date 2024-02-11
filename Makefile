NAME  = libftprintf.a
BONUS = libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -MMD -MP -g
#CFLAGS= -g

BIN_DIR=./bin
#SRC_DIR=./src
SRC_DIR=./bonus
INC_DIR=./inc

BONUS_SRC_DIR= ./bonus

LIBFT_HEADER=libft.h
FT_PRINTF_HEADER=ft_printf.h

LIBFT_DIR=./libft
#LIBFT_LIB=${LIBFT_DIR}/libft.a
LIBFT_LIB=${BIN_DIR}/libft.a

SRC_FILES=$(wildcard ${SRC_DIR}/*.c)
OBJ_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.o)
DEP_FILES=$(SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%.d)

BONUS_SRC_FILES=$(wildcard ${BONUS_SRC_DIR}/*.c)
BONUS_OBJ_FILES=$(BONUS_SRC_FILES:${BONUS_SRC_DIR}/%.c=${BIN_DIR}/%.o)
BONUS_DEP_FILES=$(BONUS_SRC_FILES:${BONUS_SRC_DIR}/%.c=${BIN_DIR}/%.d)

all: ${LIBFT_LIB} ${NAME}

${LIBFT_LIB}:
	make bonus -C ${LIBFT_DIR}

${NAME}: ${LIBFT_LIB} ${OBJ_FILES} 
	ar -rcsT ${NAME}  ${BIN_DIR}/libft.a  ${OBJ_FILES} 
#	cp ${SRC_DIR}/ft_printf_bonus.h ${INC_DIR}/ft_printf_bonus.h
	cp ${SRC_DIR}/ft_printf.h ${INC_DIR}/ft_printf.h

${BIN_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	${CC} ${CFLAGS} -I ${INC_DIR} -o $@ -c $<

${BIN_DIR}/%.o: ${BONUS_SRC_DIR}/%.c Makefile
	${CC} ${CFLAGS} -I ${INC_DIR} -o $@ -c $<

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

#bonus: fclean ${LIBFT_LIB} ${BONUS_OBJ_FILES} 
#	ar -rcsT ${NAME}  ${BIN_DIR}/libft.a  ${BONUS_OBJ_FILES} 
#	cp ${BONUS_SRC_DIR}/ft_printf_bonus.h ${INC_DIR}/
#	touch bonus

#bonus: ${LIBFT_LIB} ${BONUS_OBJ_FILES}
#	ar -rcsT ./libftprintf_bonus.a  ${BIN_DIR}/libft.a  ${BONUS_OBJ_FILES} 
#	cp ${BONUS_SRC_DIR}/ft_printf_bonus.h ${INC_DIR}/
#	touch bonus
bonus : all

clean:
	rm -f ${BIN_DIR}/*.o
	rm -f ${BIN_DIR}/*.d
	make clean -C ${LIBFT_DIR}

fclean: clean
	rm -f ${NAME}
	make fclean -C ${LIBFT_DIR}

re: fclean all

-include ${DEP_FILES} ${BONUS_DEP_FILES}

tests: ${LIBFT_LIB} ${NAME}
	make -C ./tests/

tests_re: ${LIBFT_LIB} ${NAME}
	make re -C ./tests/

.PHONY: all clean fclean re ${LIBFT_LIB} tests tests_re