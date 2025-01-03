/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:46 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 12:47:44 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void stack_clear(t_stack *stack)
{
	t_node *current = stack->head;
	while (current)
	{
		t_node *next = current->next;
		node_clear(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void node_clear(t_node *node)
{
	// free(node->content);
	free(node);
}
