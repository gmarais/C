#include <game.h>
#include <graphic.h>

void draw_ui()
{
	draw_lives_indicators();
	SDL_Color font_color = {200, 255, 128};
	char *score_string = get_score_string();
	SDL_Surface *score_text = TTF_RenderText_Blended(gd.police, score_string, font_color);
	SDL_Rect pos;
	pos.x = 1004 - score_text->w;
	pos.y = 20;
	SDL_BlitSurface(score_text, NULL, gd.screen, &pos);
	free(score_string);
	SDL_FreeSurface(score_text);

	SDL_Color grey_color = {128, 128, 128};
	char fps_string[256];
	sprintf(fps_string, "fps: %i\n", (int)g_data.fps);
	SDL_Surface *fps_text = TTF_RenderText_Blended(gd.police, fps_string, grey_color);
	pos.x = 1024 - fps_text->w;
	pos.y = 624;
	SDL_BlitSurface(fps_text, NULL, gd.screen, &pos);
	SDL_FreeSurface(fps_text);
}

void draw_bg()
{
	gd.bg_offset = (gd.bg_offset <= -1024) ? 0 : gd.bg_offset - g_data.delta_time * 200.0f;
	SDL_FillRect(gd.screen, NULL, 0x000000);
	SDL_Rect pos;
	pos.x = gd.bg_offset;
	pos.y = 0;
	SDL_BlitSurface(gd.bg_img, NULL, gd.screen, &pos);
	pos.x = gd.bg_offset + 1024;
	SDL_BlitSurface(gd.bg_img, NULL, gd.screen, &pos);
}

void draw()
{
	SDL_Rect pos;

	// Lock the screen for direct access to the pixels
	if ( SDL_MUSTLOCK(gd.screen) )
	{
		if ( SDL_LockSurface(gd.screen) < 0 )
		{
			fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
			return;
		}
	}

	draw_bg();
	draw_ui();
	lst_t *go_list_current = g_data.go_list;
	while (go_list_current != 0)
	{
		pos.x = go_list_current->go->pos.x - (gd.img[go_list_current->go->img_index]->w * 0.5);
		pos.y = go_list_current->go->pos.y - (gd.img[go_list_current->go->img_index]->h * 0.5);
		SDL_BlitSurface(gd.img[go_list_current->go->img_index], NULL, gd.screen, &pos);
		go_list_current = go_list_current->next;
	}

	SDL_Flip(gd.screen);

    if ( SDL_MUSTLOCK(gd.screen) )
	{
        SDL_UnlockSurface(gd.screen);
    }
}

