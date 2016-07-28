#include "main.h"

static void get_inputs_rotations(SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_KP_1)
		g_env.rots[0] = g_env.rots[0] < 1 ? g_env.rots[0] + 1 : 1;
	else if (e.key.keysym.sym == SDLK_KP_2)
		g_env.rots[1] = g_env.rots[1] < 1 ? g_env.rots[1] + 1 : 1;
	else if (e.key.keysym.sym == SDLK_KP_3)
		g_env.rots[2] = g_env.rots[2] < 1 ? g_env.rots[2] + 1 : 1;
	else if (e.key.keysym.sym == SDLK_KP_4)
		g_env.rots[0] = g_env.rots[0] > -1 ? g_env.rots[0] - 1 : -1;
	else if (e.key.keysym.sym == SDLK_KP_5)
		g_env.rots[1] = g_env.rots[1] > -1 ? g_env.rots[1] - 1 : -1;
	else if (e.key.keysym.sym == SDLK_KP_6)
		g_env.rots[2] = g_env.rots[2] > -1 ? g_env.rots[2] - 1 : -1;
}

static void get_inputs_translations(SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_q)
		g_env.trans[0] = g_env.trans[0] < 1 ? g_env.trans[0] + 1 : 1;
	else if (e.key.keysym.sym == SDLK_a)
		g_env.trans[0] = g_env.trans[0] > -1 ? g_env.trans[0] - 1 : -1;
	else if (e.key.keysym.sym == SDLK_w)
		g_env.trans[1] = g_env.trans[1] < 1 ? g_env.trans[1] + 1 : 1;
	else if (e.key.keysym.sym == SDLK_s)
		g_env.trans[1] = g_env.trans[1] > -1 ? g_env.trans[1] - 1 : -1;
	else if (e.key.keysym.sym == SDLK_d)
		g_env.trans[2] = g_env.trans[2] < 1 ? g_env.trans[2] + 1 : 1;
	else if (e.key.keysym.sym == SDLK_e)
		g_env.trans[2] = g_env.trans[2] > -1 ? g_env.trans[2] - 1 : -1;
}

static int process_inputs()
{
	SDL_Event e;

	SDL_PollEvent(&e);
	if(e.window.event == SDL_WINDOWEVENT_CLOSE)
		return 1;
	if (e.type != SDL_KEYDOWN)
		return 0;
	if (e.key.keysym.sym == SDLK_ESCAPE)
		return 1;
	get_inputs_rotations(e);
	if (e.key.keysym.sym == SDLK_KP_0)
		g_env.text_is_on = g_env.text_is_on == 0 ? 1 : 0;
	get_inputs_translations(e);
	return 0;
}

static void init_model_view()
{
	const float eye[3] = {5, 5, 5};
	const float center[3] = {0, 0, 0};
	const float up[3] = {0, 1, 0};

	g_env.mv = look_at(eye, center, up);
}

void main_loop()
{
	short int exited;

	init_model_view();
	exited = 0;
	while (!exited)
	{
		exited = process_inputs();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glUseProgram(g_env.shader->id_program);
		glBindVertexArray(g_env.mdl->vaoid);
		draw();
		glBindVertexArray(0);
		glUseProgram(0);
		SDL_GL_SwapWindow(g_env.w);
	}
	delete_model(g_env.mdl);
}