/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:28:19 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 17:38:28 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:53:09 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 17:27:40 by jmorneau         ###   ########.fr       */
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

static void	hold_first(t_node **head_a, t_node **head_b,
						int *sorted_array, int t)
{
	int			i;
	int			max_number;
	static int	n = 1;

	i = 0;
	max_number = sorted_array[((((t / 11) * n) + t % 11)) - 1];
	if (n == 1)
		i -= t % 11;
	while (*head_a != NULL && i < (t / 11))
	{
		if ((*head_a)->value <= max_number)
		{
			pb(head_a, head_b);
			i++;
		}
		else
			big_number_on_top(head_a, max_number);
	}
	n++;
}

static void	hold_seconde(t_node **head_a, t_node **head_b, int t)
{
	int	i;

	i = 0;
	while (*head_b != NULL && i < (t / 11))
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

void	sortarray500(t_node **head_a, t_node **head_b)
{
	int	sizeofhead_a;
	int	*sorted_array;

	sizeofhead_a = sizeofchainedlist(*head_a);
	sorted_array = calcluechunck(head_a, sizeofhead_a);
	while (*head_a != NULL)
		hold_first(head_a, head_b, sorted_array, sizeofhead_a);
	while (*head_b != NULL)
		hold_seconde(head_a, head_b, sizeofhead_a);
	free (sorted_array);
}
