/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 17:12:03 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-26 17:12:03 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	node_swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack || !*stack || !(*stack)->next)
			return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	node_rotate(t_stack **stack)
{
	t_stack *first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	lstadd_back(stack, first);
}

void	node_reverse_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	assigin_index(t_stack *stack) 
{
	t_stack	*current;
	t_stack	*iterator;
	int		index;

	current = stack;
	while (current)
	{
		iterator = stack;
		index = 0;
		while (iterator)
		{
			if(current->content > iterator->content)
				index++;
			iterator = iterator->next;
		}
		current->index= index;
		current = current->next;
	}
}