/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:28:58 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 14:00:09 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void	stack_insert_at(t_stack *stack, t_node *node, int index)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->head;
	while (i < index - 1)
	{
		current = current->next;
		i++;
	}
	node->next = current->next;
	node->prev = current;
	current->next->prev = node;
	current->next = node;
	stack->size++;
}

void	stack_insert(t_stack *stack, t_node *node, int index)
{
	index = calc_reletive_index(stack, index);
	if (index == -1)
		return ;
	if (index == stack->size)
	{
		if (!stack->head)
			stack->head = node;
		else
		{
			stack->tail->next = node;
			node->prev = stack->tail;
		}
		stack->tail = node;
		stack->size++;
	}
	else if (index == 0)
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
		stack->size++;
	}
	else
		stack_insert_at(stack, node, index);
}

void	stack_push(t_stack *stack, t_node *node)
{
	return (stack_insert(stack, node, -1));
}
