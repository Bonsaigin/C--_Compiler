# Background
This was originally a project for CS441, but I've chosen to keep working with it after school.

C- is an extension of the C-- language. More info about C-- can be found here at a mirror of the language's original site: http://www.cs.tufts.edu/~nr/c--/index.html 

The purpose of this project is to extend the C-- language to include new features. We can do this by including new syntactic and semantic rules and defining what happens with these new grammar constructs.

# Usage
- (Optional if not altering grammar) Generate new files
> bnfc -cpp cmm.cf

- Build both the compiler and pstack:
> make

- Compile fib.cmm, producing fib.apm:
> ./cmm2pstack fib.cmm fib.apm

- Disassemble fib.apm:
> ./pstack/apd fib

- Execute fib.apm:
> ./pstack/api fib

# Features
  The cmm standard library contains three functions:

  exit()      : ends the program immediately  

  puts("...") : prints a string (only literal strings are supported)  

  putn(num)   : prints an integer (like printf("\t%d\n", num))  

  We have included functionality to read numbers:  

  getnum()    : gets a number from stdin

Note that function calls are not yet checked for number and type of
arguments; giving the wrong number is likely to smash the stack.
All functions return a value. Functions with multiple arguments are not parsed correctly.

Features implemented include:
* getnum()
* if and if-else
* simple for loop
* global variables

Planned features NOT yet implemented include:
* swap optimization
* scoped for loop
* function argument count checking
* doubles 
* type checking
* arrays
* hash tables

NOTE: The beginning of this project was done together by David Jones
and Ian Gibson. The work was divided evenly. David wrote SIf and
SFor, Ian wrote getnum() and SIfElse. The implementation of global
variables was a joint effort. The decisions and construction of
the grammar were decided upon together.
