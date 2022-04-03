/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:38:33 by narakely          #+#    #+#             */
/*   Updated: 2022/03/29 19:38:33 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_eating_data(void *philo)
{
	t_philo_data			*philo_tmp;

	philo_tmp = philo;
	while (philo_tmp->data->finish == 0)
	{
		if (philo_tmp->data->eat_finish >= philo_tmp->data->num_of_philos)
		{
			philo_tmp->data->finish = 1;
			pthread_mutex_lock(&philo_tmp->data->print);
			pthread_mutex_lock(&philo_tmp->data->eat);
			pthread_mutex_unlock(&philo_tmp->data->main);
		}
		usleep(300);
	}
	return (0);
}

void	*check_death_data(void *philo)
{
	t_philo_data	*philo_tmp;
	unsigned int	time_now;

	philo_tmp = philo;
	while (philo_tmp->data->finish == 0)
	{
		time_now = get_time();
		if (time_now > philo_tmp->death_time)
		{
			print_philo(philo_tmp, "died");
			pthread_mutex_lock(&philo_tmp->eating);
			pthread_mutex_lock(&philo_tmp->data->print);
			pthread_mutex_unlock(&philo_tmp->data->main);
		}
		usleep(300);
	}
	return (0);
}
