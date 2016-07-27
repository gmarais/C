#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 12:39:07 by gmarais           #+#    #+#              #
#    Updated: 2014/03/23 18:53:58 by gmarais          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./include

NAME = libft.a

# Directories
LIB_DIR=lib
INC_DIR=include
SRC_DIR=sources
OBJ_DIR=objects

ifeq ($(OS),Windows_NT)
	OS_DETECTED=Windows
else
	OS_DETECTED=$(shell uname -s)
endif
#-------------------------------------------------------------------# Windows #
ifeq ($(OS_DETECTED), Windows)
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
	REDIRECT_ERROR=2>nul
endif
#---------------------------------------------------------------------# Linux #
ifeq ($(OS_DETECTED), Linux)
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
	REDIRECT_ERROR=
endif
#------------------------------------------------------------------# Mac OS X #
ifeq ($(OS_DETECTED), Darwin)
# Commands
	RM=rm -rf
	RMDIR=rm -rf
	ECHO=echo
# Feedback
	RED=""
	GREEN=""
	CYAN=""
	ENDL=""
	ENDC=""
	COMPILED="$@"
	REDIRECT_ERROR=
endif
#---------------------------------------------------------------# Compilation #
# Sources
SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstgetone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstadd_back.c \
	ft_sin.c \
	ft_cos.c \
	ft_tan.c \
	ft_exp.c \
	ft_abs.c \
	ft_absf.c \
	ft_sgn.c \
	ft_realloc.c \
	ft_putd.c \
	ft_getline.c \
	ft_atof.c \
	get_next_line.c \
	file_get_content.c \
	ft_strtablen.c

# Objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Rules
all: $(NAME)
	@$(ECHO) "Library compiled!$(ENDL)"

$(NAME): $(OBJ_DIR) $(OBJ) $(LIB_DIR)
	@$(ECHO) "Compiling library...$(ENDL)"
	@ar rc $(LIB_DIR)/$(NAME) $(OBJ)

$(LIB_DIR):
	@$(ECHO) "Creating lib directory$(ENDL)"
	@mkdir $(LIB_DIR)
	@$(ECHO) "Compiling objects:$(ENDL)"

$(OBJ_DIR):
	@$(ECHO) "Creating objects directory$(ENDL)"
	@mkdir $(OBJ_DIR)
	@$(ECHO) "Compiling objects:$(ENDL)"

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@
	@$(ECHO) "$(CYAN)$(COMPILED)$(ENDC)"

clean:
	@$(ECHO) "$(RED)Cleaning objects$(ENDL)"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@$(ECHO) "$(RED)Removing binary$(ENDL)"
	@$(RMDIR) $(LIB_DIR)

re: fclean
	@make --no-print-directory $(NAME)
