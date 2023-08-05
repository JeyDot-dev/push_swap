#
#	  ____  __  __  ___  _   _     __      __   
#	 (  _ \(  )(  )/ __)( )_( )    \ \     \ \  
#	  )___/ )(__)( \__ \ ) _ (      > >     > > 
# 	 (__)  (______)(___/(_) (_)    /_/     /_/  
#
#	                   /\                        
#	                   ||                        
#	                   ||                        
#	                   \/                        
#	   __      __     ___  _    _    __    ____  
#	  / /     / /    / __)( \/\/ )  /__\  (  _ \ 
#	 < <     < <     \__ \ )    (  /(__)\  )___/ 
#	  \_\     \_\    (___/(__/\__)(__)(__)(__)   
#
#----------------------------------------------
#1;bold 2;low intensity 4;Underline 5;Blink 8;invis 9;strike
BLK	= \033[30m
RED	= \033[31m
GRN	= \033[32m
BRN	= \033[33m
BLU	= \033[34m
PUR	= \033[35m
CYN	= \033[36m
LGR	= \033[37m
RST	= \033[0m

NAME		:=	push_swap
UNAME_S 	:= $(shell uname -s)

SRC_D		:=	src/
BUILD_D		:=	.build/
LIB_D		:=	libft/
INC			:=	libft/inc/	inc/

LIB			:=	ft
INC			:=	inc/ libft/
SRC			:=	main.c	list_utils.c	load_list.c	rotate_reverse.c	pswap_atoi.c	free_utils.c	swap_push.c check_order.c
#FRAMEWORK	:=	OpenGL	AppKit

SRC			:=	$(SRC:%=$(SRC_D)%)
OBJ 		:=	$(SRC:$(SRC_D)%.c=$(BUILD_D)%.o)
DEPS        :=	$(OBJ:.o=.d)

ifeq ($(UNAME_S),Linux)
INC		 	:=	libft/inc	inc
LIB_D		:=	libft/
LIB			:=	ft
FRAMEWORK	:=	
endif
RM			:=	rm -rf
CC			:=	gcc
DIR_DUP     =	mkdir -p "$(@D)"
#-MMD -MP = Used to add dependencies during precomp. (for .h)
CPPFLAGS    :=	-MMD -MP $(addprefix -I,$(INC))
CFLAGS		:=	-Wextra -Werror -Wall
# -(r)eplace the older objects, -(c)reate if no lib, -s index stuff
AR          :=	ar
ARFLAGS     :=	-r -c -s
LDFLAGS     :=	$(addprefix -L,$(dir $(LIB_D)))
LDLIBS      :=	$(addprefix -l,$(LIB))
LDFMWK		:=	$(addprefix -framework ,$(FRAMEWORKS))
MAKEFLAGS   += --no-print-directory
#-----------------------------all------------------------------------
all		:	$(NAME)
#-----------------------------NAME-----------------------------------
$(NAME)	:	$(OBJ)
			$(MAKE) complib
			${CC} $(LDFLAGS) $(OBJ) $(LDLIBS) $(LDFMWK) -o $(NAME)
			$(info MAKING $(NAME).....)
			echo "\033[5;32m\t\tFinished compiling $(NAME) !!! $(CLR)"
#------------------------OBJ COMPILATION-----------------------------
$(BUILD_D)%.o	:	$(SRC_D)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
			echo created $(@F)

-include	${DEPS}
#----------------------------COMPLIB---------------------------------
complib	:
	$(info COMPILING THE LIBS)
	@$(MAKE) -s -C libft
ifeq ($(UNAME_S),Linux)
endif
ifeq ($(UNAME_S),Darwin)
endif
#----------------------------CLEAN-----------------------------------
clean	:
	$(RM) $(OBJ) $(DEPS)
	$(MAKE) -C libft clean
ifeq ($(UNAME_S),Darwin)
else
endif
	echo "$(CYN) \t\tALL CLEANED $(RST)"
#----------------------------FCLEAN----------------------------------
fclean	:	clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
ifeq ($(UNAME_S),Darwin)
else
endif
	echo "\033[5;36m \t\tALL F*NG CLEANED !!! $(RST)"
#------------------------------RE------------------------------------
re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT :
