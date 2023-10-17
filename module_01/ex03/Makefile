NAME			= wepon
SRCS			= main.cpp Weapon.cpp  HumanA.cpp  HumanB.cpp
OBJ_DIR			= obj
HEADER			= Weapon.hpp  HumanA.hpp  HumanB.hpp
OBJS			= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
CPP				= c++ 
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -std=c++98
MK				= mkdir -p

all:			$(OBJ_DIR) $(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR): 
	$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o:	%.cpp Makefile $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:			
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re bonus
