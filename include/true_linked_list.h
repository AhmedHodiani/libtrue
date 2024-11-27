/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_linked_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataher <ataher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:28:19 by ataher            #+#    #+#             */
/*   Updated: 2024/11/27 15:30:07 by ataher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTRUE_LINKED_LIST_H
# define LIBTRUE_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;


// loggers
void stack_log(t_stack stack);
void stack_log_detailed(t_stack stack);


#endif
