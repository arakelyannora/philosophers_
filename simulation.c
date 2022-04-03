/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:38:40 by narakely          #+#    #+#             */
/*   Updated: 2022/03/29 19:38:40 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo_data *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->n]);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->n1]);
	print_philo(philo, "has taken a fork");
}

void	eat(t_philo_data	*philo)
{
	pthread_mutex_lock(&philo->eating);
	print_philo(philo, "is eating");
	philo->death_time = get_time() + philo->data->time_to_die;
	pthread_mutex_lock(&philo->data->eat);
	philo->num_of_eat++;
	if (philo->num_of_eat == philo->data->num_of_must_eat)
		philo->data->eat_finish++;
	pthread_mutex_unlock(&philo->data->eat);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->data->forks[philo->n]);
	pthread_mutex_unlock(&philo->data->forks[philo->n1]);
}

void	philo_sleep(t_philo_data	*philo)
{
	print_philo(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	think(t_philo_data	*philo)
{
	print_philo(philo, "thinking");
}

void	*simulate(void *arg)
{
	t_philo_data	*philo;
	pthread_t		dead_thread;
	pthread_t		eat_thread;

	philo = arg;
	pthread_create(&dead_thread, NULL, check_death_data, philo);
	pthread_detach(dead_thread);
	philo->death_time = get_time() + philo->data->time_to_die;
	if (philo->data->num_of_must_eat > 0)
	{
		pthread_create(&eat_thread, NULL, check_eating_data, philo);
		pthread_detach(eat_thread);
	}
	while (!philo->data->finish)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		philo_sleep(philo);
	}
	return (0);
}
