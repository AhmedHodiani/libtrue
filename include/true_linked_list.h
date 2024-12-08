/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_linked_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:28:19 by ataher            #+#    #+#             */
/*   Updated: 2024/12/08 12:30:06 by ataher           ###   ########.fr       */
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
	void	(*pop)(struct s_stack *stack, ssize_t index);
	t_stack_log	log;
}	t_stack;


// loggers
void stack_log_simple(t_stack stack);
void stack_log_detailed(t_stack stack);

// init
t_stack stack_init(void);
t_node *node_init(void *content);

// clear
void stack_clear(t_stack *stack);
void node_clear(t_node *node);

// pop
void stack_pop(t_stack *stack, ssize_t index);

// insert
void stack_insert(t_stack *stack, t_node *node, ssize_t index);
void stack_push(t_stack *stack, t_node *node);


#endif
