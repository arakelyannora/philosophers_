/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:34:35 by narakely          #+#    #+#             */
/*   Updated: 2022/04/03 16:34:42 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	malloc_error(t_main_data	*data)
{
	if (data->philos)
		free(data->philos);
	write(2, "Error: Malloc Error\n", 20);
}

int	end_of_program(int error, t_main_data	*data)
{
	if (error == WRONG_ARGUMENTS)
		write(2, "Error: Wrong Arguments\n", 23);
	if (error == MALLOC_ERROR)
		malloc_error(data);
	return (1);
}
