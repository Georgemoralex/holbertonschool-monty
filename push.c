#include "monty.h"

/**
 * _push -  pushes an element to the stack
 * @stack: double pointer to header (top) of the stack
 * @line_number: counter for line number of the file
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	size_t len = 0, i = 0;
	char arg[128] = "";
	char *argument = arg;

	argument = strtok(NULL, " \t\r\n\v\f");

	if (argument == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_stack_t(*stack);

		exit(EXIT_FAILURE);
	}

	len = strlen(argument);
	for (i = 0; i < len; i++)
		if (!isdigit(argument[i]) && argument[0] != '-')
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
			free_stack_t(*stack);

			exit(EXIT_FAILURE);
		}

	if (stack_queue == 's')
		add_node(stack, atoi(argument));

	if (stack_queue == 'q')
		add_node_queue(stack, atoi(argument));
}
