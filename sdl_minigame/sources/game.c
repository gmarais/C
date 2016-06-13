#include <game.h>

struct game_data g_data;

void update_fps()
{
	float curr = clock();
	g_data.delta_time = (curr - g_data.last_time) / CLOCKS_PER_SEC;
	g_data.fps = (1.0 / g_data.delta_time);
	g_data.last_time = curr;
}

int init_game()
{
	g_data.game_paused = 0;
	g_data.game_ended = 0;
	spawn_player();
	spawn_enemy(220.0f);
	spawn_enemy(420.0f);
	g_data.last_time = clock();
	g_data.last_shot = g_data.last_time;
	g_data.destroyer_time = g_data.last_time;
}

void tick_game()
{
	if (g_data.game_paused)
		return;
	if (g_data.is_dead && g_data.last_time - g_data.death_time >= 2.f * CLOCKS_PER_SEC)
	{
		clean_quit_game();
		init_game();
	}
	if (g_data.last_time - g_data.destroyer_time >= 30.f * CLOCKS_PER_SEC)
	{
		g_data.destroyer_time = g_data.last_time;
		spawn_destroyer(rand() % 640);
	}
	tick_objects();
}

void clean_quit_game()
{
	g_data.game_ended = 1;
	while (g_data.go_list != 0)
	{
		remove_go(&g_data.go_list);
	}
	g_data.lives = 0;
}

