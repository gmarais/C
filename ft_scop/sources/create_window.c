#include "main.h"

static int process_error(char *msg)
{
	ft_putstr("Error: ");
	ft_putendl_fd(msg, 2);
	return -1;
}

static void init_shaders(char *obj_file, char *img_file)
{
	char *path;

	path = ft_strjoin(OBJ_PATH, obj_file);
	g_env.mdl = new_model(path);
	load_model(g_env.mdl);
	free(path);
	path = ft_strjoin(IMG_PATH, img_file);
	g_env.texture = new_texture(path);
	if (load_texture(g_env.texture))
	{
		ft_putendl_fd("Failed to load texture...", 2);
	}
	free(path);
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
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
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
	if(glewInit() != GLEW_OK)
		return process_error("Erreur d'initialisation de GLEW");
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5, 0.5, 0.5, 1);
	init_shaders(obj_file, img_file);
	init_model_view();
	return 0;
}
