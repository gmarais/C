#include <game.h>

static go_t *spawn_life_indicator(float pos_x)
{
	go_t *indicator = new_go();
	indicator->pos.x =  24 + pos_x;
	indicator->pos.y = 24;
	indicator->dir.x = 0.0f;
	indicator->dir.y = 0.0f;
	indicator->speed = 0.0f;
	indicator->img_index = 9;
	indicator->animator = 0;
	indicator->collider = 0;
	indicator->ai_handler = 0;
	indicator->on_death = &spawn_explosion;
	add_back_go(indicator, &g_data.go_list);
	return indicator;
}

static void init_lives_indicators()
{
	g_data.lives_number = g_data.player->life_max;
	g_data.lives = malloc(sizeof(go_t*) * g_data.lives_number);
	int i = 0;
	while (i < g_data.player->life_max)
	{
		g_data.lives[i] = spawn_life_indicator(4 + i * 46);
		i++;
	}
}

static void show_dead_lives_state()
{
	int i = 0;
	while (i < g_data.lives_number)
	{
		g_data.lives[i]->img_index = 10;
		i++;
	}
}

void draw_lives_indicators()
{
	if (!g_data.lives && g_data.player)
		init_lives_indicators();
	if (!g_data.player || g_data.is_dead)
	{
		show_dead_lives_state();
		return;
	}

	int i = 0;
	while (i < g_data.player->life)
	{
		g_data.lives[i]->img_index = 9;
		i++;
	}
	while (i < g_data.player->life_max)
	{
		g_data.lives[i]->img_index = 10;
		i++;
	}
}

char *get_score_string()
{
	char *str = (char *)malloc(sizeof(char) * 256);
	sprintf(str, "Score: %i", g_data.score);
	return str;
}
