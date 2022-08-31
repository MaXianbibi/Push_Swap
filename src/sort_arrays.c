/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:59:09 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 17:41:05 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sortarray3(t_node **head_a, t_node **head_b)
{
	(void)head_b;
	while (checkifsorted(head_a) == false)
	{
		if ((*head_a)->next->next != NULL
			&& (*head_a)->value > (*head_a)->next->value
			&& (*head_a)->value > (*head_a)->next->next->value)
			ra(head_a);
		else if ((*head_a)->value > (*head_a)->next->value)
			sa(head_a);
		else if ((*head_a)->value < (*head_a)->next->value)
			rra(head_a);
	}
}

void	sortarray5(t_node **head_a, t_node **head_b)
{
	int	chainedlist_l;
	int	chunck;
	int	*sorted_array;

	chainedlist_l = sizeofchainedlist(*head_a);
	sorted_array = calcluechunck(head_a, chainedlist_l);
	chunck = sorted_array[2];
	while (sizeofchainedlist(*head_a) > 3)
	{
		if ((*head_a)->value < chunck)
			pb(head_a, head_b);
		else
			ra (head_a);
	}
	sortarray3(head_a, head_b);
	if ((*head_b)->next != NULL && (*head_b)->value < (*head_b)->next->value)
		rb(head_b);
	while (*head_b != NULL)
		pa(head_a, head_b);
	free(sorted_array);
}

t_node	*sortarray(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		i;

	i = 0;
	head_a = NULL;
	head_b = NULL;
	while (i < argc - 1)
		insert_at_head(&head_a, creat_new_node(ft_atoi(argv[i++ + 1])));
	if (checkifsorted(&head_a))
		return (head_a);
	if (argc <= 4)
		sortarray3(&head_a, &head_b);
	else if (argc <= 6)
		sortarray5(&head_a, &head_b);
	else if (argc <= 101)
		sortarray100(&head_a, &head_b);
	else
		sortarray500(&head_a, &head_b);
	return (head_a);
}
