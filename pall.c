#include "monty.h"

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
