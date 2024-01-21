#include "monty.h"
/**
 * m_push - add node to the stack
 * @stack: pointer to the top of stack
 * @line_number: line_number
 * Return: no return
*/
void m_push(stack_t **stack, unsigned int line_number)
{
	int v = 0;
	stack_t *new_node;
	char *arg = strtok(NULL, " \t\n");

	if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	v = atoi(arg);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = v;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	(*stack) = new_node;
}
