/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:02:22 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 16:43:54 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*creat_new_node(int value)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	if (result == NULL)
		return (NULL);
	result->value = value;
	result->next = NULL;
	return (result);
}

void	insert_at_head(t_node **head, t_node *node_to_insert)
{
	t_node	*tmp;

	tmp = *head;
	if (!*head)
		*head = node_to_insert;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node_to_insert;
	}
}

bool	checkifsorted(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	*calcluechunck(t_node **head_a, int sizeofhead_a)
{
	int	i;
	int	tmp;
	int	*array;

	array = t_node2int(*head_a, sizeofhead_a);
	i = 0;
	while (i < sizeofhead_a - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (array);
}

int	sizeofchainedlist(t_node *head_a)
{
	t_node	*tmp;
	int		value;

	value = 0;
	tmp = head_a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		value++;
	}
	return (value);
}
