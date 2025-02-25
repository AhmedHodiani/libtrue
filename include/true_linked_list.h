/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_linked_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:28:19 by ataher            #+#    #+#             */
/*   Updated: 2025/01/22 01:06:01 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRUE_LINKED_LIST_H
# define TRUE_LINKED_LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../../libftprintf/include/libftprintf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*(*dup)(struct s_node *node);
}	t_node;

struct	s_stack;

typedef struct s_stack_log {
	void	(*simple)(struct s_stack stack);
	void	(*detailed)(struct s_stack stack);
}	t_stack_log;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	char			name;
	int				(*find)(struct s_stack stack, int content);
	void			(*insert)(struct s_stack *stack, t_node *node, int index);
	void			(*push)(struct s_stack *stack, t_node *node);
	void			(*clear)(struct s_stack *stack);
	void			(*pop)(struct s_stack *stack, int index);
	int				(*shift)(struct s_stack *stack, int rounds);
	t_node			*(*get)(struct s_stack *stack, int index);
	t_stack_log		log;
}	t_stack;

// loggers
void	stack_log_simple(t_stack stack);
void	stack_log_detailed(t_stack stack);

// init
t_stack	*stack_init(char name);
t_node	*node_init(int content);

// clear
void	stack_clear(t_stack *stack);
void	node_clear(t_node *node);

// pop
void	stack_pop(t_stack *stack, int index);

// insert
void	stack_insert(t_stack *stack, t_node *node, int index);
void	stack_push(t_stack *stack, t_node *node);

// get
t_node	*stack_get(t_stack *stack, int index);
int		stack_shift(t_stack *stack, int rounds);

// dup
t_node	*node_dup(t_node *node);

// find
int		stack_find(t_stack stack, int content);

// general
int		calc_reletive_index(t_stack *stack, int index);

#endif
