#include "monty.h"
/**
 *exe - function to execute stack operation
 *@stack: is pointer stack of doubly linked list
 *@line_number: is the number of script
 *@arg: is the argument
 */

void exe(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t ops[] = {
		{"push", m_push},
		{"pall", m_pall},
		{NULL, NULL}
	};
	i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}