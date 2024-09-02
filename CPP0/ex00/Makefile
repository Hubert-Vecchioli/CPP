###############################################################################
#********************** Makefile for CPP00 project  **************************#
###############################################################################

#******************************  COMPILER  ***********************************#

NAME			= megaphone
CC 				= g++
CFLAGS 			= -Wall -Werror -Wextra  -std=c++98

#******************************  SOURCE  *************************************#

PATHS = megaphone.cpp
SRCDIRS = ./

#******************************  OBJ  ****************************************#

OBJDIRS = objs
OBJS = $(addprefix $(OBJDIRS)/, $(patsubst %.cpp, %.o, $(PATHS)))

#******************************  COLORS  *************************************#


GREEN			=	\033[0;32m
END				=	\033[0m

#******************************  RULES  **************************************#

all: $(NAME)

$(NAME): 	$(OBJDIRS) $(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "${GREEN}> ${NAME} was successfuly compiled 🎉${END}"

$(OBJDIRS):
	@mkdir -p $(OBJDIRS)

$(OBJDIRS)/%.o: $(SRCDIRS)/%.cpp
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJDIRS)
			@echo "${GREEN}> Objects deleted${END}"

fclean : clean
			@rm -f ${NAME}
			@echo "${GREEN}> Cleaning of ${NAME} has been done${END}"

re: fclean all
