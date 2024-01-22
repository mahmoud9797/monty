#include "monty.h"
/**
 *pint - function to print the top element of the stack
 *@stack: point to the top element
 *@line_number: the number of line in file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
