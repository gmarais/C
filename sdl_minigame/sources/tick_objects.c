#include <game.h>

static void animate(go_t *go)
{
	if (go->animator->loop != 0 && g_data.last_time - go->animator->last_time > go->animator->interval)
	{
		go->animator->var_index = (go->animator->var_index >= go->animator->var_tab_size - 1) ? 0 : go->animator->var_index + 1;
		go->img_index = go->animator->var_tab[go->animator->var_index];

		go->animator->last_time = g_data.last_time;
		if (go->animator->loop > 0 && go->animator->var_index == 0)
			go->animator->loop--;
	}
}

static void move_object(go_t *go)
{
	go->pos.x += go->speed * g_data.delta_time * go->dir.x;
	go->pos.y += go->speed * g_data.delta_time * go->dir.y;
}

static int go_is_alive(go_t *go)
{
	if (go->pos.x > 2048 || go->pos.x < -1024 || go->pos.y < -640 || go->pos.y > 1280)
		return 0;
	if (go->collider != 0 && go->life <= 0)
		return 0;
	if (go->animator != 0 && go->animator->loop == 0)
		return 0;
	return 1;
}

static void tick_object(lst_t *curr)
{
	if (curr->go->speed != 0)
		move_object(curr->go);
	if (curr->go->ai_handler != 0 && curr->go->ai_handler->ai_tick != 0)
		curr->go->ai_handler->ai_tick(curr->go);
	if (curr->go->collider != 0)
		apply_collisions(curr);
	if (curr->go->animator != 0)
		animate(curr->go);
}

void tick_objects()
{
	lst_t *prev = 0;
	lst_t *curr = g_data.go_list;

	while (curr)
	{
		if (curr->go != 0)
		{
			tick_object(curr);
		}

		if (!curr->go || !go_is_alive(curr->go))
		{
			if (curr == g_data.go_list)
				g_data.go_list = curr->next;
			remove_go(&curr);
			if (prev != 0)
				prev->next = curr;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

