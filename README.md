# ComplexCalculator
Mathematical equation solver in Java with an extensible API.

## Description

### Purpose

* Works entirely in the command line
* Can solve mathematical expressions of infinite depth
* Can store, apply and plot mathematical functions
* Can solve logic expressions and plot truth tables (undocumented)

### Use

Run the program cc.jar via command line (CMD: java -jar cc.jar). Type in any
expression you want to solve, use <code>/h</code> for help. Store functions or 
constants by using the <code>:=</code> operator.

>You can also pass any sequence of equations to solve as argument, e.g.:
<br>
<br>
Input:<br><code>java -jar cc.jar 2+3 ans\*5</code><br>
Output:<br><code>2+3 = 5</code><br><code>ans*5 = 25</code>
</code>

## Dependencies

### Internal

The Project is based on the mkz_utils library which was made by me and is public
domain (see: <https://github.com/markoczy/JavaPowerUtils> or /lib folder).

### Third Party

At the moment there is no third party dependency.

## Strucural Design

### Projects

At the moment there are 2 Projects:

- JComplexCalculator: The Actual Java Project
- The old obsolete C++ Project with a GUI made in C#

### Classes

TODO: Explain architecture...

## License

The project is licensed under GPL Version 3.

## TODO

- Matrix integration
- Data structure 3.0 (multiway tree)
- Solver prototype
