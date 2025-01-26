/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 22:38:08 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-23 22:38:08 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	tmp = lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}
t_stack	*lstnew(int content)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
t_stack	*lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	lstdelone(t_stack *stack)
{
	free(stack->content);
	free(stack);
}
