#include <game.h>
#include <graphic.h>

float move_y = 0.0f;
float move_x = 0.0f;
short int is_shooting = 0;
short int is_windowed = 1;
int key_hooks()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
/*
		if (event.type == SDL_KEYDOWN)
		{
			printf("keycode: %u\n", event.key.keysym.scancode);
		}
*/
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE)
			is_shooting = 1;
		else if (event.type == SDL_KEYUP && event.key.keysym.sym==SDLK_SPACE && is_shooting > 0)
			is_shooting = 0;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_UP)
			move_y = -1.0f;
		else if (event.type == SDL_KEYUP && event.key.keysym.sym==SDLK_UP && move_y < 0)
			move_y = 0.0f;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_DOWN)
			move_y = 1.0f;
		else if (event.type == SDL_KEYUP && event.key.keysym.sym==SDLK_DOWN && move_y > 0)
			move_y = 0.0f;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT)
			move_x = 1.0f;
		else if (event.type == SDL_KEYUP && event.key.keysym.sym==SDLK_RIGHT && move_x > 0)
			move_x = 0.0f;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT)
			move_x = -1.0f;
		else if (event.type == SDL_KEYUP && event.key.keysym.sym==SDLK_LEFT && move_x < 0)
			move_x = 0.0f;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_p)
			toggle_pause();

		if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE && is_windowed))
			return 1.0f;

#ifndef WIN32
		else if (event.type == SDL_KEYDOWN && (event.key.keysym.sym==SDLK_ESCAPE || event.key.keysym.sym==SDLK_F11) && !is_windowed)
		{
				SDL_putenv("SDL_VIDEO_CENTERED=center");
				gd.screen = SDL_SetVideoMode(1024, 640, 0, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
				is_windowed = !is_windowed;
		}
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym==SDLK_F11 && is_windowed)
		{
				gd.screen = SDL_SetVideoMode(1024, 640, 0, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE|SDL_FULLSCREEN);
				is_windowed = !is_windowed;
		}
#endif
	}

	if (move_y < 0)
		move_up();
	else if (move_y > 0)
		move_down();

	if (move_x < 0)
		move_backward();
	else if (move_x > 0)
		move_forward();

	if (is_shooting)
		shoot();
	return 0;
}

