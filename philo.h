/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:58:38 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/06/29 20:36:01 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo_info	t_philo_info;

typedef struct s_philo{
	int				thread_num;
	pthread_t		id;
	t_philo_info	*info;
}	t_philo;
/*철학자 하나하나 */

typedef struct s_philo_info{
	int				philo_args[5]; //argv 인자값저장
	long long		time_start;//get_time으로 받아올 시각
	t_philo			*philo_arr;//철학자 정보저장
	pthread_mutex_t	print;//철학자 "잘돌아가고 있는지" 출력
	pthread_mutex_t *eats;//철학자 잘먹고있는지 출력
	pthread_mutex_t *fork_arr;//철학자 포크가 잘있는지
	int				philo_dead;//철학자 죽었는지
	int				is_must_eat_on;
	int				full_philo_cnt;
	int				done_eat;//밥안먹은 철학자 있는지
}	t_philo_info;
/*철학자들 총괄*/


int	init_philo(t_philo_info *info);
#endif