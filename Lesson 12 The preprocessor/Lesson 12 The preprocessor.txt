# 12 The preprocessor

This chapter describes another unique feature of the C language that is not found in many other higher-level programming languages. The C **preprocessor** provides the tools that enable you to develop programs that are easier to read, to modify, to develop and to port to different computer systems. This chapter covers:

* Creating your own constants and macros with the `#define` statement.
* Building your own library files with the `#include` statement.
* Making more powerful programs with the conditional `#ifdef`, `#endif`, `#else` and `#ifndef` statements.

The **preprocessor** analyzes the statements before the analysis of the C program itself takes place. The **preprocessor** statements are identified by the presence of a hash key, `#`, which must be the first nonspace character on the line.

## 12.1 The #define statement

One of the primary uses of the `#define` statement is to assign symbolic names to program constants. For example:

```c
#define	YES	1
```

Defines the name `YES` and makes it equivalent to the value `1`. After a name has been defined in a program, either inside or outside a function. it can be used anywhere in the program, what is required is that a name be defined before it is referenced by the program.

Whenever a defined name is used in a program, whatever appears to the right of the defined name in the `#define` statement gets automatically substituted in the program by the preprocessor. It's analogous to doing a search and replace with a text editor, in this case the preprocessor replaces all ocurrences of the defined name with its associated text. Examples of this:

```c
int variable = YES;

if (variable == YES)
	...
```

A defined name is not a variable, you cannot assign a value to it unless the result of substituting the defined value is a variable.
	
The `#define` statements are usually grouped at the beginning of the program or inside an include file, where they can be quickly referenced and shared by more than one source file.

Define statements are usually written in capital letters so they can be distinguished from a variable. Another convention is to prefix the defined value with the letter k, for example:

```c
#define kYes	1
```

Common examples of defines are the number `PI` or the `NULL` pointer. Assigning constants symbolic names frees you from having to remember the particular constant value every time you want to use it in the program.

### 12.1.1 Program extendability

Using a defined name for a constant value helps to make programs more readily extendable. A common example is using, for example, a defined constant to set the upper bound in an array:

```c
#define	MAXIMUM_DATAVALUES	1000
```

Suppose the following statements:

```c
float dataValues[MAXIMUM_DATAVALUES];

for (i = 0; i < MAXIMUM_DATAVALUES; i++)
	...

if (index > MAXIMUM_DATAVALUES - 1)
	...
```

If you wished to increase the number of items in the array, you would just need to change the defined constant, like this:

```c
#define	MAXIMUM_DATAVALUES 2000
```

In case you didn't define the constant with a symbolic name, you would need to change each number manually.

### 12.1.2 Program portability

Another nice use of the `#define` statement is that it helps to make programs more portable from one computer system to another. It might be necessary to use constant values that are related to the particular computer on which the program is running. This might have to do with the use of a particular memory address, a filename, the number of bits contained in a computer word... For example:

```c
#define	kIntSize	32	// *** Machine Dependent !!! ***
```

But in this case it would be even more portable to make a function that determines the number of bits in an integer with no input from the user.

### 12.1.3 More advanced types of definitions

A definition for a name can include more than a simple constant value. It can include an expression, for example:

```c
#define TWO_PI	2.0 * 3.141592654
```

A **preprocessor** definition does not have to be a valid C expression in its own right, just as long as wherever it is used the resulting expression is valid. For example:

```c
#define	LEFT_SHIFT_8	<< 8
```

or:

```c
#define AND			&&
#define OR			||
#define EQUALS		==
```

However, it is bad practice to redefine the syntax of the underlying language in this manner. And it can make it harder for someone else to understand your code.

A defined value can itself reference another defined value:

```c
#define	PI	3.141592654
#define	TWO_PI	2.0 * PI
```

are perfectly valid. Reversing the order of the defines is also valid, you can reference other defined values in your definitions provided everything is defined at the same time the defined name is used in the program. For readability, it is suggested that you don't use a defined term until it has been defined though.

Good use of defines usually reduces the need for comments. Consider the following statement:

```c
if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	...
```

Now consider the following define and the following statement:

```c
#define	IS_LEAP_YEAR	 year % 4 == 0  &&  year % 100 != 0   \
						|| year % 400 == 0
if ( IS_LEAP_YEAR )
	...
```

Notice how a backslash character was used to signal the continuation of a second line to the preprocessor.

## 12.2 Arguments and Macros

In C, definitions are frequently called **macros**. This terminology is often applied to definitions that take one or more arguments. 

With **macros**, you do not need to express the type of the argument because you are merely performing a literal text substitution and not invoking a function. Consider a **macro** called `SQUARE` that squares its argument:

```c
#define	SQUARE(x)	x * x
```

This enables you to subsequently write statements such as:

```c
y = SQUARE (v);
```

In this example, the **macro** works for variables of any type (`int`, `long`, `float`), you would need multiple functions to achieve the same results. One consideration about **macro** definitions is that because they are substituted into the program by the **preprocessor**, they inevitably use more memory space than an equivalently defined function. On the other hand, because a function takes time to call and to return, this overhead is avoided when a macro definition is used instead.

It is sometimes necessary to add parentheses enclosing the **arguments** in **macros**, and the whole macro itself, for example with the macro above:

```c
SQUARE(v + 1)
```

Would be substituted by:

```c
y = v + 1 * v + 1;
```

If you redefine the **macro** like:

```c
#define SQUARE(x)	((x) * (x))
```

It would be substituted by:

```c
y = ((v + 1) * (v + 1));
```

Useful **macros** can be defined using the conditional operator, examples are the following:

```c
#define  MAX(a,b)   ( ((a) > (b)) ? (a) : (b) )
#define  IS_LOWER_CASE(x)  ( ((x) >= 'a') && ((x) <= 'z') )
```

### 12.2.1 Variable number of argument to macros

A **macro** can be defined to take an indeterminate or variable number of arguments. This is specified to the **preprocessor** by putting three dots at the end of the argument list. The remaining arguments in the list are collectively referenced in the macro definition by the special identifier `_ _VA_ARGS_ _`. For example the **macro** definition:

```c
#define debugPrintf(...)   printf ("DEBUG:" _ _VA_ARGS_ _);
```

And some of its uses:

```c
debugPrintf ("Hello world!\n");
// Output: DEBUG: Hello world!

debugPrintf ("i = %i, j = %i\n", i, j);
// Output: DEBUG: i = 100, j = 200
```

### 12.2.2 The # operator

If you place a hash key, #, in front of a parameter in a **macro** definition the **preprocessor** creates a constant string out of the macro argument when the macro is invoked. For example, the definition:

```c
#define	str(x)	#x
```

Causes the subsequent invocations:

```c
str(testing)
str("hello")
```

To be expanded into:

```c
"testing"
"\"hello\""
```

By the **preprocessor**. The **preprocessor** literally inserts double quotation marks around the actual **macro** argument. A more practical example of this is the following:

```c
#define printint(var)	printf(#var " = %i\n", var)
```

The following statement:

```c
printint(count);
```

expands to:

```c
printf("count" " = %i\n", count);
```

### 12.2.3 The ## operator

This operator is used in **macro** definitions to join two tokens together. 

It is preceded or followed by the name of a parameter to the macro. The **preprocessor** takes the actual **argument** to the macro that is supplied when the macro is invoked and creates a single token out of that argument and whatever token follows (or precedes) the ##.

Suppose you have one hundred variables, named `x1`, `x2`, `x3` and so on, also suppose the following definition:

```c
#define	test(n)	(x ## n)
```

The definition above is invoked like this:

```c
test(20)
```

This expands to:

```c
x20;
```

A practical use of the ## operator, in combination with the definition `printint` previously defined, is to get the variable name as well as its value displayed:

```c
#define	printx(n)	printint(x ## n)
```

This causes the invocation:

```c
printx(10)
```

to expand into:

```c
printf("x10 = %i\n", x10);
```

## 12.3 The #include statement

After you have programmed in C for a while, you will find yourself developing your own set of **macros** and **functions** that you will want to use in each of your programs. 

But instead of having to type these **macros** into each new program you write, the **preprocessor** enables you to collect all your definitions into a separate file and then include the file and all its macros and user defined functions in your programs, using the `#include` statement. These files normally end with the characters `.h` and are referred to as **header or include files**.

Suppose you are writing a series of programs for performing various metric conversions. Yog might want to set up some defines for all of the constants that you need to perform your conversions:

```c
#define  INCHES_PER_CENTIMETER   0.394
#define  CENTIMETERS_PER_INCH    1 / INCHES_PER_CENTIMETER

#define  QUARTS_PER_LITER        1.057
#define  LITERS_PER_QUART        1 / QUARTS_PER_LITER

#define  OUNCES_PER_GRAM         0.035
#define  GRAMS_PER_OUNCE         1 / OUNCES_PER_GRAM
```

Suppose you entered the previous definitions into a separate file on the system called `metric.h`, any program where you need these definitions you can include the `metric.h` file using the #include preprocessor directive:

```c
#include "metric.h"
```

This statement must appear before any of the defines contained in `metric.h` are referenced, usually at the beginning of the source file. 

The preprocessor looks for the specified file on the system and copies the contents of the file into the program at that precise point that the `#include` statement appears.

The double quotation marks around the include filename instruct the **preprocessor** to look for the specified file in one or more file directories (typically first in the same directory that contains the source file, but the actual places the preprocessor searches are system dependent). If the file isn't located, the preprocessor automatically searches other system directories.

Enclosing the filename within the characters < and > instead, as in:

```c
#include <stdio.>
```

causes the preprocessor to look for the include file in the special system include file directory or directories, which are system dependant.

One of the nicest things about the include file capability is that it enables you to centralize your definitions, but you can actually put anything you want in an include file. Using include files to centralize commonly used **preprocessor** definitions, structure definitions, prototype declarations and global variable declarations is a good programming technique.

Include files can be nested, an include file itself can include another file and so on.

## 12.4 Conditional compilation

The C **preprocessor** offers a feature known as **conditional compilation**. This is often used to reate one program that can be compiled to run on different computer systems. It is also often used to switch on or off various statements in the program, such as debugging statements that help trace the flow of program execution.

### 12.4.1 The #ifdef, #endif, #else, defined (), #elif and #ifndef statements

These statements behave as you would expect, its syntax is:

```c
#ifdef	WINDOWS
#	define SYSTEM	"WINDOWS"
#else
#	define SYSTEM	"LINUX"
#endif
```

The statement above is equal to:

```c
#if defined (WINDOWS)
#	defined SYSTEM	"WINDOWS"
#else
#	define	SYSTEM	"LINUX"
#endif
```

You can use logical operators or arithmetic operators in **preprocessor** statements, for example:

```c
#if		OS == 1
...
#elif	OS == 10 || defined (WINDOWSNT)
...
#elif	OS == 30
...
#else
...
#endif
```

### 12.4.2 Avoiding multiple inclusion of header files

A common use of the `#ifndef` statement is to avoid multiple inclusion of a file in a program. For a file called `"mystdio.h"`, you could use the following syntax:

```c
#ifndef	_MYSTDIO_H
#define	_MYSTDIO_H
	(All your statements)
#endif
```

Once the file has been included, the symbolic name `_MYSTDIO_H` is defined, and future attempts to include the file will fail, avoiding the multiple inclusion of the same file in a program.

## 12.5 The undef statement

You can undefine symbolic names using the #undef statement:

```c
#undef	LINUX.
```
