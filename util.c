/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:37:59 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/07/04 18:36:58 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_err(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	digit;
	int					button;

	digit = 0;
	button = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			button = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		digit *= 10;
		digit += (*str - '0');
		str++;
	}
	if (digit > 9223372036854775807 && button == 1)
		return (-1);
	else if (digit > 9223372036854775808ULL && button == -1)
		return (0);
	return ((int)digit * button);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	if (gettimeofday(&time, NULL) != 0)
		return (1);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	alt_sleep(long long time_to_sleep)
{
	long long	target_time;

	target_time = get_time() + time_to_sleep;
	while (target_time > get_time())
		usleep(100);
}
