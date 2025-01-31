/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 16:34:22 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-26 16:34:22 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack_a, t_stack **stack_b, char set)
{
	if (set == DO_A)
	{
		node_swap(stack_a);
		ft_putstr("sa\n");
	}
	else if (set == DO_B)
	{
		node_swap(stack_b);
		ft_putstr("sb\n");
	}
	else if (set == DO_ALL)
	{
		node_swap(stack_a);
		node_swap(stack_b);
		ft_putstr("ss\n");
	}
}
void	push(t_stack **stack_a, t_stack **stack_b, char set)
{
	t_stack *tmp;

	if (set == DO_A)
	{
		if (!*stack_b)
			return ;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		ft_putstr("pa\n");
	}
	else if (set == DO_B)
	{
		if (!*stack_a)
			return ;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		ft_putstr("pb\n");
	}
}


void	rotate(t_stack **stack_a, t_stack **stack_b, char set)
{
	if (set == DO_A)
	{
		node_rotate(stack_a);
		ft_putstr("ra\n");
	}
	else if (set == DO_B)
	{
		node_rotate(stack_b);
		ft_putstr("rb\n");
	}
	else if (set == DO_ALL)
	{
		node_rotate(stack_a);
		node_rotate(stack_b);		
		ft_putstr("rr\n");
	}
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char set)
{
	if (set == DO_A)
	{
		node_reverse_rotate(stack_a);
		ft_putstr("rra\n");
	}
	else if (set == DO_B)
	{
		node_reverse_rotate(stack_b);
		ft_putstr("rrb\n");
	}
	else if (set == DO_ALL)
	{
		node_reverse_rotate(stack_a);
		node_reverse_rotate(stack_b);
		ft_putstr("rrr\n");
	}
}
