/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loggers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:29:42 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 14:03:50 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

void	stack_log_detailed(t_stack stack)
{
	t_node	*node;
	int		index;

	if (!stack.head)
		return ;
	node = stack.head;
	index = 0;
	while (node)
	{
		ft_printf("[%d] %p: %d\n", index, node, node->content);
		node = node->next;
		if (node)
			ft_printf("\t  ↑↓\n");
		else
			ft_printf("\t   ↓\n");
		index++;
	}
	ft_printf("\t(null)\n");
}

void	stack_log_simple(t_stack stack)
{
	t_node	*node;

	node = stack.head;
	ft_printf("[ ");
	while (node)
	{
		ft_printf("%d ", node->content);
		node = node->next;
	}
	ft_printf("]\n");
}
