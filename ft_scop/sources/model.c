#include "model.h"
#include "shader.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_model *new_model(char *obj_filename)
{
	t_model *model;
	model = (t_model *)ft_memalloc(sizeof(t_model));
	model->obj_filename = obj_filename;
	return model;
}

void delete_model(t_model *model)
{
	ft_lstdel(&model->vertices, 0);
	free(model->positions);
	free(model->colors);
	free(model->uvs);
	free(model);
}

static void set_model_positions_colors(t_model *model)
{
	t_list *iterator;
	t_vertex *vertex;
	int i;
	int j;

	model->positions = (float *)malloc(sizeof(float [model->v_size * 3]));
	model->colors = (float *)malloc(sizeof(float [model->v_size * 4]));
	iterator = model->vertices;
	i = 0;
	j = 0;
	while (iterator != 0)
	{
		vertex = (t_vertex *)iterator->content;
		model->positions[i++] = vertex->position[e_xyz_x];
		model->positions[i++] = vertex->position[e_xyz_y];
		model->positions[i++] = vertex->position[e_xyz_z];
		model->colors[j++] = vertex->color[e_rgba_r];
		model->colors[j++] = vertex->color[e_rgba_g];
		model->colors[j++] = vertex->color[e_rgba_b];
		model->colors[j++] = vertex->color[e_rgba_a];
		iterator = iterator->next;
	}
}

static void set_model_uvs(t_model *model)
{
	t_list *iterator;
	t_vertex *vertex;
	int i;

	model->uvs = (float *)malloc(sizeof(float [model->v_size * 2]));
	iterator = model->vertices;
	i = 0;
	while (iterator != 0)
	{
		vertex = (t_vertex *)iterator->content;
		model->uvs[i++] = vertex->tex_coord[e_uv_u];
		model->uvs[i++] = vertex->tex_coord[e_uv_v];
		iterator = iterator->next;
	}
}

int load_model(t_model *model)
{
	int	fd;
	t_obj obj;
	t_list *iterator;

	if ((fd = open(model->obj_filename, O_RDONLY)) <= 0)
	{
		close(fd);
		ft_putendl_fd("Error opening obj file.", 2);
		return - 1;
	}
	load_obj(&obj, fd);
	close(fd);
	center_and_scale_obj(&obj);
	iterator = obj.f;
	while (iterator != 0)
	{
		add_face_to_model(obj, OBJ_F(iterator), model);
		iterator = iterator->next;
	}
	delete_obj(&obj);
	set_model_positions_colors(model);
	set_model_uvs(model);
	return 0;
}
