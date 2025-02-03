/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:57:03 by ataher            #+#    #+#             */
/*   Updated: 2025/01/20 13:57:15 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/true_linked_list.h"

int	calc_reletive_index(t_stack *stack, int index)
{
	if (index < 0)
		index += stack->size + 1;
	if (index < 0 || index > stack->size)
		return (-1);
	return (index);
}
