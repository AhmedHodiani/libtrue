/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:24:02 by ataher            #+#    #+#             */
/*   Updated: 2024/12/08 12:25:23 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

t_stack stack_init(void)
{
	t_stack stack;
	stack.head = NULL;
	stack.tail = NULL;
	stack.size = 0;

	stack.insert = stack_insert;
	stack.push = stack_push;
	stack.pop = stack_pop;
	stack.clear = stack_clear;
	stack.log.simple = stack_log_simple;
	stack.log.detailed = stack_log_detailed;
	return (stack);
}

t_node *node_init(void *content)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
