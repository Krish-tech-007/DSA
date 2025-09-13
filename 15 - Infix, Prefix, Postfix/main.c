#include <stdio.h>
#include <stdlib.h>


// Notations to write an expression
// Infix - Left Operator Right
// Prefix - Operator Left Right
// Postfix - Left Right Operator

/*
Example:
Infix: A*(B+C)*D

Postfix:
A * (BC+) * D
ABC+* * D
ABC+*D*

Prefix:
A*(+BC)*D
*(A+BC) * D
**A+BCD

*/

/*
Need for postfix
Computer needs to evaluate expression based on operator precedence
In the case of infix expression, to evaluate, it must iterate the expression several times
That is not required in the case of postfix expression

Example postfix expression: ABC+*D*
It will iterate till it encounters an operator, it then performs that operation for the previous two operands and substitutes the value
Hence the machine will iterate the expression only once
*/

/*
Converting from infix to prefix and postfix
1. Operator precedence is taken into consideration
2. Prefix - Operator Left Right and Postfix - Left Right Operator

Tips:
1. Parenthesize the expression according to precedence rules
2. Enclose result in [] to indicate single unit, for understanding only, remove while operating
*/

int main()
{
    return 0;
}
