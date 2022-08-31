/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:58:44 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 15:36:09 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	smallestnumber(t_node *head_a)
{
	t_node	*tmp;
	int		value;

	value = 2147483647;
	tmp = head_a;
	while (tmp != NULL)
	{
		if (tmp->value < value)
			value = tmp->value;
		tmp = tmp->next;
	}	
	return (value);
}

int	biggestnumber(t_node *head_a)
{
	t_node	*tmp;
	int		value;

	value = -2147483648;
	tmp = head_a;
	while (tmp != NULL)
	{
		if (tmp->value > value)
			value = tmp->value;
		tmp = tmp->next;
	}	
	return (value);
}

int	find_next(t_node **head_a, int i)
{
	int		j;
	t_node	*tmp;

	j = 0;
	tmp = *head_a;
	while (tmp->value > i)
	{
		tmp = tmp->next;
		j++;
	}
	return (j);
}

int	find_next_number(t_node **head_a)
{
	int		j;
	t_node	*tmp;

	j = 0;
	tmp = *head_a;
	while (tmp->value != biggestnumber(*head_a))
	{
		tmp = tmp->next;
		j++;
	}
	return (j);
}

int	*t_node2int(t_node *head, int lenght)
{
	int		*array;
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = head;
	array = malloc(sizeof(int) * lenght);
	if (!array)
		return (NULL);
	while (i < lenght)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
