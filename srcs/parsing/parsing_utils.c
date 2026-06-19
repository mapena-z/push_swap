#include "../../includes/parsing.h"
#include "../../libft/libft.h"

int	has_flag(int argc, char **argv, char *flag)
{
	int	len;
	int	i;

	len = ft_strlen(flag) + 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], flag, len) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	first_value_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && check_flags(argv[i]))
		i++;
	return (i);
}