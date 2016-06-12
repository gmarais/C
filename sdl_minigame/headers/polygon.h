#ifndef _POLYGON_
#define _POLYGON_

#include <vector2.h>

typedef struct vertex_list
{
	vector2 vertex;
	struct vertex_list *next;
} vertex_list_t;

typedef struct polygon_s
{
	int size;
	struct vertex_list *vertices;
} poly_t;

#endif
