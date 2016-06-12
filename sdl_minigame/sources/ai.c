#include <game.h>

static void enemy_ai_tick(void *data)
{
	go_t *go = (go_t *)data;
	ai_handler_t *aih = go->ai_handler;
	if (g_data.last_time - aih->last_move_order > aih->move_order_interval)
	{
		aih->last_move_order = g_data.last_time;
		if (go->pos.x < 550 && go->dir.x < 0)
			go->dir.x = .5f;
		if (go->pos.x >= 800 && go->dir.x > 0)
			go->dir.x = -.5f;
		if (go->pos.y < 200 && go->dir.y < 0)
			go->dir.y = .5f;
		if (go->pos.y >= 440 && go->dir.y > 0)
			go->dir.y = -.5f;
	}
	if (go->pos.x < 800 || go->dir.x > -0.7f)
	{
		weapon_t *w = go->weapon;
		while (w)
		{
			w->fire(w, go);
			w = w->next;
		}
	}
}

ai_handler_t *new_enemy_ai()
{
	ai_handler_t *handler = new_ai_handler();
	handler->last_move_order = g_data.last_time;
	handler->move_order_interval = 1000000.0f;
	handler->ai_tick = &enemy_ai_tick;
	return handler;
}
