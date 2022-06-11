/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:55:09 by ecayir            #+#    #+#             */
/*   Updated: 2022/06/05 10:58:06 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phi.h"

void	ft_exit(char *s)
{
	printf("%s", s);
	exit(EXIT_FAILURE);
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
