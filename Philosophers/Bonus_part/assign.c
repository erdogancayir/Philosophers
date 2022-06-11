/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:00:58 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/11 16:00:58 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	*hospital(void *data)
{
	t_phis	*philo;
	t_state	*all;

	philo = (t_phis *)data;
	all = philo->link;
	while (true)
	{
		if (philo->eat_count == all->must_eat)
			break ;
		if (gettime() - philo->last_eat > all->time_die)
		{
			print(philo->id, "\033[0;91mPhilosop died", all);
			all->is_died = true;
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	birth(t_phis *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	philo->last_eat = gettime();
	pthread_create(&philo->link->yep, NULL, hospital, philo);
	while (philo->link->is_died == false)
	{
		meal_time(philo);
		if (philo->eat_count == philo->link->must_eat)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	exit(1);
}

void	process(t_state *all)
{
	int	idx;

	idx = -1;
	while (++idx < all->number_of)
	{
		all->philo[idx].pid = fork();
		if (all->philo[idx].pid < 0)
			ft_exit("Error! Fork");
		if (all->philo[idx].pid == 0)
			birth(&all->philo[idx]);
		usleep(100);
	}
	pthread_create(&all->check, NULL, waitp, all);
	pthread_join(all->check, NULL);
}
