/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:55:41 by narakely          #+#    #+#             */
/*   Updated: 2022/04/03 16:03:24 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo(t_philo_data *philo, char *str)
{
	unsigned int	time_now;

	pthread_mutex_lock(&philo->data->print);
	time_now = get_time();
	printf("%u\t%d\t%s\n", time_now - philo->data->creation_date,
		philo->n + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	free_data(t_main_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].eating);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eat);
	pthread_mutex_destroy(&data->main);
	free(data->philos);
	free(data->forks);
}
