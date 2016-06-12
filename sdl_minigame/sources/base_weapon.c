#include <game.h>

static void spawn_base_projectile(vector2 pos, vector2 dir, enum e_owner owner)
{
	go_t *projectile = new_go();
	projectile->owner = owner;
	projectile->life = 1;
	projectile->life_max = 1;
	projectile->pos = pos;
	projectile->dir = dir;
	projectile->speed = owner == (PLAYER) ? 1400.0f : 1000.0f;
	projectile->img_index = owner == (PLAYER) ? 1 : 3;
	projectile->animator = 0;
	projectile->collider = new_collider();
	projectile->collider->size.x = 16;
	projectile->collider->size.y = 12;
	projectile->collider->damage = 1;
	projectile->ai_handler = 0;
	projectile->on_death = &spawn_explosion;
	add_back_go(projectile, &g_data.go_list);
}

static void base_weapon_fire(weapon_t *this, go_t *go)
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
		spawn_base_projectile(pr_pos, pr_dir, go->owner);
	}
	if (this->ammunitions <= 0 && g_data.last_time - this->last_shot > this->reload_time)
	{
		this->ammunitions = this->max_rounds;
	}
}

weapon_t *new_base_weapon(vector2 pos)
{
	weapon_t *w = new_weapon();
	w->last_shot = g_data.last_time;
	w->ammunitions = w->max_rounds = 1;
	w->reload_time = 0.0f;
	w->fire_interval = 0.45f * CLOCKS_PER_SEC;
	w->fire = &base_weapon_fire;
	w->pos = pos;
	return w;
}
