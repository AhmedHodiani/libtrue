#include "include/true_linked_list.h"



int main()
{
	t_stack stack = stack_init();

	t_node *node1 = node_init(strdup("Hello"));
	t_node *node2 = node_init(strdup("Hi"));
	t_node *node3 = node_init(strdup("gg"));
	t_node *node4 = node_init(strdup("me"));

	stack.push(&stack, node1);
	stack.push(&stack, node2);
	stack.insert(&stack, node3, 0);
	stack.push(&stack, node4);

	stack.log.detailed(stack);
	stack.clear(&stack);
}
