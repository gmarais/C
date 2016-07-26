#include "main.h"

t_env	g_env;

static void cleanQuit()
{
	if (g_env.context != 0)
	{
		SDL_GL_DeleteContext(g_env.context);
		g_env.context = 0;
	}
	if (g_env.w != 0)
	{
		SDL_DestroyWindow(g_env.w);
		g_env.w = 0;
	}
	if (g_env.shader)
	{
		delete_shader(g_env.shader);
		free(g_env.shader);
		g_env.shader = NULL;
	}
	if (g_env.texture)
	{
		delete_texture(g_env.texture);
		free(g_env.texture);
		g_env.texture = NULL;
	}
	SDL_Quit();
}

int main(int ac, char **av)
{
	char *obj_file;
	char *img_file;

	obj_file = ac > 1 ? av[1] : BASE_OBJ;
	img_file = ac > 2 ? av[2] : BASE_IMG;
	if (create_window(obj_file, img_file) == 0)
		main_loop();
	cleanQuit();
	return 0;
}