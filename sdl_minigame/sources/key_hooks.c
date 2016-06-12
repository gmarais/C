#include <game.h>
#include <graphic.h>

float move_y = 0.0f;
float move_x = 0.0f;
short int is_shooting = 0;
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
        if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 65)
			is_shooting = 1;
        else if (event.type == SDL_KEYUP && event.key.keysym.scancode == 65 && is_shooting > 0)
			is_shooting = 0;

        if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 111)
			move_y = -1.0f;
        else if (event.type == SDL_KEYUP && event.key.keysym.scancode == 111 && move_y < 0)
			move_y = 0.0f;

        if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 116)
			move_y = 1.0f;
        else if (event.type == SDL_KEYUP && event.key.keysym.scancode == 116 && move_y > 0)
			move_y = 0.0f;

        if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 114)
			move_x = 1.0f;
        else if (event.type == SDL_KEYUP && event.key.keysym.scancode == 114 && move_x > 0)
			move_x = 0.0f;

        if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 113)
			move_x = -1.0f;
        else if (event.type == SDL_KEYUP && event.key.keysym.scancode == 113 && move_x < 0)
			move_x = 0.0f;

        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 9))
			return 1.0f;
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

