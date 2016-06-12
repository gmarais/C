#include <game.h>

static float get_min(float pos, float size)
{
	return pos - (size * 0.5f);
}

static int are_colliding(go_t *go_a, go_t *go_b)
{
	float min_x_a = get_min(go_a->pos.x, go_a->collider->size.x);
	float max_x_a = min_x_a + go_a->collider->size.x;
	float min_y_a = get_min(go_a->pos.y, go_a->collider->size.y);
	float max_y_a = min_y_a + go_a->collider->size.y;
	float min_x_b = get_min(go_b->pos.x, go_b->collider->size.x);
	float max_x_b = min_x_b + go_b->collider->size.x;
	float min_y_b = get_min(go_b->pos.y, go_b->collider->size.y);
	float max_y_b = min_y_b + go_b->collider->size.y;
	if ((min_x_a > min_x_b && min_x_a < max_x_b || max_x_a > min_x_b && max_x_a < max_x_b
	 	|| min_x_b > min_x_a && min_x_b < max_x_a || max_x_b > min_x_a && max_x_b < max_x_a)
	 && (min_y_a > min_y_b && min_y_a < max_y_b || max_y_a > min_y_b && max_y_a < max_y_b
	 	|| min_y_b > min_y_a && min_y_b < max_y_a || max_y_b > min_y_a && max_y_b < max_y_a)
	)
	{
		return 1;
	}
	return 0;
}

void apply_collisions(lst_t *elem)
{
	if (!g_data.is_playing)
		return;
	lst_t *curr = elem->next;

	while (curr)
	{ 
		if (curr->go 
			&& curr->go->collider != 0
			&& are_colliding(elem->go, curr->go)
			&& ((elem->go->owner | curr->go->owner) == PLAYER_ENEMY 
				|| (elem->go->owner | curr->go->owner) == PLAYER_PICKUP
					&& (curr->go == g_data.player || elem->go == g_data.player))
			&& elem->go->pos.x < 1024 + elem->go->collider->size.x / 2
			&& curr->go->pos.x < 1024 + curr->go->collider->size.x / 2
			&& elem->go->life > 0
			&& curr->go->life > 0)
		{
			elem->go->life -= curr->go->collider->damage;
			curr->go->life -= elem->go->collider->damage; 
		}
		curr = curr->next;
	}
}

