#ifndef _MAIN_
#define _MAIN_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <libft.h>
#include <stdlib.h>
#include "math_tools.h"
#include "shader.h"
#include "texture.h"
#include "time_tools.h"
#include "model.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 640

// globals
typedef struct s_env {
	SDL_Window* w;
	SDL_GLContext *context;
	mat4_t proj;
	mat4_t mv;
	shader_t *shader;
	texture_t *texture;
	t_model *mdl;
	short int rots[3];
	short int trans[3];
	float col_to_text;
	short int text_is_on;
} t_env;

extern t_env g_env;

void draw();
void main_loop();
int create_window(char *obj_file, char *img_file);


#endif