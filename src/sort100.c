/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:53:09 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 16:00:34 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	big_number_on_top(t_node **head_a, int max_number)
{
	if (find_next(head_a, max_number) < sizeofchainedlist(*head_a) / 2)
	{
		while ((*head_a)->value > max_number)
			ra(head_a);
	}
	else
	{
		while ((*head_a)->value > max_number)
			rra(head_a);
	}
}

static t_node	*hold_first(t_node **head_a, int t, int s, int *sorted_array)
{
	int			i;
	int			max_number;
	static int	n = 1;
	t_node		*head_b;

	i = 0;
	head_b = NULL;
	max_number = sorted_array[((((t / s) * n) + t % s)) - 1];
	if (n == 1)
		i -= t % s;
	while (*head_a != NULL && i < (t / s))
	{
		if ((*head_a)->value <= max_number)
		{
			pb(head_a, &head_b);
			i++;
		}
		else
			big_number_on_top(head_a, max_number);
	}
	n++;
	return (head_b);
}

static void	hold_seconde(t_node **head_a, t_node **head_b, int t, int s)
{
	int	i;

	i = 0;
	while (*head_b != NULL && i < (t / s))
	{
		if ((*head_b)->value == biggestnumber(*head_b))
		{
			pa(head_a, head_b);
			i++;
		}
		else
		{
			if (find_next_number(head_b) < sizeofchainedlist(*head_b) / 2)
			{
				while ((*head_b)->value != biggestnumber(*head_b))
					rb(head_b);
			}
			else
			{
				while ((*head_b)->value != biggestnumber(*head_b))
					rrb(head_b);
			}
		}
	}
}

void	sortarray100(t_node **head_a, t_node **head_b, int sizeofchunck)
{
	int	sizeofhead_a;
	int	*sorted_array;

	sorted_array = calcluechunck(head_a, sizeofchainedlist(*head_a));
	sizeofhead_a = sizeofchainedlist(*head_a);
	while (*head_a != NULL)
		*head_b = hold_first(head_a, sizeofhead_a, sizeofchunck, sorted_array);
	while (*head_b != NULL)
		hold_seconde(head_a, head_b, sizeofhead_a, sizeofchunck);
	free (sorted_array);
}
