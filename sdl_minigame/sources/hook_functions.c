#include <game.h>

void toggle_pause()
{
	g_data.game_paused = !g_data.game_paused;
	if (g_data.game_paused)
	{
		g_data.pause_time = g_data.last_time;
		return;
	}
	float pause_time = g_data.last_time - g_data.pause_time;
	lst_t *curr = g_data.go_list;
	while (curr != 0)
	{
		curr->go->spawn_time += pause_time;
		if (curr->go->animator)
			curr->go->animator->last_time += pause_time;
		if (curr->go->ai_handler)
			curr->go->ai_handler->last_move_order += pause_time;
		weapon_t *w = curr->go->weapon;
		while (w)
		{
			w->last_shot += pause_time;
			w = w->next;
		}

		curr = curr->next;
	}
}

void shoot()
{
	if (g_data.is_dead || g_data.game_paused)
		return;
	if (!g_data.is_playing)
	{
		g_data.is_playing = 1;
		g_data.player->img_index = 0;
	}
	if (g_data.player->weapon)
	{
		weapon_t *w = g_data.player->weapon;
		while (w)
		{
			w->fire(w, g_data.player);
			w = w->next;
		}
	}
}

void move_forward()
{
	if (g_data.is_dead || g_data.game_paused)
		return;
	float pos_x = g_data.player->pos.x +  (460.0f) * g_data.delta_time;
	if (pos_x > 1024 - 35)
		pos_x = 1024 - 35;
	g_data.player->pos.x = pos_x;
}

void move_backward()
{
	if (g_data.is_dead || g_data.game_paused)
		return;
	float pos_x = g_data.player->pos.x - (360.0f) * g_data.delta_time;
	if (pos_x < 35)
		pos_x = 35.0f;
	g_data.player->pos.x = pos_x;
}

void move_up()
{
	if (g_data.is_dead || g_data.game_paused)
		return;
	float pos_y = g_data.player->pos.y - (560.0f) * g_data.delta_time;
	if (pos_y < 35)
		pos_y = 35.0f;
	g_data.player->pos.y = pos_y;
}

void move_down()
{
	if (g_data.is_dead || g_data.game_paused)
		return;
	float pos_y = g_data.player->pos.y + (460.0f) * g_data.delta_time;
	if (pos_y > 605)
		pos_y = 605.0f;
	g_data.player->pos.y = pos_y;
}

