/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:24:02 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 13:53:09 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"
#include <string.h>

t_stack	*stack_init(char name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->name = name;
	stack->insert = stack_insert;
	stack->push = stack_push;
	stack->pop = stack_pop;
	stack->clear = stack_clear;
	stack->get = stack_get;
	stack->shift = stack_shift;
	stack->find = stack_find;
	stack->log.simple = stack_log_simple;
	stack->log.detailed = stack_log_detailed;
	return (stack);
}

t_node	*node_init(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	node->dup = node_dup;
	return (node);
}
