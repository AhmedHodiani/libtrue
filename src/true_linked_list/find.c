/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:08:59 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 16:52:01 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

int	stack_find(t_stack stack, int content)
{
	int	i;

	i = 0;
	while (stack.head)
	{
		if (stack.head->content == content)
			return (i);
		stack.head = stack.head->next;
		i++;
	}
	return (-1);
}

t_node	*stack_get(t_stack *stack, int index)
{
	t_node	*node;
	int		i;

	if (index < 0)
		index += stack->size;
	if (index < 0 || index >= stack->size)
		return (NULL);
	node = stack->head;
	i = 0;
	while (node)
	{
		if (i == index)
			return (node);
		node = node->next;
		i++;
	}
	return (NULL);
}
