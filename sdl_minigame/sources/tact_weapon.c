#include <game.h>

static void tact_ai_tick(void *data)
{
	go_t *go = (go_t *)data;
	ai_handler_t *aih = go->ai_handler;
	if (g_data.last_time - aih->last_move_order > aih->move_order_interval)
	{
			go->life = 0;
	}
}

static ai_handler_t *new_tact_ai()
{
	ai_handler_t *handler = new_ai_handler();
	handler->last_move_order = g_data.last_time;
	handler->move_order_interval = .85f * CLOCKS_PER_SEC;
	handler->ai_tick = &tact_ai_tick;
	return handler;
}

static void spawn_sub_missile(vector2 pos, vector2 dir, enum e_owner owner)
{
	go_t *projectile = new_go();
	projectile->owner = owner;
	projectile->life = 1;
	projectile->life_max = 1;
	projectile->pos = pos;
	projectile->dir = dir;
	projectile->speed = 900.0f;
	projectile->img_index = 16;
	projectile->animator = 0;
	projectile->collider = new_collider();
	projectile->collider->size.x = 10;
	projectile->collider->size.y = 10;
	projectile->collider->damage = 1;
	projectile->ai_handler = 0;
	if (owner == PLAYER)
		projectile->on_death = &explode_and_score;
	else
		projectile->on_death = &spawn_explosion;
	add_back_go(projectile, &g_data.go_list);
}

static void explode_enemy_tact_missile(vector2 pos)
{
	spawn_explosion(pos);
	vector2 m_dir;
	m_dir.x = 0.0f;
	m_dir.y = 1.0f;
	spawn_sub_missile(pos, m_dir, ENEMY);
	m_dir.y = -1.0f;
	spawn_sub_missile(pos, m_dir, ENEMY);
}

static void spawn_tact_projectile(vector2 pos, vector2 dir, enum e_owner owner)
{
	go_t *projectile = new_go();
	projectile->owner = owner;
	projectile->life = 1;
	projectile->life_max = 1;
	projectile->pos = pos;
	projectile->dir = dir;
	projectile->speed = 500.0f;
	projectile->img_index = owner == (ENEMY) ? 14 : 15;
	projectile->animator = 0;
	projectile->collider = new_collider();
	projectile->collider->size.x = 12;
	projectile->collider->size.y = 10;
	projectile->collider->damage = 1;
	projectile->ai_handler = new_tact_ai();
	projectile->on_death = &explode_enemy_tact_missile;
	add_back_go(projectile, &g_data.go_list);
}

static void tact_weapon_fire(weapon_t *this, go_t *go)
{
	if (this->ammunitions > 0
		&& g_data.last_time - this->last_shot > this->fire_interval)
	{
		this->ammunitions--;
		this->last_shot = g_data.last_time;
		vector2 pr_pos;
		pr_pos.x = go->pos.x + this->pos.x;
		pr_pos.y = go->pos.y + this->pos.y;
		vector2 pr_dir;
		pr_dir.x = go->owner == (PLAYER) ? 1.0f : -1.0f;
		pr_dir.y = 0.0f;
		spawn_tact_projectile(pr_pos, pr_dir, go->owner);
	}
	if (this->ammunitions <= 0 && g_data.last_time - this->last_shot > this->reload_time)
	{
		this->ammunitions = this->max_rounds;
	}
}

weapon_t *new_tact_weapon(vector2 pos)
{
	weapon_t *w = new_weapon();
	w->last_shot = g_data.last_time;
	w->ammunitions = w->max_rounds = 2;
	w->reload_time = 2.0f * CLOCKS_PER_SEC;
	w->fire_interval = 0.2f * CLOCKS_PER_SEC;
	w->fire = &tact_weapon_fire;
	w->pos = pos;
	return w;
}
