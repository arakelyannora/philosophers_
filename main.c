/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:38:42 by narakely          #+#    #+#             */
/*   Updated: 2022/04/03 16:22:14 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_main_data	data;
	int			error;

	memset(&data, 0, sizeof(t_main_data));
	error = check_arguments(argc, argv);
	if (error)
		return (end_of_program(error, &data));
	error = init_data(argc, argv, &data);
	if (error)
		return (end_of_program(error, &data));
	pthread_mutex_lock(&data.main);
	free_data(&data);
	return (0);
}
