# simple_shell

# A simple C shell project

## Description

This is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C as a milestone project for Alx-Holberton School.

## Installation

Clone this repository into your working directory. Files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

## Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

## Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

## Non-Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

echo "ls" | ./shell
In non-interactive mode, the program will exit after finishing your desired command(s).

This is the man page which contains all functions and descriptions of all the functions used in this Simple shell project. To access this page, Do:

## AUTHORS

This file contains the details of all the individuals that contributed to this shell project.

## Features

1. DIsplay a prompt and wait for the user to type a command. A command-line always ends with a new line.
2. The prompt is displayed again each time a command has been executed.
3. The command lines are simple, no semicolons, no pipes, no redirections, or any other advanced features.
4. The command lines are made only of one word.No arguement will be passed to the programs.
5.If an executable is not found the shell prints an error message and displayu the prompt again.

## Credits

All codes written by Ademola Glory and Emmanuel Murairi.
