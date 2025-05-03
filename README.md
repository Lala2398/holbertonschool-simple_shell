# holbertonschool-simple_shell



## Project Description : 
Holberton Simple Shell is a basic Unix command-line interpreter (shell) written in C. 
It was developed as a first-trimester project by Lala Ibadullayeva and Okan Mahmudov during the period from May 21st, 2025 to May 4th, 2025.
The shell interprets and executes user input, replicating core functionalities of popular shells like bash. 
It handles command parsing, locating binaries via the PATH environment variable, executing programs using fork and execve, and managing basic built-in commands like env and exit.

### Features : 
- Executes commands located in system PATH
- Handles absolute and relative paths
- Supports built-in env to display environment variables
- Supports built-in exit to terminate the shell
- Parses input into argument arrays
- Gracefully handles unknown commands
- Clean error messaging


### File Structure : 

```
├── shell.c            # Main project code
├── main.h             # Header file
├── README.md          # General knowledge of the project
├── AUTHORS            # Names of Authors
├──man_1_simple_shell  # Manual page for the shell

````


### Compilation :
````
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
````

### Usage : 
- To start the shell:
```
./hsh
```

- Then enter commands like:
```
$ ls
$ pwd
$ env
$ exit
```

### Known Limitations :
- No support for piping (|), redirection (>, <), or logical operators (&&, ||).
- No prompt displayed for user input (i.e., doesn't print $ or similar).
- No advanced error handling (e.g., for permission denied).
- Doesn't support comments or complex input syntax.


### Viewing the Manual Page : 

````
man ./man_1_simple_shell
````


### Authors
- Lala Ibadullayeva
- Okan Mahmudov
