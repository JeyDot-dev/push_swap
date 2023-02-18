#			 _______                 #
#			 \  ___ `'.              #
#		 _.._ ' |--.\  \       _.._  #
#	   .' .._|| |    \  '    .' .._| #
#	   | '    | |     |  '   | '     #
#	 __| |__  | |     |  | __| |__   #
#	|__   __| | |     ' .'|__   __|  #
#	   | |    | |___.' /'    | |     #
#	   | |   /_______.'/     | |     #
#	   | |   \_______|/      | |     #
#	   | |                   | |     #
#	   |_|                   |_|     #
#/''''''''''''''''''''''''''''''''''\#
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

NAME		:=	libft.a
UNAME_S		:= $(shell uname -s)

SRC_D		:=	src/
BUILD_D		:=	.build/
LIB_D		:=
INC			:=	inc/
LIB			:=
SRC			:=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c	\
				ft_isprint.c		ft_strlen.c			ft_memset.c			ft_bzero.c		\
				ft_memcpy.c			ft_memmove.c		ft_strlcpy.c		ft_strlcat.c	\
				ft_toupper.c		ft_tolower.c		ft_strchr.c			ft_strrchr.c	\
				ft_strncmp.c		ft_memchr.c			ft_memcmp.c			ft_strnstr.c	\
				ft_atoi.c			ft_calloc.c			ft_strdup.c			ft_substr.c		\
				ft_strjoin.c		ft_strtrim.c		ft_split.c			ft_itoa.c		\
				ft_strmapi.c		ft_striteri.c		ft_putchar_fd.c		ft_putstr_fd.c	\
				ft_putendl_fd.c		ft_putnbr_fd.c		ft_itoa_base.c		ft_printf.c		\
				ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	\
				ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c	\
				ft_lstclear.c		ft_lstiter.c		ft_lstmap.c			ft_abs.c\
				get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c
FRAMEWORK	:=

SRC			:=	$(SRC:%=$(SRC_D)%)
OBJ			:=	$(SRC:$(SRC_D)%.c=$(BUILD_D)%.o)
DEPS		:=	$(OBJ:.o=.d)

ifeq ($(UNAME_S),Linux)
INC			:=	inc/	get_next_line/
LIB_D		:=
LIB			:=
FRAMEWORK	:=
endif
RM			:=	rm -rf
CC			:=	gcc
DIR_DUP		=	mkdir -p "$(@D)"
#-MMD -MP = Used to add dependencies during precomp. (for .h)
CPPFLAGS	:=	-MMD -MP $(addprefix -I,$(INC))
CFLAGS		:=	-Wextra -Werror -Wall
# -(r)eplace the older objects, -(c)reate if no lib, -s index stuff
AR			:=	ar
ARFLAGS		:=	-r -c -s
LDFLAGS		:=	$(addprefix -L,$(dir $(LIB_D)))
LDLIBS		:=	$(addprefix -l,$(LIB))
LDFMWK		:=	$(addprefix -framework ,$(FRAMEWORKS))
MAKEFLAGS	+=	--no-print-directory
#-----------------------------all------------------------------------
all		:	$(NAME)
#-----------------------------NAME-----------------------------------
$(NAME)	:	$(OBJ)
			$(MAKE) complib
#			${CC} $(LDFLAGS) $(OBJ) $(LDLIBS) $(LDFMWK) -o $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)
			ranlib $(NAME)
			echo "\033[5;32m\t\tFinished compiling $(NAME) !!! $(CLR)"
			$(info MAKING $(NAME).....)
#------------------------OBJ COMPILATION-----------------------------
$(BUILD_D)%.o	:	$(SRC_D)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
			echo created $(@F)

-include	${DEPS}
#----------------------------COMPLIB---------------------------------
complib	:
	$(info COMPILING THE LIBS)
ifeq ($(UNAME_S),Linux)
endif
ifeq ($(UNAME_S),Darwin)
endif
#----------------------------CLEAN-----------------------------------
clean	:
	$(RM) $(OBJ) $(DEPS)
ifeq ($(UNAME_S),Darwin)
else
endif
	echo "$(CYN) \t\t$(basename $(NAME)) CLEANED $(RST)"
#----------------------------FCLEAN----------------------------------
fclean	:	clean
	$(RM) $(NAME)
ifeq ($(UNAME_S),Darwin)
else
endif
	echo "\033[5;36m \t\t$(basename $(NAME)) F*NG CLEANED !!! $(RST)"
#------------------------------RE------------------------------------
re		:	fclean all
info	:
			$(info $(OBJ))
.PHONY	:	all clean fclean re info
.SILENT :
