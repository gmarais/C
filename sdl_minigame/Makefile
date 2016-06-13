EXEC=game

ifeq ($(OS),Windows_NT)
	OS_DETECTED=Windows
else
	OS_DETECTED=$(shell uname -s)
endif
#-------------------------------------------------------------------# Windows #
ifeq ($(OS_DETECTED), Windows)
INCLUDES=-mwindows -I../../mingw_libraries/SDL-1.2.15/include -I../../mingw_libraries/SDL-1.2.15/include/SDL -I../../mingw_libraries/SDL_ttf-2.0.11/include -I./headers/

LDFLAGS=-L../../mingw_libraries/SDL-1.2.15/lib -lSDLmain -lSDL -L../../mingw_libraries/SDL_ttf-2.0.11/lib/x86 -lSDL_ttf

RESFILE=winres/game.res

endif
#---------------------------------------------------------------------# Linux #
ifeq ($(OS_DETECTED), Linux)
INCLUDES=-I./headers/

LDFLAGS=-lSDLmain -lSDL -lSDL_ttf

RESFILE=

endif


SRC=sources/main.c \
sources/load_images.c \
sources/draw.c \
sources/game.c \
sources/go.c \
sources/tick_objects.c \
sources/base_weapon.c \
sources/tact_weapon.c \
sources/spawn_ships.c \
sources/collisions.c \
sources/explosions.c \
sources/hook_functions.c \
sources/key_hooks.c \
sources/ui.c \
sources/ai.c \
sources/life_pickup.c

all:
	@gcc $(SRC) $(RESFILE) $(INCLUDES) $(LDFLAGS) -o $(EXEC)
	@echo "\n\tProgram created.\n"
run: all
	@echo "\n\tRunning program.\n"
	@./$(EXEC)
clean:
	@rm $(EXEC)
	@echo "\n\tProgram removed.\n"

