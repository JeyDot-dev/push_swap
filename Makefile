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
NAME		=	push_swap

#SRC_SUBDIR	=	file.c
SRC_ROOT	=	main.c
SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRC			=	${addprefix ${SRC_DIR},${SRC_ROOT}}
#				${addprefix ${SRC_DIR}subdir/,${SRC_SUBDIR}} \

OBJ 		=	${SRC:%.c=%.o}
OBJF		=	${addprefix ${OBJ_DIR},${notdir ${OBJ}}}


HEADER_DIR	=	libft/	inc/
LIB_DIR		=	libft/ 
LIB_FILES	=	ft

HEADERS		=	${addprefix -I,${HEADER_DIR}}
LIBS		=	${addprefix -L,${LIB_DIR}} ${addprefix -l,${LIB_FILES}}

RM			=	rm -rf
CC			=	gcc
CFLAGS		=	-Wextra -Werror -Wall

#FRAMEWORKS	=	OpenGL	AppKit
#FFLAGS		=	${addprefix -framework ,${FRAMEWORKS}}




#--------------------------------------------------------------------------------

%.o		:	%.c
			${CC} ${CFLAGS} ${HEADERS} -c $< -o ${addprefix ${OBJ_DIR},${notdir $@}}
all		:	${NAME}

${NAME}	:	complib ${OBJ}
			${CC} ${OBJF} ${LIBS}  -o ${NAME}

complib	:
			@${MAKE} -s -C libft

clean	:
			${RM} ${OBJF}
			${MAKE} -C ./libft clean

fclean	:	clean
			${MAKE} -C ./libft fclean
			${RM} ${NAME}

re		:	fclean all

#			***Linux stuff***
#INCS_LX 		=	libft/ inc/
#LIB_DIR_LX		=	libft/ inc/
#HEADERS_LX		=	${addprefix -I,${INCS_LINUX}}
#LIB_DIR_LX		=	${addprefix -L,${INCS_LINUX}}
#LIBS_LX		=	-lft
#OBJ_FLAGS_LX	=

#linux	:	fclean cleanlinux	
#			@${MAKE} -s -C libft
#			${CC} ${CFLAGS} ${HEADERS_LINUX} ${OBJS_FLAGS_LX} -c ${SRC}
#			$(CC) ${addsuffix .o,${notdir ${basename ${SRC}}}}  -Lminilibx-linux -lmlx_Linux -Llibft -lft  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#cleanlinux :
#			${MAKE} -C libft fclean
#			${RM} ${addsuffix .o,${notdir ${basename ${SRC}}}}

.PHONY	:	all clean fclean e
