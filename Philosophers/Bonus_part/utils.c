/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:40:34 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/11 15:40:34 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

uint64_t	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	print(int id, char *s, t_state *all)
{
	if (all->is_died == false)
	{
		sem_wait(all->print);
		printf("\033[0;97m%llu -> timestamp_in_ms ~ ",
			(gettime() - all->start_time));
		printf("\033[0;96m%d. philosop -> %s\n", id, s);
		sem_post(all->print);
	}
}

int	ft_atoi(char *s)
{
	int	res;
	int	sing;
	int	i;
	int	j;

	res = 0;
	sing = 1;
	i = 0;
	j = -1;
	while (s[++j])
		if (s[j] < '0' || s[j] > '9')
			ft_exit("Only + number..\n");
	while (s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	return (res * sing);
}
