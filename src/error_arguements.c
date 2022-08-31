/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arguements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:59:46 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/29 17:39:25 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (2);
}

bool	ft_is_all_digit(char *digit)
{
	int	i;

	i = 0;
	if (digit[0] == '-')
		i++;
	while (digit[i] != '\0')
	{
		if (ft_isdigit(digit[i]) != 1)
			return (false);
		i++;
	}
	return (true);
}

bool	double_number(char **argv, int j)
{
	int	i;

	i = 1;
	while (i < j)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (true);
		i++;
	}
	return (false);
}

int	error_arguments(int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 0;
	if (argc < 2)
		return (1);
	while (i < argc - 1)
	{
		tmp = ft_itoa(ft_atoi(argv[i + 1]));
		if (!ft_is_all_digit(argv[i + 1]) || ft_strncmp(argv[i + 1], tmp,
				INT32_MAX) != 0 || double_number(argv, i + 1))
		{
			free(tmp);
			return (print_error());
		}
		free(tmp);
		i++;
	}
	return (0);
}
