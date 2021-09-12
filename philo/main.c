/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <murachid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:16:21 by murachid          #+#    #+#             */
/*   Updated: 2021/09/10 14:37:39 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosphers.h"

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc < 5 || argc > 6 || ft_error(argc, argv) == 1)
	{
		printf("bad arguments\n");
		return (1);
	}
	if (init_data(&data, argc, argv))
	{
		printf("bad arguments\n");
		return (1);
	}
	return (alloc_and_init(data));
}
