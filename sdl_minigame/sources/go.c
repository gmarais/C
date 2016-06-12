#include <game.h>

go_t *new_go()
{
	go_t *go = (go_t *)malloc(sizeof(go_t));
	go->spawn_time = g_data.last_time;
	go->animator = 0;
	go->collider = 0;
	go->ai_handler = 0;
	go->weapon = 0;
	return go;
}

animator_t *new_animator()
{
	return (animator_t *)malloc(sizeof(animator_t));
}

collider_t *new_collider()
{
	return (collider_t *)malloc(sizeof(collider_t));
}

ai_handler_t *new_ai_handler()
{
	return (ai_handler_t *)malloc(sizeof(ai_handler_t));
}

weapon_t *new_weapon()
{
	weapon_t *w = (weapon_t *)malloc(sizeof(weapon_t));
	w->next = 0;
	return w;
}

void add_back_go(go_t *go, lst_t **list)
{
	lst_t *new = (lst_t *)malloc(sizeof(lst_t));
	new->go = go;
	new->next = 0;

	lst_t *end = *list;
	while (end != 0 && end->next != 0)
		end = end->next;

	if (end != 0)
		end->next = new;
	else
		*list = new;
}

void add_front_go(go_t *go, lst_t **list)
{
	lst_t *new = (lst_t *)malloc(sizeof(lst_t));
	new->go = go;
	new->next = *list;
	*list = new;
}

void remove_go(lst_t **elem)
{
	if ((*elem)->go != 0)
	{
		if (((*elem)->go->collider == 0 || (*elem)->go->life <= 0) && (*elem)->go->on_death != 0 && !g_data.game_ended)
		{
			(*elem)->go->on_death((*elem)->go->pos);
		}
		if ((*elem)->go->animator != 0)
		{
			free((*elem)->go->animator);
		}
		if ((*elem)->go->collider != 0)
		{
			free((*elem)->go->collider);
		}
		weapon_t *tmp;
		while ((*elem)->go->weapon != 0)
		{
			tmp = (*elem)->go->weapon;
			(*elem)->go->weapon = (*elem)->go->weapon->next;
			free(tmp);
		}
		free ((*elem)->go);
	}
	lst_t *next = (*elem)->next;
	free (*elem);
	*elem = next;
}
