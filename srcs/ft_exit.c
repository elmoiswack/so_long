#include "../so_long.h"

void	ft_exit(char *str)
{
	ft_printf("Error in %s\n", str);
	exit(-1);
}