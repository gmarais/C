/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_TOOLS_H
# define MATH_TOOLS_H

# include <math.h>

typedef struct		s_mat4
{
	float			val[16];
}					t_mat4;

extern const double	g_pi;
extern const t_mat4	g_identity_matrix;

void				debug_matrix(t_mat4 m);
void				debug_vector3(const float v[3]);
float				cotangent(float angle);
float				degrees_to_radians(float degrees);
float				radians_to_degrees(float radians);
t_mat4				multiply_matrices(const t_mat4 *m1, const t_mat4 *m2);
void				scale_matrix(t_mat4 *m, float x, float y, float z);
void				translate_matrix(t_mat4 *m, float x, float y, float z);
void				rotate_x(t_mat4 *m, float angle);
void				rotate_y(t_mat4 *m, float angle);
void				rotate_z(t_mat4 *m, float angle);
void				cross_product(float (*result)[3]
	, const float a[3]
	, const float b[3]);
float				dot_product(const float a[3], const float b[3]);
void				normalize(float (*v)[3]);
void				copy_vector(float (*copy)[3], const float v[3]);
t_mat4				look_at(const float eye[3]
	, const float center[3]
	, const float up[3]);
t_mat4				create_proj_matrix(float fov
	, float ratio
	, float near
	, float far);

#endif
