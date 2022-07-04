/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:34:04 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 21:58:25 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	possible_to_atoi(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

int	init_arg(int ac, char **av, t_philo_info *info)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (possible_to_atoi(av[i]) == 0)
			return (print_err("Not Numeric args\n"));
		if (ft_atoi(av[i]) < 0)
			return (print_err("Not Positive Num\n"));
	}
	info->num_of_philos = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->finish_line = ft_atoi(av[5]);
	else
		info->finish_line = -1;
	info->time_of_start = get_time();
	info->philo_eat = 0;
	if (get_time() == 1)
		return (print_err("Get Time Failure\n"));
	return (0);
}
