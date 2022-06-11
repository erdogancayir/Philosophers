/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:43:29 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/11 15:43:39 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	meal_time(t_phis *philo)
{
	t_state	*all;

	all = philo->link;
	sem_wait(all->forks);
	print(philo->id, "\033[0;91mtook the right fork", all);
	sem_wait(all->forks);
	print(philo->id, "\033[0;95mtook the left fork", all);
	print(philo->id, "\033[0;92mEating", all);
	pass_the_time(philo->link->time_eat, philo->link);
	philo->last_eat = gettime();
	philo->eat_count++;
	sem_post(all->forks);
	sem_post(all->forks);
}

void	philo_sleep(t_phis *philo)
{
	t_state	*all;

	all = philo->link;
	print(philo->id, "\033[0;94mSleeping", philo->link);
	pass_the_time(all->time_sleep, all);
}

void	philo_think(t_phis *philo)
{
	print(philo->id, "\033[0;93mThinking", philo->link);
}
