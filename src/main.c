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

void stack_log(t_stack stack)
{
	if (!stack.head)
		return ;
	t_node *node = stack.head;
	while (node)
	{
		printf("%s\n", (char *)node->content);
		node = node->next;
	}
}

t_stack stack_init(void)
{
	t_stack stack;
	stack.head = NULL;
	stack.tail = NULL;
	stack.size = 0;
	return (stack);
}

int main()
{
	t_stack stack = stack_init();
	t_node *node1 = node_init("Hello");
	t_node *node2 = node_init("Hi");
	t_node *node3 = node_init("gg");

	stack_insert(&stack, node1, -1);
	stack_insert(&stack, node2, -1);
	stack_insert(&stack, node3, 0);
	stack_log(stack);
}
