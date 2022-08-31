/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:32:13 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 17:33:52 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	freehead(t_node **head)
{
	t_node	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

static int	new_argc(char **list_of_number)
{
	int	i;

	i = 0;
	while (list_of_number[i] != NULL)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	char	**list_of_number;
	char	*tmp;

	head = NULL;
	if (argc == 1)
		return (0);
	list_of_number = argv;
	if (argc == 2)
	{
		tmp = ft_strjoin("bullshit ", argv[1]);
		list_of_number = ft_split(tmp, ' ');
		free(tmp);
	}
	if (!error_arguments(new_argc(list_of_number), list_of_number))
		head = sortarray(new_argc(list_of_number), list_of_number);
	freehead(&head);
	if (argc == 2)
		ft_free_chartable(list_of_number);
	return (0);
}
