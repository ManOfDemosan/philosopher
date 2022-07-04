/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:26:52 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 15:57:48 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_philo_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	if (info->forks == NULL)
		return (print_err("Error: Forks Malloc Failure\n"));
	while (i < info->num_of_philos)
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		i++;
	}
	return (0);
}

int	init_eat_check(t_philo_info *info)
{
	int	i;

	i = 0;
	info->deadcheck = malloc(sizeof(pthread_mutex_t) * info->num_of_philos);
	if (info->deadcheck == NULL)
		return (print_err("Error: Deadcheck Malloc Failure\n"));
	while (i < info->num_of_philos)
	{
		pthread_mutex_init(&(info->deadcheck[i]), NULL);
		i++;
	}
	return (0);
}

int	make_philo(t_philo_info *info)
{
	int	i;

	i = 0;
	info->philo_args = malloc(sizeof(t_philo) * info->num_of_philos);
	if (info->philo_args == NULL)
		return (print_err("Error: Philo Array Malloc Failure\n"));
	while (i < info->num_of_philos)
	{
		pthread_create(&(info->philo_args[i].thread), \
		NULL, philo_func(info), &(info->philo_args[i]));
		info->philo_args[i].number = i + 1;
		info->philo_args[i].fed_time = get_time();
		info->philo_args[i].eat_cnt = 0;
		info->philo_args[i].print = &(info->print);
		info->philo_args[i].deadcheck = &(info->deadcheck[i]);
		info->philo_args[i].left_fork = &(info->forks[i]);
		info->philo_args[i].right_fork = &(info->forks \
		[((i + 1) % info->num_of_philos)]);
		info->philo_args[i].info = info;
		i++;
	}
}

int	init_philo(t_philo_info *info)
{
	pthread_mutex_init(&(info->print), NULL);
	if (init_fork(info))
		return (1);
	if (init_eat_check(info))
		return (1);
	if (make_philo(info))
		return (1);
	return (0);
}
