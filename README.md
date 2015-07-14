# ComplexCalculator
Complex math Expression parser in C++ (Core) and C# (CLI)

## Description

### Purpose

* Command line tool to solve an equation string and output a double value in return.
* Can solve equations of infinite depth as it uses a fully recursive solving algorithm
* Can validate a string before solving (Attention: validation rather basic)

### Use

Run the program cc.exe via command line (I recommend to put it somewhere in %PATH%)

### Example usage:

* Input > "cc (-(21.433*0.46+75)+4*5.775/94-1)"
* Output> "-85,6134353191489"

NB: Please note that the exponential function technically exists put the character is escaped by windows CMD 
    use enclosing " signs in your equation to avoid this ( i.e. "(2^3)3" )

## Dependencies

### In-Project Dependencies

The C# Project depends on the Core Project in C++ (ccalc.dll) this library has to be in a folder named "lib"

### Third Party

At the moment there is no third party dependency, but I plan to have an SQLite DB attached,
it will be used to store user-defined function definitions (see TODO section)

## Strucural Design

### Projects

At the moment there are 3 Projects:

* CCalc_Core: The Core library in C++
* CCalc_DLL: The DLL export logic to use the DLL for C# and Java projects (JNA)
* CCalc_CS: The DLL import logic for C# and the Command Line Interface (will soon be exported to CCalc_CLI)

### Classes

These are the classes that build the Core logic:

* CEqParser: The parser.
    * Used to solve an equation string
  
* CAbstractEq: The abstract Equations class, 
    * All operations (add, multiply etc.) inherit from this class
    * Contains method "getValue()" to retreive the value as a double
    * Most important child: CChaineq (Can hold linear equations of infinite lentgh and solve them in appropriate order)

## TODO

* Error Codes

* DLL Wrapper for C# / Java

* Command Line Interface:
   * CLI Loop
   * History
   * Settings: 
     * Log steps count
     * Function (DB) files to load (e.g. "trigo.db","stats.db" etc.)

*  Functions Parser:
   * Built-In functions: ANS, abs, exp, sin, cos, etc. -> DONE!
   * Define functions mechanism ( e.g. "f(x,y):=32*x+y" ) -> DONE!
   * Store functions, mechanisms: RAM (volatile), SQLiteDB (static)
   * Parse operations with functions ( e.g. "f(21,34)" ) -> DONE!
   * Lambda functions (infinite length)

## Contribution

If you want to contribute to this project, you are very welcome! Also if you want to use the algorithm in one of
your projects, please feel free :-) However if you want to contribute to the core project, please mail me what you
are planning to do so that we don't work both at the same improvement.

Sorry for the rather basic commenting, this will be improved in future versions...
