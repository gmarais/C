#ifndef _MATH_TOOLS_
#define _MATH_TOOLS_

#include <math.h>

typedef struct s_mat4
{
	float val[16];
} mat4_t;

extern const double PI;
extern const mat4_t IDENTITY_MATRIX;

void	debug_matrix(mat4_t m);
float	cotangent(float angle);
float	degrees_to_radians(float degrees);
float radians_to_degrees(float radians);
mat4_t multiply_matrices(const mat4_t* m1, const mat4_t* m2);
void scale_matrix(mat4_t* m, float x, float y, float z);
void translate_matrix(mat4_t* m, float x, float y, float z);
void rotate_x(mat4_t* m, float angle);
void rotate_y(mat4_t* m, float angle);
void rotate_z(mat4_t* m, float angle);
void cross_product(float (*result)[3], const float a[3], const float b[3]);
float dot_product(const float a[3], const float b[3]);
void normalize(float (*v)[3]);
mat4_t look_at(const float eye[3], const float center[3], const float up[3]);
mat4_t create_proj_matrix(float fov, float ratio, float near, float far);

#endif