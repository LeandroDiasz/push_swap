/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.rio>         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 19:37:11 by ledias-d          #+#    #+#             */
/*   Updated: 2025-01-16 19:37:11 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

/*--- main.c ---*/
void	init_stack(t_stack **a, char **av);

/*--- stack.c ---*/
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstnew(int content);
t_stack	*lstlast(t_stack *lst);

/*--- erro.c ---*/
void	free_stack(t_stack **stack);
void	error(t_stack **stack);

/*--- verify_stack.c ---*/
int		verify_duplicate(t_stack *stack_a, int nbr);
long	ft_atol(const char *str);
int		verify_sintax(char *av);

#endif