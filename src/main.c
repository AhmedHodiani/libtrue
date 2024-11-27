#include "../include/true_linked_list.h"

t_node *node_init(void *content)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void stack_insert(t_stack *stack, t_node *node, ssize_t index)
{
	if (index == -1 || index == stack->size)
	{
		if (!stack->head)
			stack->head = node;
		else
		{
			stack->tail->next = node;
			node->prev = stack->tail;
		}
		stack->tail = node;
		stack->size++;
		return ;
	}
	else if (index == 0)
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
		stack->size++;
		return ;
	}

	if (index > stack->size)
	{
		printf("Index out of range\n");
		return ;
	}

	ssize_t i = 0;
	t_node *current = stack->head;
	while (i < index - 1)
	{
		current = current->next;
		i++;
	}
	node->next = current->next;
	node->prev = current;
	current->next->prev = node;
	current->next = node;
	stack->size++;
	return ;
}

void stack_push(t_stack *stack, t_node *node)
{
	return stack_insert(stack, node, -1);
}

t_stack stack_init(void)
{
	t_stack stack;
	stack.head = NULL;
	stack.tail = NULL;
	stack.size = 0;

	stack.insert = stack_insert;
	stack.push = stack_push;
	stack.log.simple = stack_log_simple;
	stack.log.detailed = stack_log_detailed;
	return (stack);
}

int main()
{
	t_stack stack = stack_init();
	t_node *node1 = node_init("Hello");
	t_node *node2 = node_init("Hi");
	t_node *node3 = node_init("gg");

	stack.push(&stack, node1);
	stack.push(&stack, node2);
	stack.insert(&stack, node3, 0);
	stack.log.detailed(stack);
}
