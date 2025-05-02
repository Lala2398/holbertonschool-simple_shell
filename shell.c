#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define PROMPT "#cisfun$ "

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;

    while (1)
    {
	    if (isatty(STDIN_FILENO))
		    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	    read = getline(&line, &len, stdin);
	    if (read == -1)
	    {
		    free(line);
		    if (isatty(STDIN_FILENO))
			    write(STDOUT_FILENO, "\n", 1);
		    exit(0);
	    }
	    line[strcspn(line, "\n")] = '\0';
	    if (strlen(line) == 0)
		    continue;
	    pid = fork();
	    if (pid == -1)
	    {
		    perror("fork");
		    exit(EXIT_FAILURE);
	    }
	    if (pid == 0)
	    {
		    char *argv[] = {line, NULL};
		    execve(line, argv, environ);
		    perror("./shell");
		    exit(EXIT_FAILURE);
	    }
	    else
	    {
		    waitpid(pid, &status, 0);
	    }
    }
    free(line);
    return 0;
}
