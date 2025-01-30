/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 19:36:25 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-16 19:36:25 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	init_stack(t_stack **a, char **av)
{
	int		i;
	long	nbr;

	i = 0;
	while (av[i])
	{
		if (!verify_sintax(av[i]))
			error(a);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error(a);
		if (!verify_duplicate(*a, (int)nbr))
			error(a);
		lstadd_back(a, lstnew(nbr));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		init_stack(&stack_a, av);
		free_matrix(av);
	}
	else
	{
		av++;
		init_stack(&stack_a, av);
	}
	assigin_index(stack_a);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
