# Minishell

## Introduction

The Minishell project is an exciting opportunity to recreate a simple shell environment similar to a minimalistic bash. This project has been a gateway into the world of processes and file descriptors, and understanding the internal workings of a shell.

## Skills and Knowledge Gained

Completing the Minishell project has been a journey of significant learning and skill acquisition. Here are the key areas of knowledge gained:

- **Process creation and synchronization**: Understanding how processes are created and synchronized formed the backbone of this project. This involved learning how to initiate processes, manage process IDs and parent-child process relationships.
- **Interpretation and execution of commands**: The project required the interpretation and execution of user commands, mimicking the behavior of a shell. This involved parsing user input and executing appropriate functions in response.
- **File descriptor manipulation**: The shell environment interacts heavily with files and hence, file descriptors. The project provided hands-on experience in working with file descriptors, including opening, closing, reading, and writing to files.
- **Usage of system calls and libraries in C**: The project provided exposure to various system calls and libraries in C, such as fork, wait, exec, and the readline library, deepening understanding of the language and its capabilities.

These skills form the crux of systems programming and are fundamental to understanding the operations of UNIX-like operating systems.

## Project Implementation

The Minishell operates in several stages to mimic the behavior of a shell:

1. **Tokenization**: The shell reads user input and breaks it down into words and operators, effectively tokenizing the input for parsing.
2. **Parsing**: The tokenized input is parsed into simple and compound commands, preparing them for execution.
3. **Expansion**: The shell performs various expansions on the parsed commands, such as variable expansions, wildcard expansions, and command substitutions.
4. **Redirection**: Any necessary redirections are performed, redirecting input and output as required by the user command. This includes handling pipe operations and redirecting output to files.
5. **Execution**: The shell executes the parsed command, creating new processes if necessary.
6. **Exit Status Collection**: Upon completion of the command, the shell collects the exit status, which can be queried using the special variable `$?`.

## Usage

The Minishell can be compiled and run using the following commands:

```bash
make
./minishell
```

## Troubleshooting

If the git submodules didn't clone properly, you can run the following commands to clone the submodules:

```bash
git submodule update --init --force --remote
```

For macOS user, you may need to install readline library using brew:

```bash
brew install readline
```
