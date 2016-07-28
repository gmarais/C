#include "libft.h"
#include "math_tools.h"

const double PI = 3.14159265358979323846;
const mat4_t IDENTITY_MATRIX = {{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
}};

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