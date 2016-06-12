#ifndef _GAME_
#define _GAME_

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector2.h>

enum e_owner
{
	NONE = 0,
	PLAYER = 1,
	ENEMY = 2,
	PICKUP = 4,
	PLAYER_PICKUP = 5,
	PLAYER_ENEMY = 3,
	ALL = 7
};

enum e_wtype
{
	NO_WEAPON = 0,
	LIGHT_WEAPON = 1,
	MEDIUM_WEAPON = 2,
	HEAVY_WEAPON = 4,
	ALL_WEAPON = 7
};

typedef struct collider
{
	vector2 size;
	int damage;
} collider_t;

typedef struct animator
{
	int loop;
	float last_time;
	float interval;
	int var_index;
	int var_tab_size;
	int *var_tab;
} animator_t;

typedef struct ai_handler
{
	float last_move_order;
	float move_order_interval;

	void (*ai_tick)(void *go);
} ai_handler_t;

typedef struct go
{
	enum e_owner owner;
	int life;
	int life_max;
	float spawn_time;
	vector2 pos;
	vector2 dir;
	float speed;
	int img_index;
	struct collider *collider;
	struct animator *animator;
	struct weapon *weapon;
	struct ai_handler *ai_handler;
	void (*on_death)(vector2 pos);
} go_t;

typedef struct weapon
{
	enum e_wtype wtype;
	vector2 pos;
	float last_shot;
	float fire_interval;
	float reload_time;
	int max_rounds;
	int ammunitions;

	void (*fire)(struct weapon *this, go_t *go);

	struct weapon *next;
} weapon_t;

typedef struct lst
{
	go_t *go;
	struct lst *next;
} lst_t;

struct game_data
{
	lst_t *go_list;
	float last_time;
	float delta_time;
	float fps;
	short int game_ended;
	int score;
	go_t *player;
	go_t **lives;
	int lives_number;
	short int is_dead;
	short int is_playing;
	float last_shot;
	float death_time;
	float destroyer_time;
};
extern struct game_data g_data;

// game.c
int init_game();
void clean_quit_game();
void update_fps();
void move_objects();
// go.c
go_t *new_go();
animator_t *new_animator();
collider_t *new_collider();
ai_handler_t *new_ai_handler();
weapon_t *new_weapon();
void add_back_go(go_t *go, lst_t **list);
void add_front_go(go_t *go, lst_t **list);
void remove_go(lst_t **elem);
// spawn_ships.c
void spawn_player();
void spawn_enemy(float pos_y);
void spawn_tact_enemy(float pos_y);
void spawn_destroyer(float pos_y);
// ai.c
ai_handler_t *new_enemy_ai();
// collisions.c
void apply_collisions(lst_t *elem);
// explosions.c
void spawn_explosion(vector2 pos);
void explode_enemy_ship(vector2 pos);
void explode_destroyer(vector2 pos);
void explode_ship(vector2 pos);
// key_hooks.c
int key_hooks();
// hook_functions.c
void shoot();
void move_forward();
void move_backward();
void move_up();
void move_down();
// ui.c
void draw_lives_indicators();
char *get_score_string();
// tick_objects.c
void tick_objects();
// life_pickup.c
void spawn_life_pickup(vector2 pos);

#endif
