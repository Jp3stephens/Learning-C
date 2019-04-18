** A #define line** defines a symbolic name or symbolic constant to be a particular string of characters:

* **#define name replacement_text* 

Thereafter, any occurrence of name (not in quotes and not part of another name) will be replaced by the corresponding replacement text. The name has the same form as a variable name: a sequence of letters and digits that begins with a letter. The replacement text can be any sequence of characters; it is not limited to numbers.

The quantities LOWER, UPPER and STEP are symbolic constants, not variables, so they do not appear in declarations. Symbolic constant names are conventionally written in upper case so they can be readily distinguished from lower case variable names. Notice that there is no semicolon at the end of a Idefine line.

**Character I/0**

The model of input and output supported by the standard library is very simple. Text input or output, regardless of where it originates or where it goes to, is dealt with as streams of characters, A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character. It is the responsibility of the library to make each input or output stream conform to this model; the C programmer using the library need not worry about how lines are represented outside the program.

The standard library provides several functions for reading or writing one character at a time, of which getchar and putchar are the simplest. Each time it is called, getchar reads the next input character from a text stream and returns that as its value. That is, after

 c = getchar () 

the variable c contains the next character of input. The characters normally come from the keyboard; input from files is discussed in Chapter 7. The function putchar prints a character each time it is called:

putchar(c)

 prints the contents of the integer variable c as a character, usually on the screen. Calls to putchar and printf may be interleaved; the output will appear in the order in which the calls are made

**Functions**

A function definition has this form

	return-type function-name (parameter declarations, if any)

	{

	Declarations

	Statements

	}

Function definitions can appear in any order, and in one source file or several, although no function can be split between files

**Arguments - Call by Value**

One aspect of C functions may be unfamiliar to programmers who are used to some other languages, particularly Fortran. In C, all function arguments are passed "by value." This means that the called function is given the values of its arguments in temporary variables rather than the originals. This leads to some different properties than are seen with "call by reference" languages like Fortran or with var parameters in Pascal, in which the called routine has access to the original argument, not a local copy. The main distinction is that in C the called function cannot directly alter a variable in the calling function;it can only alter its private, temporary copy. Call by value is an asset, however, not a liability. It usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine

When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the address of the variable to be set (technically a pointer to the variable), and the called function must declare the parameter to be a pointer and access the variable indirectly through it

The story is different for arrays. When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array-there is no copying of array elements. By subscripting this value, the function can access and alter any element of the array

**Character Arrays**

getline puts the character ' \0' (the null character, whose value is zero) at the end of the array it is creating, to mark the end of the string of characters. This convention is also used by the C language: when a string constant like 

	"Hello\n"

appears in a C program, it is stored as an array of characters containing the characters of the string and terminated with a ' \0' to mark the end.

	

<table>
  <tr>
    <td>H</td>
    <td>e</td>
    <td>l</td>
    <td>l</td>
    <td>o</td>
    <td>\n</td>
    <td>\0</td>
  </tr>
</table>


The %s format specification in printf expects the corresponding argument to be a string represented in this form. copy also relies on the fact that its input argument is terminated by , \0', and it copies this character into the output argument. (All of this implies that ' \0' is not a part of normal text.) 

**External Variables and Scope**

The variables in main, such as line, longest, etc., are private or local to main. Because they are declared within main, no other function can have direct access to them. The same is true of the variables in other functions; for example, the variable i in getline is unrelated to the i in copy. Each local variable in a function comes into existence only when the function is called, and disappears when the function is exited. This is why such variables are usually known as automatic variables, following terminology in other languages. We will use the term automatic henceforth to refer to these local variables

Because automatic variables come and go with function invocation, they do not retain their values from one call to the next, and must be explicitly set upon each entry. If they are not set, they will contain garbage. As an alternative to automatic variables, it is possible to define variables that are external to all functions, that is, variables that can be accessed by name by any function. 

 Because external variables are globally accessible, they can be used instead of argument lists to communicate data between functions. Furthermore, because external variables remain in existence permanently, rather than appearing and disappearing as functions are called and exited, they retain their values even after the functions that set them have returned. An external variable must be defined, exactly once, outside of any function; this sets aside storage for it. The variable must also be declared in each function that wants to access it; this states the type of the variable. The declaration may be an explicit **extern** statement or may be implicit from context.

 Syntactically, external definitions are just like definitions of local variables, but since they occur outside of functions, the variables are external. Before a function can use an external variable, the name of the variable must be made known to the function. One way to do this is to write an extern declaration in the function; the declaration is the same as before except for the added keyword **extern**.

In certain circumstances, the extern declaration can be omitted. If the definition of an external variable occurs in the source file before its use in a particular function, then there is no need for an extern declaration in the function. 

* In fact, common practice is to place definitions of all external variables at the beginning of the source file, and then omit all extern declarations.

If the program is in several source files, and a variable is defined in *file1* and used in* file 2* and *file3*, then **extern** declarations are needed in *file2* and *file3* to connect the occurrences of the variable. The usual practice is to collect **extern** declarations of variables and functions in a separate file, historically called a header, that is included by #include at the front of each source file. The suffix .h is conventional for header names. The functions of the standard library, for example, are declared in headers like <stdio.h>.

You should note that we are using the words *definition *and *declaration* carefully  when we refer to external variables in this section. **"Definition"** refers to the place where the variable is created or assigned storage; **"declaration"** refers to places where the nature of the variable is stated but no storage is allocated.

* By the way, there is a tendency to make everything in sight an **extern** variable because it appears to simplify communications - argument lists are short and variables are always there when you want them. But external variables are always there even when you don't want them. Relying too heavily on external variables is fraught with peril since it leads to programs whose data connections are not at all obvious-variables can be changed in unexpected and even inadvertent ways, and the program is hard to modify.

