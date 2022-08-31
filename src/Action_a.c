/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:17:42 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/29 14:49:00 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_node **head_a)
{
	t_node	*tmp;

	tmp = (*head_a);
	(*head_a) = tmp->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	ft_printf("sa\n");
}

void	ra(t_node **head)
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
	ft_printf("ra\n");
}

void	rra(t_node **head)
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
	ft_printf ("rra\n");
}

void	pb(t_node **head1, t_node **head2)
{
	t_node	*tmp;

	tmp = *head1;
	*head1 = (*head1)->next;
	tmp->next = *head2;
	*head2 = tmp;
	ft_printf("pb\n");
}
