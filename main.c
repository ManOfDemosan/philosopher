/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:05:55 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/29 21:13:44 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>


int	print_err(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

// int	main(int ac, char **av)
// {	
// 	t_philo_info	info;

// 	if (ac < 5 || ac > 6)
// 		return (print_err("Error: argument\n"));
// 	init_philo(&info);
// 	return (0);
// }

void	*t_putstr(void *arg)
{
	
	printf("hello\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t philo[5];

	for(int i = 0; i < 5; i++)
	{
		pthread_create(&(philo[i]), NULL, t_putstr, NULL);
		pthread_join(philo[i], NULL);
	}
}