EXEC=game

INCLUDES=./headers/

SRC=sources/main.c \
sources/load_images.c \
sources/draw.c \
sources/game.c \
sources/go.c \
sources/tick_objects.c \
sources/base_weapon.c \
sources/spawn_ships.c \
sources/collisions.c \
sources/explosions.c \
sources/hook_functions.c \
sources/key_hooks.c \
sources/ui.c \
sources/ai.c \
sources/life_pickup.c

all:
	@gcc $(SRC) -I$(INCLUDES) -lSDLmain -lSDL -lSDL_ttf -o $(EXEC)
	@echo "\n\tProgram created.\n"
run: all
	@echo "\n\tRunning program.\n"
	@./$(EXEC)
clean:
	@rm $(EXEC)
	@echo "\n\tProgram removed.\n"

