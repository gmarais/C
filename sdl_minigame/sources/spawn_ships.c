#include <game.h>
#include <weapons.h>

void spawn_player()
{
	g_data.score = 0;
	g_data.is_playing = 0;
	g_data.player = new_go();
	g_data.player->owner = PLAYER;
	g_data.player->life = 5;
	g_data.player->life_max = 5;
	g_data.player->pos.x = 80.0f;
	g_data.player->pos.y = 320.0f;
	g_data.player->dir.x = 1.0f;
	g_data.player->dir.y = 0.0f;
	g_data.player->speed = 0.0f;
	g_data.player->img_index = 11;
	g_data.player->animator = 0;
	g_data.player->collider = new_collider();
	g_data.player->collider->size.x = 62;
	g_data.player->collider->size.y = 70;
	g_data.player->collider->damage = 10;
	g_data.player->ai_handler = 0;
	vector2 w_pos;
	w_pos.x = 80.0f;
	w_pos.y = 0.0f;
	g_data.player->weapon = new_base_weapon(w_pos);
	g_data.player->weapon->fire_interval = 0.2f * CLOCKS_PER_SEC;
	g_data.player->on_death = &explode_ship;
	add_back_go(g_data.player, &g_data.go_list);
	g_data.is_dead = 0;
	g_data.death_time = g_data.last_time;
}

void spawn_enemy(float pos_y)
{
	go_t *enemy = new_go();
	enemy->owner = ENEMY;
	enemy->life = 5;
	enemy->life_max = 5;
	enemy->pos.x = 1224.0f;
	enemy->pos.y = pos_y;
	enemy->dir.x = -0.75f;
	enemy->dir.y = (pos_y < 320) ? 0.25f : -0.25f;
	enemy->speed = 360.0f;
	enemy->img_index = 2;
	enemy->animator = 0;
	enemy->collider = new_collider();
	enemy->collider->size.x = 80;
	enemy->collider->size.y = 100;
	enemy->collider->damage = 1;
	enemy->ai_handler = new_enemy_ai();
	vector2 w_pos;
	w_pos.x = -30.0f;
	w_pos.y = -50.0f;
	enemy->weapon = new_base_weapon(w_pos);
	w_pos.y = 50.0f;
	enemy->weapon->next = new_base_weapon(w_pos);
	enemy->on_death = &explode_enemy_ship;
	add_back_go(enemy, &g_data.go_list);
}

void spawn_tact_enemy(float pos_y)
{
	go_t *enemy = new_go();
	enemy->owner = ENEMY;
	enemy->life = 5;
	enemy->life_max = 5;
	enemy->pos.x = 1224.0f;
	enemy->pos.y = pos_y;
	enemy->dir.x = -0.75f;
	enemy->dir.y = (pos_y < 320) ? 0.25f : -0.25f;
	enemy->speed = 360.0f;
	enemy->img_index = 13;
	enemy->animator = 0;
	enemy->collider = new_collider();
	enemy->collider->size.x = 62;
	enemy->collider->size.y = 100;
	enemy->collider->damage = 1;
	enemy->ai_handler = new_enemy_ai();
	vector2 w_pos;
	w_pos.x = -60.0f;
	w_pos.y = 0.0f;
	enemy->weapon = new_tact_weapon(w_pos);
	enemy->on_death = &explode_enemy_ship;
	add_back_go(enemy, &g_data.go_list);
}

void spawn_destroyer(float pos_y)
{
	go_t *enemy = new_go();
	enemy->owner = ENEMY;
	enemy->life = 15;
	enemy->life_max = 15;
	enemy->pos.x = 2000.0f;
	enemy->pos.y = pos_y;
	enemy->dir.x = -1.0f;
	enemy->dir.y = 0.0f;
	enemy->speed = 160.0f;
	enemy->img_index = 8;
	enemy->animator = 0;
	enemy->collider = new_collider();
	enemy->collider->size.x = 990;
	enemy->collider->size.y = 200;
	enemy->collider->damage = 100;
	enemy->ai_handler = 0;
	enemy->on_death = &explode_destroyer;
	add_front_go(enemy, &g_data.go_list);
}

