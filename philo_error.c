/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 10:53:31 by murachid          #+#    #+#             */
/*   Updated: 2021/09/11 10:53:32 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (1);
}

int	ft_characters(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' && j == 0 && ft_isdigit(argv[i][j + 1]) == 0)
			{
				j++;
				continue ;
			}
			if (ft_isdigit(argv[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(int argc, char **argv)
{
	if (ft_characters(argc, argv) == 1)
		return (1);
	else
		return (0);
}
