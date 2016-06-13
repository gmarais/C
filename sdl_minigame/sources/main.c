#include <game.h>
#include <graphic.h>

graphic_data_t gd;

void loop()
{
	int exited = 0;

	while (!exited)
	{
		update_fps();
		tick_game();
		draw_bg();
		draw();
		if (key_hooks())
			exited = 1;
	}
}

#if defined(WIN32) && !defined(UNIX)
int WinMain(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
	{
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_putenv("SDL_VIDEO_CENTERED=center");
	gd.screen = SDL_SetVideoMode(1024, 640, 0, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE); // Ouverture de la fenêtre
	if (gd.screen == NULL)
	{
		fprintf(stderr, "Couldn't initialize Video Mode: %s\n", SDL_GetError());
		exit(1);
	}
	SDL_WM_SetCaption("Space to shoot", NULL);

	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	gd.police = TTF_OpenFont("./fonts/Arkitech Medium.ttf", 16);

	gd.bg_offset = 0;
	if (!load_images())
	{
		SDL_WM_SetIcon(gd.icon_img, NULL);
		init_game();
		loop();
		clean_quit_game();
	}
	else
		fprintf(stderr, "Couldn't load images: %s\n", SDL_GetError());

	TTF_CloseFont(gd.police);
	TTF_Quit();
	SDL_Quit();
	return EXIT_SUCCESS; // Fermeture du programme
}
