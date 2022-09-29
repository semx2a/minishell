#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;

	printf("%s\n", av[1] + 0);
	printf("%s\n", av[1] + 1);
	printf("%s\n", av[1] + 2);
	printf("%s\n", av[1] + 3);
	printf("%s\n", av[1] + 4);
	return (0);
}
