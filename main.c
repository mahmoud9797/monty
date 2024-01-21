#include "monty.h"
#include <stdio.h>
/**
 * main - function handle monty interperter
 *@argc: number of passed arguments
 *@argv: array of arguments strings
 *Return: EXIT_SUCCESS on success
 */
int main(int argc, char *argv[])
{
	FILE *m_file;
	char *f_name;
	stack_t *stack = NULL;
	char *m_line = NULL;
	unsigned int n_line = 0;
	size_t n_reads = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	f_name = argv[1];
	m_file = fopen(f_name, "r");
	if (!m_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", f_name);
		return (EXIT_FAILURE);
	}
	while (getline(&m_line, &n_reads, m_file) != -1)
	{
		n_line++;
		opcode = strtok(m_line, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
		{
			exe(opcode, &stack, n_line);
		}
	}
	free(m_line);
	fclose(m_file);

	exit(EXIT_SUCCESS);
}
