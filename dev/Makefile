NAME  = libftprintf.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
DEPFLAGS	=	-MMD -MP

ifdef CSANITIZE
	SANITIZE_FLAGS = -g -fsanitize=${CSANITIZE}
endif

OBJ_DIR	= ./obj
SRC_DIR	= ./src
INC_DIR	= ./inc

BONUS_SRC_DIR	= ./bonus_src
BONUS_INC_DIR	= ./bonus_inc

LIBFT_DIR		= ./libft
LIBFT_INC_DIR	= ${LIBFT_DIR}/inc
LIBFT_LIB		= ${LIBFT_DIR}/libft.a


SRC_FILES	=	ft_printf_char		\
				ft_printf_dec		\
				ft_printf_hex		\
				ft_printf_int		\
				ft_printf_low_hex	\
				ft_printf_percent	\
				ft_printf_ptr		\
				ft_printf_str		\
				ft_printf_up_hex	\
				ft_printf_usgn		\
				ft_printf

BONUS_SRC_FILES =	ft_format_bonus				\
					ft_format_padding_bonus		\
					ft_format_prefix_bonus		\
					ft_width_bonus				\
					ft_padding_utils_bonus		\
					ft_precision_bonus			\
					ft_printf_char_bonus		\
					ft_printf_dec_bonus			\
					ft_printf_hex_bonus			\
					ft_printf_int_bonus			\
					ft_printf_low_hex_bonus		\
					ft_printf_percent_bonus		\
					ft_printf_ptr_bonus			\
					ft_printf_str_bonus			\
					ft_printf_up_hex_bonus		\
					ft_printf_usgn_bonus		\
					ft_printf_bonus

SRC = $(addprefix ${SRC_DIR}/, $(addsuffix .c, ${SRC_FILES}))
OBJ = $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRC_FILES}))
DEP = $(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${SRC_FILES}))

BONUS_SRC = $(addprefix ${BONUS_SRC_DIR}/, $(addsuffix .c, ${BONUS_SRC_FILES}))
BONUS_OBJ = $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${BONUS_SRC_FILES}))
BONUS_DEP = $(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${BONUS_SRC_FILES}))

all: ${NAME}

ifndef BONUS
#${NAME} : ${LIBFT_LIB} ${OBJ}
#	cp ${LIBFT_LIB} $@ 
#	ar -csr $@ ${OBJ} 
#${NAME} : ${LIBFT_LIB} ${BONUS_OBJ} 
#	cp ${LIBFT_LIB} $@
#	ar -csr $@ ${BONUS_OBJ}
else
${NAME} : ${LIBFT_LIB} ${BONUS_OBJ} 
	cp ${LIBFT_LIB} $@
	ar -csr $@ ${BONUS_OBJ} 
endif

libft:
	make -C ${LIBFT_DIR} --no-print-directory

bonus: 
	@make BONUS=1 --no-print-directory

${LIBFT_LIB}:
	make -C ${LIBFT_DIR} --no-print-directory

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c Makefile
	@mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC_DIR} -o $@ -c $<

${OBJ_DIR}/%.o: ${BONUS_SRC_DIR}/%.c Makefile
	@mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} ${DEPFLAGS} ${SANITIZE_FLAGS} -I ${BONUS_INC_DIR} -I ${LIBFT_INC_DIR} -o $@ -c $<

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d
	make clean -C ${LIBFT_DIR} --no-print-directory

fclean: clean
	rm -f ${NAME}
	make fclean -C ${LIBFT_DIR} --no-print-directory

re: fclean all
-include ${DEP} ${BONUS_DEP}

.PHONY: all clean fclean re bonus