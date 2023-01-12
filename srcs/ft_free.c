#include "../so_long.h"

void	ft_free_2d_array(char **array, int y)
{
	if (y > 1)
	{
		while (y > 1)
		{
			free(array[y]);
			y--;
		}
	}
	free (array);
	return ;
}