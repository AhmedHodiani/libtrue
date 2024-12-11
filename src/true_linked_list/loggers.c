/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:29:42 by ataher            #+#    #+#             */
/*   Updated: 2024/12/11 12:33:08 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void stack_log_detailed(t_stack stack)
{
	if (!stack.head)
		return ;
	t_node *node = stack.head;
	int index = 0;
	while (node)
	{
		printf("[%d] %p: %d\n", index, node, node->content);
		node = node->next;
		if (node)
			printf("\t  ↑↓\n");
		else
			printf("\t   ↓\n");
		index++;
	}
	printf("\t(null)\n");
}

void stack_log_simple(t_stack stack)
{
	t_node *node = stack.head;
	printf("[ ");
	while (node)
	{
		printf("%d ", node->content);
		node = node->next;
	}
	printf("]\n");
}
