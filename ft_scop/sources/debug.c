#include "libft.h"
#include "math_tools.h"

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

void debug_vector3(const float v[3])
{
	ft_putd(v[0]);
	ft_putstr(", ");
	ft_putd(v[1]);
	ft_putstr(", ");
	ft_putd(v[2]);
	ft_putstr("\n\n");
}
