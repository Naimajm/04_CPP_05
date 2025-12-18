
DEF_COLOR      	= \033[0;39m
ORANGE         	= \033[38;5;209m
MID_GRAY       	= \033[38;5;245m
DARK_GREEN     	= \033[38;2;75;179;82m

NAME 			:= form
CC 				:= c++
CFLAGS 			:= -Wall -Wextra -Werror -std=c++98
# -Wshadow

INCLUDE_DIR 	:= ./include
INCLUDE			:= -I$(INCLUDE_DIR)

SRC_FILES 		:= 	main.cpp \
					Bureaucrat.cpp \
					Form.cpp

OBJ_FILES 		:= $(SRC_FILES:%.cpp=%.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):  $(OBJ_FILES)
	@echo "$(ORANGE)🚀​ Compiling $(NAME)... $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(INCLUDE) -o $(NAME)
	@echo "$(DARK_GREEN)📚 $(NAME) has been created		OK$(DEF_COLOR)"

clean:
	@rm -f $(OBJ_FILES)	
	@echo "${MID_GRAY}Cleaning objects $(NAME)			OK$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MID_GRAY)Cleaning $(NAME)				OK$(DEF_COLOR)"

re: fclean all
	@echo "$(DARK_GREEN)🔁 Cleaning and recompiled -> $(NAME) 	OK$(DEF_COLOR)"	
	@make -s clean

debug: CFLAGS 		+= -g -fsanitize=address
debug: re

valgrind: $(NAME)
	@echo "$(ORANGE)🔍 Running Valgrind memory check...$(DEF_COLOR)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all library clean fclean re debug valgrind
