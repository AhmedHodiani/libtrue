/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_linked_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:28:19 by ataher            #+#    #+#             */
/*   Updated: 2024/11/27 16:20:32 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTRUE_LINKED_LIST_H
# define LIBTRUE_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

struct s_stack;

typedef struct s_stack_log {
	void	(*simple)(struct s_stack stack);
	void	(*detailed)(struct s_stack stack);
}	t_stack_log;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;

	void	(*insert)(struct s_stack *stack, t_node *node, ssize_t index);
	void	(*push)(struct s_stack *stack, t_node *node);
	void	(*clear)(struct s_stack *stack);
	t_stack_log	log;
}	t_stack;


// loggers
void stack_log_simple(t_stack stack);
void stack_log_detailed(t_stack stack);

#endif
