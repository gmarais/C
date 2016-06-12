#include <game.h>

static void heal_player(vector2 pos)
{
	(void)pos;
	if (g_data.player->life < g_data.player->life_max)
		g_data.player->life++;
}

void spawn_life_pickup(vector2 pos)
{
	go_t *pu = new_go();
	pu->owner = PICKUP;
	pu->life = pu->life_max = 1;
	pu->pos = pos;
	pu->dir.x = -1.0f;
	pu->dir.y = 0.0f;
	pu->speed = 400.0f;
	pu->img_index = 12;
	pu->animator = 0;
	pu->collider = new_collider();
	pu->collider->size.x = 32;
	pu->collider->size.y = 32;
	pu->collider->damage = 0;
	pu->on_death = &heal_player;
	add_back_go(pu, &g_data.go_list);
}
