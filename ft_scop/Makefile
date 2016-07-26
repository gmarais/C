#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/16 12:39:07 by gmarais           #+#    #+#              #
#    Updated: 2016/06/16 18:53:58 by gmarais          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
PROG_NAME=ft_scop
# Debug mode
DEBUG=no
# Directories
SRC_DIR=sources
INC_DIR=headers
OBJ_DIR=objects
LIB_DIR=libraries
EXEC_DIR=exec

ifeq ($(OS),Windows_NT)
	OS_DETECTED=Windows
else
	OS_DETECTED=$(shell uname -s)
endif
#-------------------------------------------------------------------# Windows #
ifeq ($(OS_DETECTED), Windows)
# Compiler
CC=gcc
# Flags
BASE_CFLAGS= -static-libgcc -m32
ifeq ($(DEBUG),yes)
	CFLAGS=$(BASE_CFLAGS) -g
else
	CFLAGS=$(BASE_CFLAGS)
endif
# Exec
EXEC=$(EXEC_DIR)\$(PROG_NAME).exe
# Libraries Directories
	GLEW_LIB_DIR=H:\MingwLibraries\glew-1.10.0_MinGW
	SDL2_LIB_DIR=H:\MingwLibraries\SDL2_32
# Includes
	INCLUDES=-I$(INC_DIR) -I$(LIB_DIR)/libft/include/ -I$(SDL2_LIB_DIR)/include -I$(GLEW_LIB_DIR)/include
# Links
	LDFLAGS=-L$(LIB_DIR)/libft/lib -lft -lmingw32 -L$(SDL2_LIB_DIR)/lib -lSDL2main -lSDL2 -L$(GLEW_LIB_DIR)/lib -lOpenGL32 -lglew32
# Commands
	RM=del /f
	RMDIR=rmdir /s /q
	ECHO=echo
# Feedback
	RED=
	GREEN=
	CYAN=
	ENDL=
	ENDC=
	COMPILED=$@
# gey dynamic libraries rule
DYNAMICS= if not exist $(EXEC_DIR)\glew32.dll copy $(GLEW_LIB_DIR)\bin\glew32.dll $(EXEC_DIR)\glew32.dll && \
	if not exist $(EXEC_DIR)\glew32mx.dll copy $(GLEW_LIB_DIR)\bin\glew32mx.dll $(EXEC_DIR)\glew32mx.dll && \
	if not exist $(EXEC_DIR)\SDL2.dll copy $(SDL2_LIB_DIR)\bin\SDL2.dll $(EXEC_DIR)\SDL2.dll
CLEAN_DYNAMICS=del /f $(EXEC_DIR)\glew32.dll && \
	del /f $(EXEC_DIR)\glew32mx.dll && \
	del /f $(EXEC_DIR)\SDL2.dll
endif
#---------------------------------------------------------------------# Linux #
ifeq ($(OS_DETECTED), Linux)
# Compiler
CC=gcc
# Flags
BASE_CFLAGS= -static-libgcc
ifeq ($(DEBUG),yes)
	CFLAGS=$(BASE_CFLAGS) -g
else
	CFLAGS=$(BASE_CFLAGS)
endif
# Exec
EXEC=$(EXEC_DIR)\$(PROG_NAME).x86
# Directories
	OS_LIB_DIR=$(LIB_DIR)/Linux
# Includes
	INCLUDES=-I$(INC_DIR)
# Links
	LDFLAGS=-lSDL2 -lGL -lglew32
# Commands
	RM=rm -rf
	RMDIR=rm -rf
	ECHO=/bin/echo -en
# Feedback
	RED=\e[31m
	GREEN=\e[32m
	CYAN=\e[36m
	ENDL=\n\e[0m
	ENDC=\e[0m
	COMPILED=•
# get dynamic libraries rule
DYNAMICS=
CLEAN_DYNAMICS=
endif
#------------------------------------------------------------------# Mac OS X #
ifeq ($(OS_DETECTED), Darwin)
# Compiler
CC=gcc
# Flags
BASE_CFLAGS=
ifeq ($(DEBUG),yes)
	CFLAGS=$(BASE_CFLAGS) -g
else
	CFLAGS=$(BASE_CFLAGS)
endif
# Exec
EXEC=$(EXEC_DIR)\$(PROG_NAME).x86
# Directories
	OS_LIB_DIR=$(LIB_DIR)/OSX
# Includes
	INCLUDES=-I$(INC_DIR)
# Links
	LDFLAGS=
# Commands
	RM=rm -rf
	RMDIR=rm -rf
	ECHO=echo -n
# Feedback
	RED=""
	GREEN=""
	CYAN=""
	ENDL="\n"
	ENDC=""
	COMPILED="•"
# get dynamic libraries rule
DYNAMICS=
CLEAN_DYNAMICS=
endif
#---------------------------------------------------------------# Compilation #
# Sources
SRC=main.c \
	create_window.c \
	main_loop.c \
	draw.c \
	create_compile_shader.c \
	shader.c \
	load_bmp.c \
	sdl_tools.c \
	texture.c \
	math_tools.c \
	time_tools.c \
	get_next_words.c \
	load_obj.c \
	center_scale_obj.c \
	add_face_to_model.c \
	model.c
# Objects
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# Rules
all: lib $(EXEC)
$(EXEC): $(OBJ_DIR) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $@
	@$(DYNAMICS)
ifeq ($(DEBUG), yes)
	@$(ECHO) "$(ENDL)$(GREEN)$(EXEC) generated in debug mode$(ENDL)"
else
	@$(ECHO) "$(ENDL)$(GREEN)$(EXEC) generated in release mode$(ENDL)"
endif
$(OBJ_DIR):
	@$(ECHO) "$(GREEN)Creating objects directory$(ENDL)"
	@mkdir $(OBJ_DIR)
	@$(ECHO) "$(GREEN)Compiling objects:$(ENDL)"
$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@
	@$(ECHO) "$(CYAN)$(COMPILED)$(ENDC)"
clean: clnlib
	@$(ECHO) "$(RED)Cleaning objects$(ENDL)"
	@$(RMDIR) $(OBJ_DIR)
fclean: fclnlib
	@$(ECHO) "$(RED)Cleaning objects$(ENDL)"
	@$(RMDIR) $(OBJ_DIR)
	@$(ECHO) "$(RED)Removing executable$(ENDL)"
	@$(RM) $(EXEC)
	@$(CLEAN_DYNAMICS)
re: fclean
	@make --no-print-directory $(EXEC)
#libft
lib:
	@(cd libraries/libft && $(MAKE))
clnlib:
	@(cd libraries/libft && $(MAKE) clean)
fclnlib:
	@(cd libraries/libft && $(MAKE) fclean)
