# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 01:34:53 by greus-ro          #+#    #+#              #
#    Updated: 2024/07/05 01:11:40 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror -MMD -MP 

ifdef CSANITIZE
	SANITIZE_FLAGS = -g -fsanitize=${CSANITIZE}
endif

DEPFLAGS = -MMD -MP 

OBJ_DIR = ./obj
SRC_DIR = ./src
INC_DIR = ./inc

LIBFT_SRC_FILES=	ft_atoi			\
					ft_bzero		\
					ft_calloc		\
					ft_iputchar_fd	\
					ft_iputendl_fd	\
					ft_iputnbr_fd	\
					ft_iputstr_fd	\
					ft_isalnum		\
					ft_isalpha		\
					ft_isascii		\
					ft_isdigit		\
					ft_islower		\
					ft_isupper		\
					ft_isprint		\
					ft_itoa			\
					ft_memchr		\
					ft_memcmp		\
					ft_memcpy		\
					ft_memmove		\
					ft_memset		\
					ft_putchar_fd	\
					ft_putendl_fd	\
					ft_putnbr_fd	\
					ft_putstr_fd	\
					ft_split		\
					ft_strchr		\
					ft_strdup		\
					ft_striteri		\
					ft_strjoin		\
					ft_strlcat		\
					ft_strlcpy		\
					ft_strlen		\
					ft_strmapi		\
					ft_strncmp		\
					ft_strnstr		\
					ft_strrchr		\
					ft_strtrim		\
					ft_substr		\
					ft_tolower		\
					ft_toupper		\
					ft_utoa

BONUS_SRC_FILES=	ft_lstadd_front_bonus	\
					ft_lstadd_back_bonus	\
					ft_lstclear_bonus		\
					ft_lstdelone_bonus		\
					ft_lstiter_bonus		\
					ft_lstlast_bonus		\
					ft_lstmap_bonus			\
					ft_lstnew_bonus			\
					ft_lstsize_bonus		


SRC	= $(addprefix ${SRC_DIR}/, $(addsuffix .c, ${LIBFT_SRC_FILES} ${BONUS_SRC_FILES}))
OBJ	= $(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${LIBFT_SRC_FILES} ${BONUS_SRC_FILES}))
DEP	= $(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${LIBFT_SRC_FILES} ${BONUS_SRC_FILES}))

all:${NAME}
	
${NAME}: ${OBJ} 
	ar -csr ${NAME} ${OBJ}
#	ar -crs ${NAME} ${OBJ}

${OBJ_DIR}/%.o:${SRC_DIR}/%.c Makefile
	@mkdir -p ${OBJ_DIR}
	cc ${CFLAGS}  ${DEPFLAGS} ${SANITIZE_FLAGS} -I ${INC_DIR} -c -o $@  $< 
	
clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d

fclean: clean 
	rm -f ${NAME}
	
re: fclean all

-include ${DEP}

.PHONY= all clean fclean re

