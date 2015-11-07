# 14. Working with larger programs

C provides all the features necessary for the efficient development of large programs. Some of the topics covered include:

* Breaking large programs into **multiple files**
* Working with **external variables**
* Extending the use of **header files**
	
## 14.1 Dividing your program into multiple files

When you start dealing with larger programs and as the number of statements in the program increases, so does the time it takes to edit the program and subsequently recompile it. 

Large programming applications frequently require the efforts of more than one programmer. Having everyone work on the same source file, or even on their own copy of the same source file is unmanageable.

C supports the notion of **modular programming** in that it does not require that all the statements for a particular program be contained in a single file. This means that you can enter your code for a particular module into one file, for another module into a different file, and so on. Here, the term **module** refers either to a single function or to a number of related functions that you choose to group logically.

## 14.2 Communication between modules

Several methods can be used so that the **modules** contained in separate files can effectively communicate. If a function from one file needs to call a function contained inside another file, the function call can be made in the normal fashion, and arguments can be passed and returned in the usual way. Of course, in the file that calls the function, you should always make certain to include a prototype declaration so the compiler knows the function's argument types and the type of the return value.

Even though more than one **module** might be specified to the compiler at the same time on the command line, the compiler compiles each **module** independently. That means that no knowledge about structure definitions, function return types or function argument types is shared across **module** compilations by the compiler. It's totally up to you to ensure that the compiler has sufficient information about such things to correctly compile each **module**.

## 14.3 External variables

Functions contained in separate files can communicate through **external variables**. 

An **external variable** is one whose value can be accessed and changed by another **module**. Inside the **module** that wants to access the **external variable**, the variable is declared in the normal fashion and the keyword `extern` is placed before the declaration. This signals to the system that a globally defined variable from another file is to be accessed.

Suppose you want to define a variable you wnat to access and possibly modify from within a function contained in another file:

```c
int moveNumber = 0;
```

This statement outside of any function makes the variable `moveNumber` global. Specifically, not just global but also **external**. To reference the value of an **external** global variable from another module, you must declare the variable to be accessed, as follows:

```c
extern int moveNumber;
```

The value of `moveNumber` can now be accessed and modified by the module in which the preceding declaration appears. Other modules can also access the value of `moveNumber` by incorporating a similar `extern` declaration in the file.

There is one important rule when working with **external variables**. The variable has to be defined in some place among your source files, this is done in two ways.

The first way is to declare the variable outside of any function, not preceded by the keyword `extern`, as follows:

```c
int moveNumber; // It can also be initialized.
```

The second way to define an **external variable** is to declare the variable outside of any function, placing the keyword `extern` in front of the declaration, and explicitely assigning an initial value to it, as follows:

```c
extern int moveNumber = 0;
```

These two ways are mutually exclusive.

## 14.4 Static Versus Extern Variables and Functions

Many situations arise in which you want to define a variable to be global but not `external`. In other words, you want to define a global variable to be local to a particular module (file). It makes sense to want to define a variable this way if no function other than those contained inside a particular file need access to the particular variable. This can be accomplished in C by defining the variable to be `static`.

The statement:

```c
static int moveNumber = 0;
```

If made outside of any function, makes the value of `moveNumber` accessible from any subsequent point in the file in which the definition appears, but not from functions contained in other files.

When a function is defined, it can be declared to be `extern` or `static`, the former case being the default. A `static` function can be called only from within the same file as the function appears. 

This is a cleaner approach to programming, the `static` declaration more accurately reflects the variable's and function's usage and no conflicts can be created by two modules that unknowingly both use different `external` global variables of the same name.

## 14.5 Using header files effectively

You can group all your commonly used definitions inside such a file and then simply include the file in any program that needs to use those definitions. Nowhere is the usefulness of the `#include` facility greater than in developing programs that have been divided into separate program **modules**.

If more than one programmer is working on developing a particular program, include files provide a means of standardization: Each programmer is using the same definitions, which have the same values. Furthermore, each programmer is thus spared the time-consuming and error-prone task of typing these definitions into each file that must use them. 

These last two points are made even stronger when you start placing common structure definitions, external variable declarations, typedef definitions, and function prototype declarations into include files. Various modules of a large programming system invariably deal with common data structures. 

By centralizing the definition of these data structures into one or more include files, you eliminate the error that is caused by two **modules** that use different definitions for the same data structure. Furthermore, if a change has to be made to the definition of a particular data structure, it can be done in one place only—inside the include file.
