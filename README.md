# Cdoku Solver

**Sudoku solver in C with recursive backtracking.**

A C implementation of the algorithm from Computerphile
found here: https://www.youtube.com/watch?v=G_UYXzGuqvM

Implemented using a one-dimensional array to represent the board.
Rows and colums are calculated based on the cell's distance from the 0 index.

## Current state

As of now the program can solve a Sudoku board that has been declared in the main function.
While this serves as a proof-of-concept for the algorithm, it does not emulate any real-life use-case.
Future implementations may attempt to remedy this in one or more ways.

It compiles without errors or warnings using the following flags:
-Wall -Werror -Wextra

## Why?

I wrote chose to implement this in C as a way to practice using the language.
Personally I found this project to be a nice introduction to arrays and pointers.

I have previously implemented variations of this in Python and Javascript.
This proved to be a welcome change.
