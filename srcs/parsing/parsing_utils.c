/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:23:34 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/28 15:08:11 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_algo_flag(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (1);
	return (0);
}

int	is_extra_flag(char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (1);
	return (0);
}

int	validate_flags(int argc, char **argv)
{
	int	algo_count;
	int	i;

	algo_count = 0;
	i = 1;
	while (i < argc)
	{
		if (is_algo_flag(argv[i]))
			algo_count++;
		else if (!is_extra_flag(argv[i]))
			break ;
		if (algo_count > 1)
			return (write(2, "Error\n", 6), 1);
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
