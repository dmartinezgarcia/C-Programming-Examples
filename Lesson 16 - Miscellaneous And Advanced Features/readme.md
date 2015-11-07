# 16. Miscellaneous and Advanced Features

Topics covered in this chapter include:

* Understanding the **goto** statement, and why you should avoid it.
* Maximizing space by using **unions**.
* Adding the **null statement** to your programs.
* Implementing statements that include the comma operator.
* Using **command-line arguments** with your programs.
* Dynamically allocating memory with `malloc()` and `calloc()`, and cleaning it up with `free()`.

## 16.1 The goto statement

Execution of the **goto** statement causes a direct branch to be made to a specified point in the program. This branch is made immediately and unconditionally upon execution of the **goto**. To identify where in the program the branch is to be made, a **label** is needed. 

A **label** is a name that is formed with the same rules as variable names and must be immediately followed by a colon. The label is placed directly before the statement to which the branch is to be made and must appear in the same function as the **goto**.

So, for example, the statement:

```c
goto out_of_data;
```

causes the program to branch immediately to the statement that is preceded by the label `out_of_data:`. This label can be located anywhere in the function, before or after the **goto**, and might be used as shown:

```c
out_of_data: printf("Unexpected end of data.\n");
```

The **goto** statement interrupts the normal sequential flow of a program, as a result, programs are harder to follow. As such, this style of programming is often derisively referred to as spaghetti code. The **goto** statements are not considered part of good programming style.

## 16.2 The null statement

C permits a solitary semicolon to be placed wherever a normal program statement can appear. The effect of such a statement, known as the **null statement**, is that nothing is done. For example:

```c
while ( (*to++ = *from++) != \0 )
	;
```

The **null statement** is needed because the compiler takes the statement that follows the looping expression as the body of the loop. Without the **null statement**, whatever statement that follows in the program is treated as the body of the program loop by the compiler.

The reader is advised that there is a tendency among certain programmers to try to squeeze as much as possible into the condition part of the while or into the condition or looping part of the for. Try not to become one of those programmers. In general, only those expressions involved with testing the condition of a loop should be included inside the condition part. Everything else should form the body of the loop. The only case to be made for forming such complex expressions might be one of execution efficiency. Unless execution speed is that critical, you should avoid using these types of expressions.

The preceding while statement is easier to read when written like this:

```c
while ( *from != '\0' )
    *to++ = *from++;
*to = '\0';
```

## 16.3 Working with unions

An unusual construct in the C programming language is the **union**. This construct is used mainly in more advanced programming applications in which it is necessary to store different types of data in the same storage area. Unions syntax and rules are identical to structs, only diferring in the way memory is allocated.

If you want to define a single variable called `x`, which could be used to store a single character, a floating-point number, or an integer, you could first define a **union** `mixed` like this:

```c
union mixed
{
	char c;
	float f;
	int i;
};
```

The following statement:

```c
union mixed x;
```

defines `x` to contain a single member that is called either `c`, `f`, or `i`. In this way the variable `x` can be used to store either a `char`, a `float` or an `int`, but not all three or even two of the three. You can use the following statement as examples about how to store variables:

```c
x.c = 'K';
x.f = 786.3869;
x.i = count / 2;
```c

Only one value can be stored at a time, and is the programmer's responsibility to ensure that the value retrieved from a union is consistent with the way it was last stored in the union.

**Unions** can be defined to contain as many member as desired, the C compiler ensures that enough storage is allocated to accommodate the largest member of the **union**. Structures can be define that contain **unions**, as can arrays. When defining a **union**, the name of the **union** is not required and variables can be declared at the same time the **union** is defined. 

Pointers to **unions** can also be declared and their syntax and rules for performing operations are the same as for structures.

## 16.4 The comma operator

The **comma operator** can be used to separate multiple expressions anywhere that a valid C expression can be used. The expressions are evaluated from left to right.

Because all operators in C produce a value, the value of the **comma operator** is that of the rightmost expression.

Note that a comma, used to separate arguments in a function call, or variable names in a list of declarations, for example, is a separate syntactic entity and is not an example of the use of the **comma operator**.

## 16.5 The register type qualifier

If a function that uses a particular variable heavily, you can request that access to the variable be made as fast as possible by the compiler. 

Tipically, this means requesting that it be stored in one of the machine's registers when the function is executed. This is done by prefixing the declaration of the variable by the keyword `register`, as follows:

```c
register int index;
register char *textPtr;
```

Both local variables and formal parameters can be declared as `register` variables. The types of variables that can be assigned to **registers** vary among machines. The basic data types can usually be assigned to registers, as well as pointers to any data type.

Even if your compiler enables you to declare a variable as a register variable, it is still not guaranteed that it will do anything with that declaration. It is up to the compiler.

You might want to also note that you cannot apply the address operator to a register variable. Other than that, register variables behave just as ordinary automatic variables.

## 16.6 The volatile type qualifier

The `volatile` qualifier is sort of the inverse to `const`. It tells the compiler explicitly that the specified variable will change its value. It's included in the language to prevent the compiler from optimizing away seemingly redundant assignments to a variable, or repeated examination of a variable without its value seemingly changing. 

A good example is to consider an I/O port. Suppose you have an output port that's pointed to by a variable in your program called `outPort`. If you want to write two characters to the port, for example an `O` followed by an `N`, you might have the following code:

```c
*outPort = 'O';
*outPort = 'N';
```

A smart compiler might notice two successive assignments to the same location and, because `outPort` isn't being modified in between, simply remove the first assignment from the program. To prevent this from happening, you declare `outPort` to be a `volatile` pointer, as follows:

```c
volatile char *outPort;
```

## 16.7 The restrict type qualifier

Like the `register` qualifier, restrict is an optimization hint for the compiler. As such, the compiler can choose to ignore it. It is used to tell the compiler that a particular pointer is the only reference (either indirect or direct) to the value it point to throughout its scope. That is, the same value is not referenced by any other pointer or variables within that scope.

The lines:

```c
int* restrict intPtrA;
int* restrict intPtrB;
```

tell the compiler that, for the duration of the scope in which `intPtrA` and `intPtrB` are defined, they will never access the same value. Their use for pointing to integers inside an array, for example, is mutually exclusive.

## 16.8 Command-line arguments

You can supply information to the program at the time the program is executed. This capability is provided by what is known as **command-line arguments**.

The only distinguishing quality of the function `main()` is that its name is special, it specifies where program execution is to begin. In fact, the function `main()` is actually called upon at the start of program execution by the C system (known more formally as the runtime system), just as you call a function from within your own C program. When `main()` completes execution, control is returned to the runtime system, which then knows that your program has completed execution.

When `main()` is called by the runtime system, two arguments are actually passed to the function:

* The first argument (`argc` by convention), is an `integer` value that specifies the number of arguments typed on the command line. 
* The second argument to `main()` is an array of character pointers, which is called `argv` by convention (for argument vector). There are `argc + 1` character pointers contained in this array, where `argc` always has a minimum value of 0. The first entry in this array is a pointer to the name of the program that is executing or is a pointer to a null string if the program name is not available on your system. Subsequent entries in the array point to the values that were specified in the same line as the command that initiated exection of the program. The last pointer in the `argv` array, `argv[argc]`, is defined to be null.

To access the command-line arguments, the `main()` function must be appropriately declared as taking two arguments. The conventional delaration that is used appears as follows:

```c
int main (int argc, char* argv[])
{
	...
}
```

For example, if a program called copy was executed from the command line with the following statement:

```
copyf foo foo1
```

then the argv array would look like this when the main is entered.

![IMG01.png](https://raw.githubusercontent.com/dmartinezgarcia/C-Programming-Examples/master/Lesson%2016%20-%20Miscellaneous%20And%20Advanced%20Features/IMG01.png)


## 16.9 Dynamic Memory Allocation

Whenever you define a variable in C, whether it is a simple data type, an array or a structure, you are effectively reserving one or more locations in the computer's memory to contain the values that will be stored in that variable. The C compiler automatically allocates the correct amount of storage for you.

It is frequently desirable to be able to dynamically allocate storage while a program is running. There are many ways, but using **dynamic memory allocation** functions you can get storage as you need it. That is, this approach enables you to allocate memory as the program is executing. To use **dynamic memory allocation**, you must first learn about three functions and one new operator.

### 16.9.1 The calloc() and malloc() functions

In the standard C library, two function, called `calloc()` and `malloc()`, can be used to allocate memory at runtime.

The `calloc()` functions takes two arguments that specify the number of elements to be reserved and the size of each element in bytes. The function returns a pointer to the beginning of the allocated storage area in memory. The storage area is also automatically set to zero.

The `calloc` function returns a pointer to `void`, which is C's generic pointer type. Before storing this returned pointer inside a pointer variable in your program, it can be converted into a pointer of the appropiate type using the type cast operator.

The `malloc()` function works similarly, except that it only takes a single argument, the total number of bytes of storage to allocate, and also doesn't automatically set the storage area to zero. 

The **dynamic memory allocation** functions are declared in the standard header file `<stdlib.h>`, which should be included in your program whenever you want to use these routines.

### 16.9.2 The sizeof operator

To determine the size of data elements to be reserved by `calloc()` or `malloc()` in a machine-independent way, the C `sizeof` operator should be used. The `sizeof` operator returns the size of the specified item in bytes. 

The argument of the `sizeof` operator can be a variable, an array name, the name of a basic data type, the name of a derived data type, or an expression. Examples of the `sizeof` statement:

```c
sizeof(int)
sizeof(struct dataEntry)
```

If data is defined as an array of struct `dataEntry` elements, the expression:

```c
sizeof (data) / sizeof (stuct dataEntry)
```

gives the number of elements contained in `data`, provided `data` is a previously defined array.

Unless a variable-length array is used in its argument, the `sizeof` operator is evaluated at compile time and not at runtime. The compiler evaluates the value of the `sizeof` expression and replaces it with the result of the calculation, which is treated as a constant. Use the `sizeof` operator wherever possible to avoid having to calculate and hard-code sizes into your program.

Getting back to **dynamic memory allocation**, if you want to allocate enough storage in your program to store one thousand integers, you can call `calloc()` as follows:

```c
int* intPtr;

intPtr = (int*) calloc (sizeof (int), 1000);

Using malloc(), the function call looks like this:

intPtr = (int*) malloc (1000 * sizeof (int));
```

Both `malloc()` and `calloc()` return a pointer to `void`, this pointer should be type cast to the appropiate pointer type, in this case `(int*)`. 

If you ask for more memory than the system has available, `calloc()` or `malloc()` returns a null pointer, be certain to test the pointer that is returned to ensure that the allocation succeeded.

### 16.9.3 The free function

When you have finished working with the memory that has been dynamically allocated by `calloc()` or `malloc()`, you should give it back to the system by calling the `free()` function. The single argument to the function is a pointer to the beginning of the allocated memory, as returned by a `calloc()` or `malloc()` call. So the call `free()` in these statements:

```c
struct dataEntry  *dataPtr;
dataPtr = (struct dataEntry *) calloc (n, sizeof (struct dataEntry));
free(dataPtr);
```

returns the memory allocated by the `calloc()` call shown previously, provided that the value of `dataPtr` points to the beginning of the allocated memory. Make sure you give the `free()` function a valid pointer to the beginning of some previously allocated space.

The memory that is released by `free()` can be reused later by a call to `calloc()` or `malloc()`. For programs that need to allocate more storage space than would otherwise be available if it were all allocated at once, this is worth remembering.

**Dynamic memory allocation** is invaluable when dealing with linked structures, such as linked lists. Another function, called `realloc()`, is associated with dynamic memory allocation, it can be used to shrink or expand the size of some previously allocated storage.
