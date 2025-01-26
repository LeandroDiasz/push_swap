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
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = lstsize(stack_a);
	if (len <= 3)
		small_sort(stack_a, stack_b);
	else if (len <= 5)
		medium_sort(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b)
{

}
