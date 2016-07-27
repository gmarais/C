#include "shader.h"

static void process_compile_error(GLuint *id_shader)
{
	GLint error_size;
	char *error;

	error_size = 0;
	glGetShaderiv(*id_shader, GL_INFO_LOG_LENGTH, &error_size);
	error = (char *)malloc(sizeof(char) * (error_size + 1));
	error[error_size] = 0;
	ft_putendl_fd("Error compiling shader:", 2);
	ft_putendl_fd(error, 2);
	free(error);
	glDeleteShader(*id_shader);
}

static int create_shader(GLuint *id_shader,	GLenum type)
{
	*id_shader = glCreateShader(type);
	if(*id_shader == 0)
	{
		ft_putendl_fd("Error, the type of shader doesn't exist", 2);
		return -1;
	}
	return 0;
}

static int get_source_code(char **content, GLuint *id_shader, char *source_file)
{
	*content = (GLchar *)file_get_content(source_file);
	if (*content == NULL)
	{
		ft_putendl_fd("Error, failed to get content from file", 2);
		ft_putendl_fd(source_file, 2);
		glDeleteShader(*id_shader);
		return -1;
	}
	return 0;
}

static int compile_shader(GLuint id_shader, const GLchar ** source_content)
{
	GLint compile_status;

	glShaderSource(id_shader, 1, source_content, 0);
	glCompileShader(id_shader);
	glGetShaderiv(id_shader, GL_COMPILE_STATUS, &compile_status);
	if(compile_status != GL_TRUE)
	{
		process_compile_error(&id_shader);
		return -1;
	}
	return 0;
}

int create_compile_shader(shader_t *shader)
{
	if (create_shader(&shader->id_vert, GL_VERTEX_SHADER)
		|| get_source_code(&shader->vert_src_content, &shader->id_vert, shader->vert_src))
		return -1;
	if (create_shader(&shader->id_frag, GL_FRAGMENT_SHADER)
		|| get_source_code(&shader->frag_src_content, &shader->id_frag, shader->frag_src))
		return -1;
	if (compile_shader(shader->id_vert, (const GLchar **)(&shader->vert_src_content))
		||compile_shader(shader->id_frag, (const GLchar **)(&shader->frag_src_content)))
		return -1;
	return 0;
}