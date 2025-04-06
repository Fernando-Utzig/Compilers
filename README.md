# Compilers

## Overview

This project implements the first stage of a compiler: a lexical analyzer (scanner). It's built using `flex` (for lexical analysis) and C++.  The scanner reads source code, identifies tokens, and builds a basic symbol table. This is part of a Compiler course in Computer Engineering.

## Technologies Used

*   `flex`
*   C++

## Build and Execution

1.  **Compile:**
    ```bash
    make
    ```
2.  **Run:**
    ```bash
    ./etapa1 test.txt
    ```

This will analyze the `test.txt` file and print the recognized tokens and the symbol table.