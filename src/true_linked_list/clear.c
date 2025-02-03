/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:46 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 13:28:36 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current)
	{
		next = current->next;
		node_clear(current);
		current = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	free(stack);
}

void	node_clear(t_node *node)
{
	free(node);
}
