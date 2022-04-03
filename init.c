/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:34:23 by narakely          #+#    #+#             */
/*   Updated: 2022/04/03 16:34:25 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_init(t_main_data *data)
{
	int	i;

	i = -1;
	data->finish = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->main, NULL);
	pthread_mutex_lock(&data->main);
	data->creation_date = get_time();
	while (++i < data->num_of_philos)
	{
		data->philos[i].n = i;
		data->philos[i].n1 = (i + 1) % data->num_of_philos;
		data->philos[i].data = data;
		data->philos[i].death_time = get_time() + data->time_to_die;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].eating, NULL);
	}
}

void	philo_create(t_main_data	*data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_create(&data->philos[i].thread, NULL,
			&simulate, &data->philos[i]);
		usleep(100);
	}
	i = -1;
	while (++i < data->num_of_philos)
		pthread_detach(data->philos[i].thread);
}

int	init_data(int argc, char **argv, t_main_data	*data)
{	
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_must_eat = 0;
	data->philos = ft_calloc(data->num_of_philos, sizeof(t_philo_data));
	if (!data->philos)
		return (MALLOC_ERROR);
	data->forks = ft_calloc(data->num_of_philos, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (MALLOC_ERROR);
	philo_init(data);
	philo_create(data);
	return (0);
}
