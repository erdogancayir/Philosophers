/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:30:35 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/08 16:50:44 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	meal_time(t_phi *philo)
{
	pthread_mutex_lock(&philo->link->fork_mutex[philo->r_fork_id]);
	print(philo->id, "\033[0;91mtook the right fork", philo->link);
	pthread_mutex_lock(&philo->link->fork_mutex[philo->l_fork_id]);
	print(philo->id, "\033[0;95mtook the left fork", philo->link);
	print(philo->id, "\033[0;92mEating", philo->link);
	philo->last_eat = gettime();
	pass_the_time(philo->link->time_to_eat, philo->link);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->r_fork_id]);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->l_fork_id]);
	philo->count_eat++;
}

void	*start(void *data)
{
	t_phi	*philo;

	philo = (t_phi *)data;
	if (philo->id % 2)
		usleep(1000);
	while (philo->link->died == false)
	{
		if (philo->link->died == true)
			break ;
		meal_time(philo);
		if (philo->link->must_eat <= philo->count_eat
			&& philo->link->must_eat != -1)
		{
			philo->link->eat_all = true;
			break ;
		}
		if (philo->link->died == true)
			break ;
		print(philo->id, "\033[0;94mSleeping", philo->link);
		pass_the_time(philo->link->time_to_sleep, philo->link);
		if (philo->link->died == true)
			break ;
		print(philo->id, "\033[0;93mThinking", philo->link);
	}
	return (NULL);
}

void	create_thread(t_state *aristo, int i, int j)
{
	while (++i < aristo->number_of)
	{
		pthread_create(&aristo->phi[i].th_id, NULL, start, &aristo->phi[i]);
	}
	die(aristo, 0, -1);
	while (++j < aristo->number_of)
		pthread_join(aristo->phi[j].th_id, NULL);
	j = -1;
	while (++j < aristo->number_of)
		pthread_mutex_destroy(&aristo->fork_mutex[j]);
	pthread_mutex_destroy(&aristo->random);
}
