/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:24 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 14:02:34 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void	stack_pop(t_stack *stack, int index)
{
	t_node	*node;

	index = calc_reletive_index(stack, index);
	if (index == -1)
		return ;
	if (index == 0)
	{
		node = stack->head;
		if (node->next)
		{
			stack->head = node->next;
			stack->head->prev = NULL;
		}
		else
		{
			stack->head = NULL;
			stack->tail = NULL;
		}
		node_clear(node);
		stack->size--;
	}
}
