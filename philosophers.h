/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <narakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:38:38 by narakely          #+#    #+#             */
/*   Updated: 2022/04/03 16:37:19 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define WRONG_ARGUMENTS 1
# define MALLOC_ERROR 2
# define PTHREAD_CREATE_ERROR 3
# define PTHREAD_JOIN_ERROR 4

typedef struct s_philo
{
	int				n;
	int				n1;
	int				num_of_eat;
	unsigned int	death_time;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	eating;
}					t_philo_data;

typedef struct s_data
{
	int				num_of_philos;
	unsigned int	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	int				finish;
	int				eat_finish;
	unsigned int	creation_date;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	main;
	t_philo_data	*philos;
}					t_main_data;

int					ft_is_digit(int c);
int					ft_atoi(const char *str);
unsigned int		get_time(void);
void				*ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				print_philo(t_philo_data *philo, char *str);
void				free_data(t_main_data *data);

int					validation_of_args(int argc, char **argv);
int					check_numeric(int argc, char **argv);
int					count_of_arguments(int argc);
int					check_arguments(int argc, char **argv);

void				malloc_error(t_main_data *data);
int					end_of_program(int error, t_main_data *data);

int					init_data(int argc, char **argv, t_main_data *data);
void				philo_init(t_main_data *data);
void				philo_create(t_main_data *data);

void				*check_eating_data(void *philo);
void				*check_death_data(void *philo);

void				take_forks(t_philo_data *philo);
void				eat(t_philo_data *philo);
void				philo_sleep(t_philo_data *philo);
void				think(t_philo_data *philo);
void				*simulate(void *arg);
void				free_data(t_main_data *data);

#endif