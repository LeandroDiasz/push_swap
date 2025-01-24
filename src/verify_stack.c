/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 18:32:43 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-24 18:32:43 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	verify_sintax(char *av)
{
	int	i;

	i = 0;
	while (av[i] == '+' || av[i] == '-')
		i++;
	if (!ft_isdigit(av[i]))
		return (0);
	while (av[i])
	{	
		if(!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	long	imp;
	long	result;

	result = 0;
	i = 0;
	imp = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	else if (str[i] == '-')
	{
		imp *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * imp);
}

int	verify_duplicate(t_stack *stack_a, int nbr)
{
	t_stack *tmp;
	if (!stack_a)
		return (1);
	tmp = stack_a;
	while (tmp != NULL)
	{
		if (tmp->content == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
	
}
