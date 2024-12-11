/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:24 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 14:22:02 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void stack_pop(t_stack *stack, ssize_t index)
{
	if (!stack->head)
		return ;
	if (index < 0)
		index += stack->size;
	if (index < 0 || index >= stack->size)
	{
		printf("Index out of range\n");
		return ;
	}
	if (index == 0)
	{
		t_node *node = stack->head;
		// printf("node to del %d\n", node->content);
		if (node->next)
		{
			stack->head = node->next;
			stack->head->prev = NULL;
		}
		else {
			stack->head = NULL;
			stack->tail = NULL;
		}
		node_clear(node);
		stack->size--;
	}
	// else if (index == stack->size - 1)
	// {
	// 	t_node *node = stack->tail;
	// 	stack->tail = node->prev;
	// 	stack->tail->next = NULL;
	// 	node_clear(node);
	// 	stack->size--;
	// }
	// else
	// {
	// 	ssize_t i = 0;
	// 	t_node *current = stack->head;
	// 	while (i < index)
	// 	{
	// 		current = current->next;
	// 		i++;
	// 	}
	// 	t_node *prev = current->prev;
	// 	t_node *next = current->next;
	// 	prev->next = next;
	// 	next->prev = prev;
	// 	node_clear(current);
	// 	stack->size--;
	// }
}
