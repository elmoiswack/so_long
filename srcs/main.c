#include "../so_long.h"

int32_t	main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc != 2)
		return (0);
	i = map_check(argv);
	if (i == 1)
		ft_printf("yay");
	if (i == -1)
		ft_printf("nay");
	return (0);

}