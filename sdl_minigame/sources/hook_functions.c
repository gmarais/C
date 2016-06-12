#include <game.h>

void shoot()
{
	if (g_data.is_dead)
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
	if (g_data.is_dead)
		return;
	float pos_x = g_data.player->pos.x +  (460.0f) * g_data.delta_time;
	if (pos_x > 1024 - 75)
		pos_x = 1024 - 75;
	g_data.player->pos.x = pos_x;
}

void move_backward()
{
	if (g_data.is_dead)
		return;
	float pos_x = g_data.player->pos.x - (360.0f) * g_data.delta_time;
	if (pos_x < 75)
		pos_x = 75.0f;
	g_data.player->pos.x = pos_x;
}

void move_up()
{
	if (g_data.is_dead)
		return;
	float pos_y = g_data.player->pos.y - (560.0f) * g_data.delta_time;
	if (pos_y < 0)
		pos_y = 0.0f;
	g_data.player->pos.y = pos_y;
}

void move_down()
{
	if (g_data.is_dead)
		return;
	float pos_y = g_data.player->pos.y + (460.0f) * g_data.delta_time;
	if (pos_y > 605)
		pos_y = 605.0f;
	g_data.player->pos.y = pos_y;
}

