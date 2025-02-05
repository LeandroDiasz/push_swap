/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 16:29:25 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-26 16:29:25 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	j;	
	int	max_bits;

	i = 0;
	max_bits = 0;
	assigin_index(*stack_a);
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push(stack_a, stack_b, DO_B);
			else
				rotate(stack_a, NULL, DO_A);
			j++;
		}
		while (lstsize(*stack_b) > 0)
			push(stack_a, stack_b, DO_A);
		i++;
	}
}
