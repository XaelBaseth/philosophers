# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 13:25:03 by acharlot          #+#    #+#              #
#    Updated: 2023/07/06 11:53:04 by acharlot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variable
NAME		=	philo
INC			=	inc/
SRC_DIR 	=	src/
OBJ_DIR 	=	obj/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread -g3
THREADFLAGS =	-fsanitize=thread
MEMFLAGS	=	-fsanitize=address
RM			=	rm -rf
ECHO		=	echo

#Colors
DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#Files
MAND_DIR	=	mandatory/
MAND_FILES	=	create_threads monitoring main
INPUT_DIR	=	input/
INPUT_FILES	=	init_args is_all_digits 
PHILOS_DIR	=	philos/
PHILOS_FILES=	init_philos routine
UTILS_DIR	=	utils/
UTILS_FILES	=	all_ate destroy ft_atoi get_time \
				init_forks panic starved

SRC_MAN_FILE=	$(addprefix $(MAND_DIR), $(MAND_FILES))
SRC_INP_FILE=	$(addprefix $(INPUT_DIR), $(INPUT_FILES))
SRC_PHI_FILE=	$(addprefix $(PHILOS_DIR), $(PHILOS_FILES))
SRC_UTI_FILE=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

MSRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_MAN_FILE)))
MOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_MAN_FILE)))

ISRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_INP_FILE)))
IOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_INP_FILE)))

PSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_PHI_FILE)))
POBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PHI_FILE)))
USRC 		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_UTI_FILE)))
UOBJ		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_UTI_FILE)))

OBJF		=	.cache_exists

OBJ 		=	$(MOBJ) $(IOBJ) $(POBJ) $(UOBJ)

#Rules
all:			$(NAME)

$(NAME):		$(OBJ) $(OBJF)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@$(ECHO) "$(YELLOW)[PHILOSOPHERS]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)"


$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJF)
					@$(CC) $(CFLAGS) -c $< -o $@


$(OBJF):		
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(MAND_DIR)
					@mkdir -p $(OBJ_DIR)$(INPUT_DIR)
					@mkdir -p $(OBJ_DIR)$(PHILOS_DIR)
					@mkdir -p $(OBJ_DIR)$(UTILS_DIR)
					@touch $(OBJF)

mem:			$(OBJ) $(OBJF)
					@$(CC) $(CFLAGS) $(MEMFLAGS) $(OBJ) -o $(NAME)
					@$(ECHO) "$(YELLOW)[PHILOSOPHERS]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)"

thread:			$(OBJ) $(OBJF)
					@$(CC) $(CFLAGS) $(THREADFLAGS) $(OBJ) -o $(NAME)
					@$(ECHO) "$(YELLOW)[PHILOSOPHERS]:\t$(ORANGE)[==========]\t$(GREEN) => Success!$(DEF_COLOR)"

clean:
					@$(RM) $(OBJ_DIR)
					@$(RM) $(OBJF)
					@$(ECHO) "$(BLUE)[PHILOSOPHERS]:\tobject files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

fclean:			clean
					@$(RM) $(NAME)
					@$(RM) *.dSYM
					@find . -name ".DS_Store" -delete
					@$(ECHO) "$(CYAN)[PHILOSOPHERS]:\texec. files$(DEF_COLOR)\t$(GREEN) => Cleaned!$(DEF_COLOR)\n"

re:				fclean all
					@$(ECHO) "$(GREEN)Cleaned and rebuilt everything for [PHILOSOPHERS]! $(DEF_COLOR)\n"

.PHONY:			all clean fclean re
