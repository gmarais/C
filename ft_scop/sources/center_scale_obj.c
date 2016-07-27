#include "model.h"

static void initiate_min_max(float (*min)[3], float (*max)[3], float (*abs_min_max)[2], t_list *tmp)
{
	int		i;

	i = -1;
	(*abs_min_max)[0] = OBJ_V(tmp)[0];
	(*abs_min_max)[1] = OBJ_V(tmp)[0];
	while (++i < 3)
	{
		(*max)[i] = OBJ_V(tmp)[i];
		(*min)[i] = OBJ_V(tmp)[i];
		if (OBJ_V(tmp)[i] < (*abs_min_max)[0])
			(*abs_min_max)[0] = OBJ_V(tmp)[i];
		if (OBJ_V(tmp)[i] > (*abs_min_max)[1])
			(*abs_min_max)[1] = OBJ_V(tmp)[i];
	}
}

static void set_min_and_max(float (*min)[3], float (*max)[3], float (*abs_min_max)[2], t_obj *obj)
{
	int i;
	t_list *tmp;

	tmp = obj->v;
	if (tmp)
		initiate_min_max(min, max, abs_min_max, tmp);
	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			if (OBJ_V(tmp)[i] > (*max)[i])
				(*max)[i] = OBJ_V(tmp)[i];
			if (OBJ_V(tmp)[i] < (*min)[i])
				(*min)[i] = OBJ_V(tmp)[i];
			if (OBJ_V(tmp)[i] < (*abs_min_max)[0])
				(*abs_min_max)[0] = OBJ_V(tmp)[i];
			if (OBJ_V(tmp)[i] > (*abs_min_max)[1])
				(*abs_min_max)[1] = OBJ_V(tmp)[i];
		}
		tmp = tmp->next;
	}
}

static void center_obj(t_obj *obj, float min[3], float max[3])
{
	float offset[3];
	float abs_middle[3];
	t_list *tmp;
	int i;

	i = -1;
	while (++i < 3)
	{
		abs_middle[i] = (ft_absf(max[i]) + ft_absf(min[i])) * 0.5f;
		offset[i] = abs_middle[i] - max[i];
	}
	tmp = obj->v;
	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			OBJ_V(tmp)[i] += offset[i];
		}
		tmp = tmp->next;
	}
}

static void scale_obj(t_obj *obj, float (*abs_min_max)[2], float wanted_size)
{
	float correction;
	float total_size;
	t_list *tmp;
	int i;

	total_size = ft_absf((*abs_min_max)[0]) + ft_absf((*abs_min_max)[1]);
	correction = wanted_size / total_size;
	tmp = obj->v;
	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			OBJ_V(tmp)[i] *= correction;
		}
		tmp = tmp->next;
	}
}

void center_and_scale_obj(t_obj *obj)
{
	float min[3];
	float max[3];
	float abs_min_max[2];
	int i;
	t_list *tmp;

	set_min_and_max(&min, &max, &abs_min_max, obj);
	center_obj(obj, min, max);
	scale_obj(obj, &abs_min_max, MAX_OBJ_SCALE);
}
