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

void	node_swap(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	stack = stack->next;
	stack->next = tmp;
}

void	swap(t_stack *stack_a, t_stack *stack_b, char set)
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
void	push(t_stack *stack_a, t_stack *stack_b, char set)
{
	if (set == DO_A)
	{
		lstadd_front(&stack_a, stack_b);
		lstdelone(stack_b);
		ft_putstr("pa\n");
	}
	else if (set == DO_B)
	{
		lstadd_front(&stack_b, stack_a);
		lstdelone(stack_a);
		ft_putstr("pb\n");
	}
}

void	rotate(t_stack *stack_a, t_stack *stack_b, char set)
{
	if (set == DO_A)
	{

		ft_putstr("ra\n");
	}
	else if (set == DO_B)
	{

		ft_putstr("rb\n");
	}
	else if (set == DO_ALL)
	{
		
		ft_putstr("rr\n");
	}
}

void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, char set)
{
	if (set == DO_A)
	{

		ft_putstr("rra\n");
	}
	else if (set == DO_B)
	{

		ft_putstr("rrb\n");
	}
	else if (set == DO_ALL)
	{

		ft_putstr("rrr\n");
	}
}
