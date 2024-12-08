/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:28:58 by ataher            #+#    #+#             */
/*   Updated: 2024/12/08 12:29:08 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void stack_insert(t_stack *stack, t_node *node, ssize_t index)
{
	if (index < 0)
		index += stack->size + 1;
	if (index < 0)
	{
		printf("Index out of range\n");
		return ;
	}
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
		return ;
	}
	else if (index == 0)
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
		stack->size++;
		return ;
	}

	if (index > stack->size)
	{
		printf("Index out of range\n");
		return ;
	}

	ssize_t i = 0;
	t_node *current = stack->head;
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
	return ;
}

void stack_push(t_stack *stack, t_node *node)
{
	return stack_insert(stack, node, -1);
}
