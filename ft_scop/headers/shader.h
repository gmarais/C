#ifndef _SHADER_
#define _SHADER_

#include <GL/glew.h>
#include <stdlib.h>
#include "libft.h"

// struct shader

typedef struct shader {
	GLuint id_vert;
	char *vert_src;
	GLchar *vert_src_content;
	GLuint id_frag;
	char *frag_src;
	GLchar *frag_src_content;
	GLuint id_program;
	GLuint u_mdlview;
	GLuint u_proj;
	GLuint u_coltotext;
} shader_t;

shader_t *new_shader(char *vertex_source, char *fragment_source);
void delete_shader(shader_t *shader);
int load_shader(shader_t *shader);
int create_compile_shader(shader_t *shader);

#endif
