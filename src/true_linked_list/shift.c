/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:05:01 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 12:30:22 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

t_node *stack_get(t_stack *stack, int index)
{
	if (index < 0)
		index += stack->size;
	if (index < 0 || index >= stack->size)
	{
		printf("Index out of range\n");
		return (NULL);
	}
	t_node *node = stack->head;
	int i = 0;
	while (node)
	{
		if (i == index)
			return (node);
		node = node->next;
		i++;
	}
	return (NULL);
}

void stack_shift(t_stack *stack, int rounds)
{
	t_node *head_temp = stack->head;
	t_node *tail_temp = stack->tail;

	if (rounds > 0)
	{

		head_temp->prev = tail_temp;
		tail_temp->next = head_temp;

		stack->head = tail_temp;
		stack->tail = tail_temp->prev;

		tail_temp->prev->next = NULL;
		tail_temp->prev = NULL;

		rounds--;
	}
	else if (rounds < 0)
	{

		tail_temp->next = head_temp;
		head_temp->prev = tail_temp;

		stack->head = head_temp->next;
		stack->tail = head_temp;

		head_temp->next->prev = NULL;
		head_temp->next = NULL;

		rounds++;
	}
	else return ;
	stack_shift(stack, rounds);
}
