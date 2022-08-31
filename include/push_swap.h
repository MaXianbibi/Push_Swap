/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:33:00 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/31 15:37:39 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

struct s_node
{
	int				value;
	struct s_node	*next;
};
typedef struct s_node	t_node;

// UTILES

t_node	*creat_new_node(int value);
void	insert_at_head(t_node **head, t_node *node_to_insert);
int		error_arguments(int argc, char **argv);
bool	checkifsorted(t_node **head);
int		sizeofchainedlist(t_node *headA);
int		smallestnumber(t_node *headA);
int		biggestnumber(t_node *headA);
int		find_next(t_node **headA, int i);
int		find_next_number(t_node **headA);
int		*t_node2int(t_node *head, int lenght);
int		*calcluechunck(t_node **head_a, int sizeofhead_a);

// SORTS

t_node	*sortarray(int argc, char **argv);
void	sortarray100(t_node **headA, t_node **headB, int sizeofchunck);

// ACTIONS

void	sa(t_node **headA);
void	ra(t_node **head);
void	rra(t_node **head);
void	pb(t_node **head1, t_node **head2);

void	sb(t_node **headA);
void	rb(t_node **head);
void	rrb(t_node **head);
void	pa(t_node **head1, t_node **head2);

#endif