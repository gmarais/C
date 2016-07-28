/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include "libft.h"
# include <GL/glew.h>
# define SIZE_XYZ 3
# define SIZE_RGBA 4
# define SIZE_UV 2
# define MAX_OBJ_SCALE 8.0f
# define BASE_OBJ "obj/42.obj"
# define BASE_IMG "img/ruler_grid.bmp"

enum				e_rfcg
{
	e_rfcg_greyscale,
	e_rfcg_colors
};
extern enum e_rfcg	rfc_mode;

enum				e_xyz
{
	e_xyz_x,
	e_xyz_y,
	e_xyz_z
};

enum				e_rgba
{
	e_rgba_r,
	e_rgba_g,
	e_rgba_b,
	e_rgba_a
};

enum				e_uv
{
	e_uv_u,
	e_uv_v
};

enum				e_vertex_component
{
	e_v,
	e_vn,
	e_vt
};

typedef struct		s_obj
{
	char			*mtllib;
	char			*usemtl;
	char			*s;
	t_list			*v;
	t_list			*color;
	t_list			*vn;
	t_list			*vt;
	t_list			*f;
}					t_obj;

# define OBJ_V(objv) ((float *)(objv->content))
# define OBJ_VN(objvn) ((float *)(objvn->content))
# define OBJ_VT(objvt) ((float *)(objvt->content))
# define OBJ_F(objf) ((int(*)[3])(objf->content))

typedef struct		s_vertex
{
	float			position[SIZE_XYZ];
	float			color[SIZE_RGBA];
	float			tex_coord[SIZE_UV];
}					t_vertex;

typedef struct		s_model
{
	char			*obj_filename;
	int				v_size;
	t_list			*vertices;
	float			*positions;
	float			*colors;
	float			*uvs;
	GLuint			vaoid;
	GLuint			positions_vboid;
	GLuint			colors_vboid;
	GLuint			uvs_vboid;
}					t_model;

t_model				*new_model(char *obj_filename);
int					load_model(t_model *model);
void				delete_model(t_model *model);
int					get_next_words(char ***words, int fd);
void				clean_words_tab(char **words, int words_len);
int					load_obj(t_obj *obj, int fd);
void				delete_obj(t_obj *obj);
void				add_face_to_model(t_obj obj
	, int obj_face[3][3]
	, t_model *model);
void				center_and_scale_obj(t_obj *obj);

#endif
