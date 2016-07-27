#include "libft.h"
#include "math_tools.h"

const double PI = 3.14159265358979323846;
const mat4_t IDENTITY_MATRIX = {{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
}};

void	debug_matrix(mat4_t m)
{
	int i;
	i = 0;
	while (i < 16)
	{
		if (i % 4 == 3)
		{
			ft_putd(m.val[i]);
			ft_putstr(",\n");
		}
		else
		{
			ft_putd(m.val[i]);
			ft_putstr(",\t");
		}
		i++;
	}
}

float	cotangent(float angle)
{
	return (float)(1.0 / tan(angle));
}

float	degrees_to_radians(float degrees)
{
	return degrees * (float)(PI / 180.0);
}

float radians_to_degrees(float radians)
{
	return radians * (float)(180.0 / PI);
}

mat4_t multiply_matrices(const mat4_t* m1, const mat4_t* m2)
{
	mat4_t out;
	unsigned int row;
	unsigned int column;
	unsigned int row_offset;

	out = IDENTITY_MATRIX;
	row = 0;
	row_offset = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			out.val[row_offset + column]
				= (m1->val[row_offset + 0] * m2->val[column + 0])
				+ (m1->val[row_offset + 1] * m2->val[column + 4])
				+ (m1->val[row_offset + 2] * m2->val[column + 8])
				+ (m1->val[row_offset + 3] * m2->val[column + 12]);
			column++;
		}
		row++;
		row_offset = row * 4;
	}
	return out;
}

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
	rotation.val[8] = sine;
	rotation.val[2] = -sine;
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

void cross_product(float (*result)[3], const float a[3], const float b[3])
{
	(*result)[0] = a[1] * b[2] - a[2] * b[1];
	(*result)[1] = a[2] * b[0] - a[0] * b[2];
	(*result)[2] = a[0] * b[1] - a[1] * b[0];
}

float dot_product(const float a[3], const float b[3])
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void normalize(float (*v)[3])
{
	float sum = ft_absf((*v)[0]) + ft_absf((*v)[1]) + ft_absf((*v)[2]);
	(*v)[0] = (*v)[0] / sum;
	(*v)[1] = (*v)[1] / sum;
	(*v)[2] = (*v)[2] / sum;
}

void copy_vector(float (*copy)[3], const float v[3])
{
	(*copy)[0] = v[0];
	(*copy)[1] = v[1];
	(*copy)[2] = v[2];
}

void debug_vector3(const float v[3])
{
	ft_putd(v[0]);
	ft_putstr(", ");
	ft_putd(v[1]);
	ft_putstr(", ");
	ft_putd(v[2]);
	ft_putstr("\n\n");
}

static void look_at_result_line(mat4_t *r
	, int *i
	, const float eye[3]
	, float v[3])
{
		r->val[(*i)] = v[0];
		r->val[(*i) + 4] = v[1];
		r->val[(*i) + 8] = v[2];
		(*i)++;
}

mat4_t look_at(const float eye[3], const float center[3], const float up[3])
{
	mat4_t result;
	float z[3];
	float y[3];
	float x[3];
	int i;

	z[0] = eye[0] - center[0];
	z[1] = eye[1] - center[1];
	z[2] = eye[2] - center[2];
	normalize(&z);
	copy_vector(&y, up);
	cross_product(&x, y, z);
	normalize(&x);
	cross_product(&y, z, x);
	normalize(&y);
	i = 0;
	result = IDENTITY_MATRIX;
	look_at_result_line(&result, &i, eye, x);
	look_at_result_line(&result, &i, eye, y);
	look_at_result_line(&result, &i, eye, z);
	result.val[12] = -dot_product(x, eye);
	result.val[13] = -dot_product(y, eye);
	result.val[14] = -dot_product(z, eye);
	return result;
}

mat4_t create_proj_matrix(float fov, float ratio, float near, float far)
{
	mat4_t out;
	const float y_scale = cotangent(degrees_to_radians(fov / 2.0f));
	const float x_scale = y_scale / ratio;
	const float frustum_length = far - near;

	ft_bzero(out.val, sizeof(float[16]));
	out.val[0] = x_scale;
	out.val[5] = y_scale;
	out.val[10] = -(far + near) / frustum_length;
	out.val[11] = -1;
	out.val[14] = -((2.0 * near * far) / frustum_length);
	return out;
}
