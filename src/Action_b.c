/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:18:02 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 16:04:27 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(t_node **head_a)
{
	t_node	*tmp;

	tmp = (*head_a);
	(*head_a) = tmp->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	ft_printf("sb\n");
}

void	rb(t_node **head)
{
	t_node	*tmp;
	t_node	*first;

	tmp = *head;
	first = *head;
	*head = (*head)->next;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = first;
			first->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	ft_printf("rb\n");
}

void	rrb(t_node **head)
{
	t_node	*tmp;
	t_node	*last;

	tmp = *head;
	last = NULL;
	while (tmp != NULL)
	{
		if (tmp->next->next == NULL)
		{
			last = tmp;
			tmp = tmp->next;
			last->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	tmp->next = *head;
	*head = tmp;
	ft_printf ("rrb\n");
}

void	pa(t_node **head1, t_node **head2)
{
	t_node	*tmp;

	tmp = *head2;
	*head2 = (*head2)->next;
	tmp->next = *head1;
	*head1 = tmp;
	ft_printf("pa\n");
}
