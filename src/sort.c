/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 15:20:21 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-26 15:20:21 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;
	int		nbr;

	tmp = stack;
	while (tmp->next)
	{
		nbr = tmp->content;
		tmp = tmp->next;
		if (!(nbr < tmp->content))
			return (0);
	}
	return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lstsize(*stack_a);
	if (size <= 2)
		sort_two(stack_a);
	else if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		medium_sort(stack_a, stack_b, size);
	else
		radix(stack_a, stack_b);
}

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, NULL, DO_A);
}

void	sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	assigin_index(*stack);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (top == 0 && mid == 2 && bot == 1)
	{
		reverse_rotate(stack, NULL, DO_A);
		swap(stack, NULL, DO_A);
	}
	else if (top == 1 && mid == 0 && bot == 2)
		swap(stack, NULL, DO_A);
	else if (top == 1 && mid == 2 && bot == 0)
		reverse_rotate(stack, NULL, DO_A);
	else if (top == 2 && mid == 0 && bot == 1)
		rotate(stack, NULL, DO_A);
	else if (top == 2 && mid == 1 && bot == 0)
	{
		swap(stack, NULL, DO_A);
		reverse_rotate(stack, NULL, DO_A);
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		min_value;
	t_stack	*current;

	assigin_index(*stack_a);
	while (lstsize(*stack_a) > 3)
	{
		current = *stack_a;
		min_value = (*stack_a)->index;
		while (current)
		{
			if (current->index < min_value)
				min_value = current->index;
			current = current->next;
		}
		if (lstlast(*stack_a)->index == min_value)
			reverse_rotate(stack_a, NULL, DO_A);
		while (*stack_a && (*stack_a)->index != min_value)
			rotate(stack_a, NULL, DO_A);
		push(stack_a, stack_b, DO_B);
	}
	sort_three(stack_a);
	while (lstsize(*stack_a) != size)
		push(stack_a, stack_b, DO_A);
}
