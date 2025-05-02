#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

/**
 * string_to_words_array - Tokenizes a line into an array of words.
 * @line: The input line to tokenize.
 *
 * Return: A NULL-terminated array of words (arguments), or NULL on failure.
 */
char **string_to_words_array(char *line)
{
	char *line_copy = NULL;
	char **argv = NULL;
	char *arg = NULL;
	size_t argc = 0;
	size_t i = 0;

	line_copy = strdup(line);
	if (line_copy == NULL)
		return (NULL);

	arg = strtok(line_copy, " \n");
	while (arg)
	{
		argc++;
		arg = strtok(NULL, " \n");
	}
	free(line_copy);

	if (argc == 0)
		return (NULL);

	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);

	arg = strtok(line, " \n");
	for (i = 0; i < argc; i++)
	{
		argv[i] = arg;
		arg = strtok(NULL, " \n");
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * fork_and_execute - Forks and executes a command using execve.
 * @argv: Argument vector for the command.
 */
void fork_and_execute(char **argv)
{
	pid_t pid;
	int status;

	if (argv == NULL)
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line = NULL;
	char **argv = NULL;
	size_t buffer_length = 0;
	ssize_t input_length = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		line = NULL;
		input_length = getline(&line, &buffer_length, stdin);
		if (input_length == -1)
		{
			free(line);
			break;
		}

		argv = string_to_words_array(line);
		if (argv == NULL)
		{
			free(line);
			continue;
		}

		fork_and_execute(argv);

		free(argv);
		free(line);
	}

	return (0);
}
