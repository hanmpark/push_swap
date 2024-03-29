# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2023/04/03 10:50:10 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# <<<<<<<<<< presettings >>>>>>>>>> #
LIBFT_DIR = ./src/libft/
FTPRINTF_DIR = ./src/ft_printf/
GNL_DIR = ./src/get_next_line/
NAME = libft.a

# <<<<<<<<<< colors >>>>>>>>>> #
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

ORANGE = \033[38;5;216m
LBLUE = \033[38;5;153m
LYELLOW = \033[38;5;222m
BEIGE = \033[38;5;223m
LGREEN = \033[38;5;155m

# <<<<<<<<<<<< sources and objects >>>>>>>>>> #
SRCS_LIBFT =	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c \
					ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
					ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
					ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_filelen.c ft_mapdup.c ft_atol.c ft_strexit.c \
					ft_freemap.c ft_isnum.c ft_lstclear_moves.c \
					ft_lstcheck_order.c ft_lstgreatest_index.c \
					ft_lstsmallest_index.c ft_lstclear_piles.c

SRCS_FTPRINTF =	def_flags.c format_hexa.c ft_printf.c print_basic.c \
					print_hexa.c specifier_filter.c treat_charflags.c \
					treat_intflags.c

SRCS_GNL =	get_next_line_utils.c get_next_line.c

SRCS =	${addprefix ${LIBFT_DIR}, ${SRCS_LIBFT}} \
		${addprefix ${FTPRINTF_DIR}, ${SRCS_FTPRINTF}} \
		${addprefix ${GNL_DIR}, ${SRCS_GNL}}

OBJS =	${SRCS:.c=.o}

# <<<<<<<<<< compiler >>>>>>>>>> #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_COUNT = 0
HEADER_PATH = ./inc/
SRCS_TOT = ${shell find ./src/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

%.o:%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH} -c $< -o ${<:.c=.o}
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[LIBFT]${DEF}"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}"

# <<<<<<<<<< rules >>>>>>>>>> #
all:	${NAME}

${NAME}:	${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
