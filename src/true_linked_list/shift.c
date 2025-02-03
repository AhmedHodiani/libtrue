/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:05:01 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 13:23:39 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void	shift_left(t_stack *stack)
{
	t_node	*head_temp;
	t_node	*tail_temp;

	head_temp = stack->head;
	tail_temp = stack->tail;
	tail_temp->next = head_temp;
	head_temp->prev = tail_temp;
	stack->head = head_temp->next;
	stack->tail = head_temp;
	head_temp->next->prev = NULL;
	head_temp->next = NULL;
}

void	shift_right(t_stack *stack)
{
	t_node	*head_temp;
	t_node	*tail_temp;

	head_temp = stack->head;
	tail_temp = stack->tail;
	head_temp->prev = tail_temp;
	tail_temp->next = head_temp;
	stack->head = tail_temp;
	stack->tail = tail_temp->prev;
	tail_temp->prev->next = NULL;
	tail_temp->prev = NULL;
}

int	stack_shift(t_stack *stack, int rounds)
{
	if (rounds > 0)
	{
		shift_right(stack);
		rounds--;
	}
	else if (rounds < 0)
	{
		shift_left(stack);
		rounds++;
	}
	else
		return (1);
	stack_shift(stack, rounds);
	return (0);
}
