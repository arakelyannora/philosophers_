/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:38:48 by narakely          #+#    #+#             */
/*   Updated: 2022/04/03 15:56:54 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validation_of_args(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0)
		return (1);
	if (ft_atoi(argv[4]) <= 0 || ft_atoi(argv[3]) <= 0)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (1);
	return (0);
}

int	check_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == 0)
			return (WRONG_ARGUMENTS);
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_is_digit(argv[i][j]))
				return (WRONG_ARGUMENTS);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_of_arguments(int argc)
{
	if (argc != 5 && argc != 6)
		return (WRONG_ARGUMENTS);
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	if (count_of_arguments(argc))
		return (WRONG_ARGUMENTS);
	if (validation_of_args(argc, argv))
		return (WRONG_ARGUMENTS);
	if (check_numeric(argc, argv))
		return (WRONG_ARGUMENTS);
	return (0);
}
