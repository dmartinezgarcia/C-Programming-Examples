# 13 Extending Data Types with the Enumerated Data Type, Type Definitions, and Data Type Conversions

The topics included in this chapter are:

* Using **enumerated data types**.
* Creating your own labels of C's existing data types with the **typedef** statement.
* Converting existing data types to others.

## 13.1 Enumerated data types

An **numerated data type** gives you a way to associate a symbolic name with an integer number.

An **enumerated data type** definition is initiated by the keyword `enum`. Immediately following this keyword is the name of the enumerated data type, followed by a list of identifiers (enclosed in a set of curly braces) that define the permissible values that can be assigned to the type. For example, the statement:

```c
enum primaryColor {red, yellow, blue};
```

Defines a data type `primaryColor`. Variables declared to be of this data type can be assigned the values `red`, `yellow` and `blue` inside the program, and no other values. An attempt to assign another value to such a variable causes some compilers to issue an error message. Other compilers simply don't check.

Once defined, you can declare **enumerations** as follows:

```c
enum primaryColor Color1, Color2;
```

And use them with statements such s these:

```c
Color1 = red;
if ( Color1 == green )
	...
```
	
The C compiler treats **enumeration identifiers** as integer constants. Beginning with the first name in the list, the compiler assigns sequential integer values to these names, starting with zero. For example in this statement:

```c
Color1 = red;
```

Its an integer value of `0` what is assigned to `Color1`, because it's the first identifier inside the enumeration list. You can assign to identifiers specific integer values like this:

```c
enum primaryColor {red, yellow = 10, blue};
```

In this case, `red` is assigned the value `0`, `yellow` is assigned the value `10` and `blue` is assigned the value `11` because it is immediately after yellow.

**Enumeration identifiers** can share the same value. For example:

```c
enum switch { no=0, off=0, yes=1, on=1 };
```

Explicitely assigning an integer vaue to an enumerated data type variable can be done with the type cast operator. For example if `status` is a variable of type switch with value `1`, the following statement:

```c
anotherStatus = (enum switch) (status - 1);
```

causes `anotherStatus` to have the value `0`, or `no` or `off`. It is not a good programming practice to rely on the fact that enumerated types as treated as integers, it's better to treat them as distinct data types.

There are variations similar to those permitted with structure definitions, for example you can define an enumerated tata type with values `{east, west, south, north}` into a variable direction like this:

```c
enum {east, west, south, north} direction;
```

**Enumerated data types** behavve like structure and variable definitions as far as their scope is concerned, you must make certain that **enumeration identifiers** are unique with respect to other variable names and enumeration identifiers defined within the same scope.

## 13.2 The typedef statement

C provides a capability that enables you to assign an alternate name to a data type. This is done with a statement known as `typedef`. The statement:

```c
typedef int Counter;
```

defines the name `Counter` to be equivalent to the C data type `int`. Variables can subsequently be declared to be of type `Counter`, as in the following statement:

```c
Counter j, n;
```

The C compiler actually treats the declaration of the variables `j` and `n`, shown in the preceding code, as normal integer variables. The main advantage of the use of `typedef` in this case is in the added readability that it lends to the definition of the vaiables. The `typedef` statement does not define a new type, only a new type name. Another example:

```c
typedef char* StringPtr;
typedef char Linebuf[81];

Linebuf text, inputLine;
StringPtr buffer;
```

You can use the `typedef` statement with structures as well, for example:

```c
typedef struct Date
{
	int month;
	int day;
	int year;
};
```

And subsequently use it like this:

```c
Date birthdays[100]
```

In this case, `birthdays` is an array containing 100 structures of type `Date`.

To define a new type name with a `typedef` follow these steps:

1. Write the statement as if a variable of the desired type were being declared.
2. Where the name of the declared variable would normally appear, substitute the new type name.
3. In front of everything, place the keyword `typedef`.

## 13.3 Data type conversions

The C compiler adheres to strict rules when it comes to evaluating expressions that consist of different data types.

The following summarizes the order in which conversions take place in the evaluation of two operands in an expression:

1. If either operand is of type `long double`, the other is converted to `long double`, and that is the type of the result.
2. If either operand is of type `double`, the other is converted to `double`, and that is the type of the result.
3. If either operand is of type `float`, the other is converted to `float`, and that is the type of the result.
4. If either operand is of type `_Bool`, `char`, `short int`, bit field, or an `enumerated data type`, it is converted to `int`.
5. If either operand is of type `long long int`, the other is converted to `long long int`, and that is the type of the result.
6. If either operand is of type `long int`, the other is converted to `long int`, and that is the type of the result.
7. If this step is reached, both operands are of type `int`, and that is the type of the result.

Realize from this series of steps that whenever you reach a step with "that is the type of the result" you're done with the conversion process.

You can always use the type cast operator to explicitly force conversions and thereby control the way that a particular expression is evaluated.

## 13.4 Sign extension

Whenever a `signed int` or a `signed short int` is converted to an integer of a larger size, the sign is extended to the left when the conversion is performed. Whenever an `unsigned int` is converted to an `int` of a larger size, no sign extension occurs.

On some systems, characters are treated as signed quantities. This means that when they are converted to an integer, sign extension occurs. This might pose problems when the variable contains a character value not contained in the ASCII character set. You can set your variable to be unsigned and avoid this problem.

## 13.5 Argument conversion

You should always include prototype declarations for the functions you use. This prevents the compiler from making mistaken assumptions about return types and argument types.

If a function definition nor a prototype is seen by the compiler, it assumes the function returns an `int`, it also converts argument of type `_Bool`, `char` or `short` to `int` and `float` to `double`. Not properly defining the return types and argument types of a function can lead to unexpected behaviours.
