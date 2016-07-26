#ifndef _MODEL_
#define _MODEL_

#include "libft.h"
#define SIZE_XYZ 3
#define SIZE_RGBA 4
#define SIZE_UV 2
#define MAX_OBJ_SCALE 8.0f
#define OBJ_PATH "obj/"
#define BASE_OBJ "42.obj"
#define IMG_PATH "img/"
#define BASE_IMG "ruler_grid.bmp"

enum e_xyz
{
	e_xyz_x,
	e_xyz_y,
	e_xyz_z
};

enum e_rgba
{
	e_rgba_r,
	e_rgba_g,
	e_rgba_b,
	e_rgba_a
};

enum e_uv
{
	e_uv_u,
	e_uv_v
};

enum e_vertex_component
{
	e_v,
	e_vn,
	e_vt
};

typedef struct obj
{
	char *mtllib;
	char *usemtl;
	char *s;
	t_list	*v;
	t_list	*color;
	t_list	*vn;
	t_list	*vt;
	t_list	*f;
} t_obj;

#define OBJ_V(objv) ((float *)(objv->content))
#define OBJ_VN(objvn) ((float *)(objvn->content))
#define OBJ_VT(objvt) ((float *)(objvt->content))
#define OBJ_F(objf) ((int(*)[3])(objf->content))

typedef struct vertex
{
	float position[SIZE_XYZ];
	float color[SIZE_RGBA];
	float tex_coord[SIZE_UV];
} t_vertex;

typedef struct model
{
	char *obj_filename;
	int v_size;
	t_list *vertices;
	float *positions;
	float *colors;
	float *uvs;
} t_model;

t_model *new_model(char *obj_filename);
void load_model(t_model *model);
void delete_model(t_model *model);
int get_next_words(char ***words, int fd);
void clean_words_tab(char **words, int words_len);
t_obj load_obj(int fd);
void add_face_to_model(t_obj obj, int obj_face[3][3], t_model *model);
void center_and_scale_obj(t_obj *obj);



#endif