# holySHI Language
holySHI is a simple, custom programming language designed for educational purposes. It features basic integer variable declarations, arithmetic operations, and print functionality.


## Features

- Variable declaration using `summonsoul` (supports only integer value right now).
- Arithmetic operations (`+`, `-`, `*`, `/`).
- Print statements using `chant`.

## File Extension

The holySHI language uses the `.hshi` file extension for its source files.

## Usage
### 1. Create a `.hshi` File
Write your holySHI code in a file with the `.hshi` extension. For example, create a file named `example.hshi`:
```plaintext
summonsoul a = 10;
summonsoul b = 20;
summonsoul sum = a + b;
chant(sum);
```
### 2 . Compile and Run Your Code
To compile and run your holySHI code, follow these steps:
#### 1.Compile 
```plaintext
g++ -o holySHI main.cpp
```
#### 2.Run the holySHI programme:
```plaintext
./holySHI example.hshi
```
### Sample Output
For the `example.hshi` file, the output will be:
30

# Implementation Details

## Lexer

The lexer tokenizes the source code into tokens. Each token is categorized into different types, such as Keyword, Identifier, Assignment, Number, String, Plus, Minus, Multiply, Divide, Modulus, Equal, LessThan, GreaterThan, LessEqual, LParen, RParen, Eol.

## Parser

The parser processes the tokens and builds an Abstract Syntax Tree (AST). It supports parsing statements and expressions, including variable declarations and arithmetic operations.

## Code Generation

The code generation phase translates the AST into executable code. Currently, it generates C++ code as an intermediate step, which is then compiled and executed.

## Development

### Source Code Structure

- `lexer.h`: Contains the definitions for tokens and the lexer structure.
- `lexer.cpp`: Implements the lexer for tokenizing the source code.
- `AST.h`: Contains the definitions for the Abstract Syntax Tree (AST) nodes.
- `Parser.h`: Implements the parser for generating the AST from tokens.
- `codeGeneration.h`: Implements the code generation from the AST to C++ code.
- `main.cpp`: The entry point for the holySHI interpreter.







