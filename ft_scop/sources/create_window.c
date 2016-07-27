#include "main.h"

static int process_error(char *msg)
{
	ft_putstr("Error: ");
	ft_putendl_fd(msg, 2);
	return -1;
}

void add_attrib(int att_id, int length, float *data, unsigned int *vboid)
{
	glGenBuffers(1, vboid);
	glBindBuffer(GL_ARRAY_BUFFER, *vboid);
	glBufferData(GL_ARRAY_BUFFER, g_env.mdl->v_size * length * sizeof(GLfloat),
			data, GL_STATIC_DRAW);
	glVertexAttribPointer(att_id, length, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

static void init_shaders(char *obj_file, char *img_file)
{
	g_env.mdl = new_model(obj_file);
	load_model(g_env.mdl);
	glGenVertexArrays(1, &(g_env.mdl->vaoid));
	glBindVertexArray(g_env.mdl->vaoid);
	add_attrib(0, 3, g_env.mdl->positions, &g_env.mdl->positions_vboid);
	add_attrib(1, 4, g_env.mdl->colors, &g_env.mdl->colors_vboid);
	add_attrib(2, 2, g_env.mdl->uvs, &g_env.mdl->uvs_vboid);
	g_env.texture = new_texture(img_file);
	if (load_texture(g_env.texture))
	{
		ft_putendl_fd("Failed to load texture...", 2);
	}
	g_env.shader = new_shader("shaders/texture.vert", "shaders/texture.frag");
	if (load_shader(g_env.shader))
	{
		ft_putendl_fd("Failed to load shader...", 2);
	}
	g_env.proj = create_proj_matrix(60.0
		, (double)WIN_WIDTH / (double)WIN_HEIGHT
		,  1.0, 100.0);
	g_env.mv = IDENTITY_MATRIX;
}

static void set_sdl_gl_attributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

static void init_model_view()
{
	const float eye[3] = {5, 5, 5};
	const float center[3] = {0, 0, 0};
	const float up[3] = {0, 1, 0};

	g_env.mv = look_at(eye, center, up);
}

int create_window(char *obj_file, char *img_file)
{
	ft_bzero(&g_env, sizeof(t_env));
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		return process_error("Initialisation failed");
	set_sdl_gl_attributes();
	g_env.w = SDL_CreateWindow("Test OpenGL"
		, SDL_WINDOWPOS_CENTERED
		, SDL_WINDOWPOS_CENTERED
		, WIN_WIDTH, WIN_HEIGHT
		, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(g_env.w == 0)
		return process_error("Window not created");
	g_env.context = SDL_GL_CreateContext(g_env.w);
	if(g_env.context == 0)
		return process_error("Context for OpenGL not created");
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK)
		return process_error("Erreur d'initialisation de GLEW");
	ft_putendl((char *)glGetString(GL_RENDERER));
	ft_putendl((char *)glGetString(GL_VERSION));
	ft_putendl((char *)glGetString( GL_SHADING_LANGUAGE_VERSION ));
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2, 0.2, 0.3, 1);
	init_shaders(obj_file, img_file);
	init_model_view();
	return 0;
}
