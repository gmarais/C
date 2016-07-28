#include "libft.h"
#include "math_tools.h"

void scale_matrix(mat4_t* m, float x, float y, float z)
{
	mat4_t scale;
	mat4_t mult_res;

	scale = IDENTITY_MATRIX;
	scale.val[0] = x;
	scale.val[5] = y;
	scale.val[10] = z;
	mult_res = multiply_matrices(&scale, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void translate_matrix(mat4_t* m, float x, float y, float z)
{
	mat4_t translation;
	mat4_t mult_res;

	translation = IDENTITY_MATRIX;
	translation.val[12] = x;
	translation.val[13] = y;
	translation.val[14] = z;
	mult_res = multiply_matrices(&translation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void rotate_x(mat4_t* m, float angle)
{
	mat4_t rotation;
	mat4_t mult_res;
	float sine;
	float cosine;

	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation = IDENTITY_MATRIX;
	rotation.val[5] = cosine;
	rotation.val[6] = -sine;
	rotation.val[9] = sine;
	rotation.val[10] = cosine;
	mult_res = multiply_matrices(&rotation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void rotate_y(mat4_t* m, float angle)
{
	mat4_t rotation;
	mat4_t mult_res;
	float sine;
	float cosine;

	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation = IDENTITY_MATRIX;
	rotation.val[0] = cosine;
	rotation.val[2] = -sine;
	rotation.val[8] = sine;
	rotation.val[10] = cosine;
	mult_res = multiply_matrices(&rotation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void rotate_z(mat4_t* m, float angle)
{
	mat4_t rotation;
	mat4_t mult_res;
	float sine;
	float cosine;

	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation = IDENTITY_MATRIX;
	rotation.val[0] = cosine;
	rotation.val[1] = -sine;
	rotation.val[4] = sine;
	rotation.val[5] = cosine;
	mult_res = multiply_matrices(&rotation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}
