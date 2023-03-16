# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 14:42:42 by hanmpark          #+#    #+#              #
#    Updated: 2023/03/16 19:40:50 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_PATH = ./libft/

# <<<<<<<<<< COLORS >>>>>>>>>> #
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

ORANGE = \033[38;5;216m
LBLUE = \033[38;5;153m
LYELLOW = \033[38;5;222m
BEIGE = \033[38;5;223m

# <<<<<<<<<< SRC /OBJ >>>>>>>>>> #
SRCS_PATH = ./src/
PARSING_PATH = ${SRCS_PATH}parsing/
PARSING_SRCS = ${addprefix ${PARSING_PATH}, init_list.c \
											set_index.c \
											check_init_list.c}

INSTRUCTIONS_PATH = ${SRCS_PATH}instructions/
INSTRUCTIONS_SRCS = ${addprefix ${INSTRUCTIONS_PATH}, push.c \
														reverse_rotate.c \
														rotate.c \
														swap.c}

SORT_PATH = ${SRCS_PATH}sort/
SORT_SRCS = ${addprefix ${SORT_PATH}, sort_big_number.c \
										sort_small_number.c \
										count_moves.c \
										locate.c \
										moves.c}

BONUS_PATH = ${SRCS_PATH}bonus/

BONUS_INSTRUCTIONS_PATH = ${BONUS_PATH}instructions/
BONUS_INSTRUCTIONS_SRCS = ${addprefix ${BONUS_INSTRUCTIONS_PATH}, push_bonus.c \
																	reverse_rotate_bonus.c \
																	rotate_bonus.c \
																	swap_bonus.c}

BONUS_PARSING_PATH = ${BONUS_PATH}parsing/
BONUS_PARSING_SRCS = ${addprefix ${BONUS_PARSING_PATH}, check_init_list_bonus.c \
														init_list_bonus.c \
														set_index_bonus.c}

BONUS_SRCS = ${BONUS_INSTRUCTIONS_SRCS} ${BONUS_PARSING_SRCS} ${BONUS_PATH}checker_bonus.c

SRCS = ${PARSING_SRCS} ${INSTRUCTIONS_SRCS} ${SORT_SRCS} ${SRCS_PATH}push_swap.c

OBJS_MAN = ${SRCS:.c=.o}
OBJS_BONUS = ${BONUS_SRCS:.c=.o}

# <<<<<<<<<< COMPILER >>>>>>>>>> #
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -fsanitize=address -g3
endif

SRCS_COUNT := ${shell find ./src/ -type f -name '*.o' | wc -l}
MAIN_SRCS_TOT = ${shell find ./src/ -type f -name '*.c' | wc -l}
MAIN_SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${MAIN_SRCS_TOT}}
HEADER_PATH = ./inc/
%.o:%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH} -c $< -o ${<:.c=.o}
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[PUSH_SWAP]${DEF}"
	@printf " ${BEIGE}  [%d/%d files (%d%%)]${DEF}" ${SRCS_COUNT} ${MAIN_SRCS_TOT} ${MAIN_SRCS_PRCT}
	@echo "${UP}${UP}"

# <<<<<<<<<< RULES >>>>>>>>>> #
all: ${NAME}

${NAME}: ${OBJS_MAN}
	@echo "\n\n"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${LIBFT_PATH}/libft.a ${OBJS_MAN} -o ${NAME}
	@echo "\n\n\n\t${BOLD}${CUR}${LYELLOW}COMPILED ✨${DEF}\n"

CHECKER_NAME = checker
${CHECKER_NAME}: ${OBJS_BONUS}
	@echo "\n\n"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${LIBFT_PATH}/libft.a ${OBJS_BONUS} -o ${CHECKER_NAME}
	@echo "\n\n\n\t${BOLD}${CUR}${LYELLOW}COMPILED ✨${DEF}\n"

debug:
	@${MAKE} DEBUG=1

norminette:
	@echo "\n\t${BOLD}${CUR}${ORANGE}NORMINETTE${DEF}\n"
	@echo "${LYELLOW}${BOLD}LIBFT${DEF}"
	@echo "${LBLUE}${CUR}ft_printf${DEF}"
	@norminette ${LIBFT_PATH}src/ft_printf/ || TRUE
	@echo "\n${LBLUE}${CUR}get_next_line${DEF}"
	@norminette ${LIBFT_PATH}src/get_next_line/ || TRUE
	@echo "\n${LBLUE}${CUR}libft${DEF}"
	@norminette ${LIBFT_PATH}src/libft/ || TRUE
	@echo "\n${LYELLOW}${BOLD}PUSH_SWAP${DEF}"
	@echo "${LBLUE}${CUR}instructions${DEF}"
	@norminette ${INSTRUCTIONS_PATH} || TRUE
	@echo "\n${LBLUE}${CUR}parsing${DEF}"
	@norminette ${PARSING_PATH} || TRUE
	@echo "\n${LBLUE}${CUR}sort${DEF}"
	@norminette ${SORT_PATH} ${SRCS_PATH}main.c || TRUE
	@echo ""

bonus: ${CHECKER_NAME}

clean:
	@echo "\n\t${BOLD}${CUR}${ORANGE}CLEANING...${DEF}\n"
	@rm -f ${OBJS_MAN} ${OBJS_BONUS}
	@${MAKE} -C ${LIBFT_PATH} clean
	@echo "${LBLUE}${BOLD}${CUR}- Deleted object files${DEF}\n"

fclean: clean
	@rm -f ${LIBFT_PATH}/libft.a
	@rm -f ${NAME} ${CHECKER_NAME}
	@echo "${LBLUE}${BOLD}${CUR}- Deleted libft.a and ${NAME}${DEF}\n\n"

re: fclean all

.PHONY: all clean fclean clean re debug
