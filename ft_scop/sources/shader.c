#include "shader.h"

shader_t *new_shader(char *vert_src, char *frag_src)
{
	shader_t *shader;
	shader = (shader_t *)malloc(sizeof(shader_t));
	shader->id_vert = 0;
	shader->id_frag = 0;
	shader->id_program = 0;
	shader->vert_src = vert_src;
	shader->frag_src = frag_src;
	return shader;
}

void delete_shader(shader_t *shader)
{
	if(glIsShader(shader->id_vert) == GL_TRUE)
		glDeleteShader(shader->id_vert);
	if(glIsShader(shader->id_frag) == GL_TRUE)
		glDeleteShader(shader->id_frag);
	if(glIsProgram(shader->id_program) == GL_TRUE)
		glDeleteProgram(shader->id_program);
}

int load_shader(shader_t *shader)
{
	GLint link_status;

	delete_shader(shader);
	if(create_compile_shader(shader))
		return -1;
	shader->id_program = glCreateProgram();
	glAttachShader(shader->id_program, shader->id_vert);
	glAttachShader(shader->id_program, shader->id_frag);
	glBindAttribLocation(shader->id_program, 0, "in_Vertex");
	glBindAttribLocation(shader->id_program, 1, "in_Color");
	glBindAttribLocation(shader->id_program, 2, "in_TexCoord0");
	glLinkProgram(shader->id_program);
	link_status = 0;
	glGetProgramiv(shader->id_program, GL_LINK_STATUS, &link_status);
	if(link_status != GL_TRUE)
	{
		ft_putendl_fd("Error loading shader:", 2);
		glDeleteProgram(shader->id_program);
		return -1;
	}
	return 0;
}
