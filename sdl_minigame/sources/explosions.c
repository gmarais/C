#include <game.h>

void spawn_explosion(vector2 pos)
{
	go_t *explosion = new_go();
	explosion->pos.x = pos.x - 5.0f;
	explosion->pos.y = pos.y;
	explosion->dir.x = 1.0f;
	explosion->dir.y = 0.0f;
	explosion->speed = 0.0f;
	explosion->img_index = 4;
	explosion->animator = new_animator();
	explosion->animator->loop = 1;
	explosion->animator->last_time = g_data.last_time;
	explosion->animator->interval = 0.075f * CLOCKS_PER_SEC;
	explosion->animator->var_index = 0;
	explosion->animator->var_tab_size = 4;
	explosion->animator->var_tab = (int *)malloc(sizeof(int) * 4);
	explosion->animator->var_tab[0] = 4;
	explosion->animator->var_tab[1] = 5;
	explosion->animator->var_tab[2] = 6;
	explosion->animator->var_tab[3] = 7;
	explosion->collider = 0;
	explosion->ai_handler = 0;
	explosion->on_death = 0;
	add_back_go(explosion, &g_data.go_list);
}

void explode_and_score(vector2 pos)
{
	g_data.score += 1;
	spawn_explosion(pos);
}

void explode_enemy_ship(vector2 pos)
{
	g_data.score += 64;
	spawn_explosion(pos);
	int i = 0;
	vector2 ex_pos;
	while (i++ < 6)
	{
		ex_pos.x = pos.x - 50 + rand() % 100;
		ex_pos.y = pos.y - 35 + rand() % 70;
		spawn_explosion(ex_pos);
	}

	if (rand() % 2 == 0)
	{
		spawn_enemy(rand() % 540 + 50);
	}
	else
	{
		spawn_tact_enemy(rand() % 540 + 50);
	}

	if (rand() % 6 == 0)
		spawn_life_pickup(pos);
}

void explode_destroyer(vector2 pos)
{
	g_data.score += 256;
	spawn_explosion(pos);
	int i = 0;
	vector2 ex_pos;
	while (i++ < 20)
	{
		ex_pos.x = pos.x - 400 + rand() % 888;
		ex_pos.y = pos.y - 140 + rand() % 280;
		spawn_explosion(ex_pos);
	}
	if (rand() % 6 == 0)
		spawn_life_pickup(pos);
}

void explode_ship(vector2 pos)
{
	spawn_explosion(pos);
	int i = 0;
	vector2 ex_pos;
	while (i++ < 4)
	{
		ex_pos.x = pos.x - 31 + rand() % 62;
		ex_pos.y = pos.y - 35 + rand() % 70;
		spawn_explosion(ex_pos);
	}
	g_data.is_dead = 1;
	g_data.death_time = g_data.last_time;
}

