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
	int	len;

	len = lstsize(*stack_a);
	if (len <= 2)
		sort_two(stack_a);
	else if (len <= 3)
		sort_three(stack_a);
	else if (len <= 5)
		medium_sort(stack_a, stack_b);
	/*else
		radix(stack_a, stack_b);*/
}

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, NULL, DO_A);
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->index;
	mid = (*stack_a)->next->index;
	bot = (*stack_a)->next->next->index;

	if (top == 0 && mid == 2 && bot == 1)
	{
		reverse_rotate(stack_a, NULL, DO_A);
		swap(stack_a, NULL, DO_A);
	}
	else if (top == 1 && mid == 0 && bot == 2)
		swap(stack_a, NULL, DO_A);
	else if (top == 1 && mid == 2 && bot == 0)
		reverse_rotate(stack_a, NULL, DO_A);
	else if (top == 2 && mid == 0 && bot == 1)
		rotate(stack_a, NULL, DO_A);
	else if(top == 2 && mid == 1 && bot == 0)
	{
		swap(stack_a, NULL, DO_A);
		reverse_rotate(stack_a, NULL, DO_A);
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		max_value;
	int		i;
	t_stack	*current;

	i = 0;
	while (i < 2)
	{
		current = *stack_a;
		max_value = (*stack_a)->index;
		while (current)
		{
			if (current->index > max_value)
				max_value = current->index;
			current = current->next;
		}
		while (*stack_a && (*stack_a)->index != max_value)
			rotate(stack_a, NULL, DO_A);
		push(stack_a, stack_b, DO_B);
		i++;
	}
	if (*stack_a)
		sort_three(stack_a);
	while (i--)
		push(stack_b, stack_a, DO_A);
}

