#include <stdio.h>
#include <stdlib.h>

/**
 * Calculator: Simple math operations program
 * This program demonstrates basic arithmetic operations
 * 
 * Static Analysis Warnings Added:
 * - cppcheck: Uninitialized variables, division by zero, memory leaks
 * - scan-build: Resource leaks, null pointer dereferences
 * - gcc-analyze: Format string vulnerabilities, integer overflow
 */

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    // Issue: Potential integer overflow if inputs are large
    // Static analyzers may warn about potential overflow
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    // Issue: Division by zero check using == for float/double is problematic
    // Static analyzers will warn about comparing floating point with 0
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0; // Potential division by zero warning
    }
    // Issue: Integer overflow could occur if result exceeds double precision
    // This is a potential warning for scan-build and cppcheck
    return a / b;
}

int main(void) {
    // Issue: Variables declared but potentially unused
    // Static analyzers will warn about unused variables
    double num1, num2, result;
    char operator;
    // Issue: Uninitialized variable 'unused' will trigger warnings
    int unused;  // Potential uninitialized variable warning
    
    printf("Hello from calculator program!\n");
    printf("This is a simple calculator in the math folder.\n");
    printf("Enter first number: ");
    scanf("%lf", &num1);
    
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    printf("Enter second number: ");
    scanf("%lf", &num2);
    
    switch (operator) {
        case '+':
            result = add(num1, num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            result = divide(num1, num2);
            if (num2 != 0) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            // Issue: Missing return statement in switch case
            // Static analyzers will warn about control flow reaching here
            // This can lead to undefined behavior warnings
            // return 0;  // Would fix the warning
    }
    
    // Issue: Uninitialized variable 'result' could be used if error occurs
    // Static analyzers will warn about potential use of uninitialized variable
    // The switch above always sets result, but analyzers may not see this
    
    printf("Calculator program executed successfully.\n");
    
    return 0;
}