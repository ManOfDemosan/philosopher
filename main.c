/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:05:55 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 20:19:56 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat(t_philo_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos && \
	info->philo_args[i].eat_cnt >= info->finish_line)
		i++;
	if (i == info->num_of_philos)
		info->philo_eat = 1;
	return (0);
}

int	check_dead(t_philo_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos && (info->philo_dead == 0))
	{
		pthread_mutex_lock(&(info->deadcheck[i]));
		if (get_time() - info->philo_args[i].fed_time \
		> info->time_to_die)
		{
			philo_print(&(info->philo_args[i]), DEAD);
			info->philo_dead = 1;
		}
		pthread_mutex_unlock(&(info->deadcheck[i]));
		i++;
	}
	return (0);
}

int	check_philo(t_philo_info *info)
{
	while (1)
	{
		check_dead(info);
		if (info->philo_dead == 1)
			break ;
		check_eat(info);
		if (info->philo_eat == 1)
		{
			pthread_mutex_lock(&(info->print));
			printf("All philosophers are done eating.\n");
			break ;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{	
	t_philo_info	info;

	if (ac < 5 || ac > 6)
		return (print_err("Error: argument\n"));
	if (init_arg(ac, av, &info) != 0)
		return (1);
	if (init_philo(&info) != 0)
		return (1);
	check_philo(&info);
	return (0);
}
