#include "libft.h"

int	main(int ac, char **av)
{
	t_vector *vct;
	t_vector *split;

	if (ac != 4)
		return (1);
	vct = vct_newstr(av[1]);
	while ((split = vct_split(vct, av[2], ft_atoi(av[3]))))
	{
		vct_printendl(split);
		vct_del(&split);
	}
	vct_del(&vct);
	return (0);
}
