#include <stdio.h>
#include <stdlib.h>

/**
 * Example 1: Simple utility program
 * This program demonstrates basic C programming concepts
 * 
 * Static Analysis Warnings:
 * - cppcheck: unused variable, uninitialized variables
 * - scan-build: potential resource leaks
 * - gcc-analyze: format string vulnerabilities
 */
int main(void) {
    // Issue: Uninitialized variable - triggers cppcheck and gcc-analyze warnings
    char buffer[256]; // Uninitialized - static analyzers will warn
    
    printf("Hello from example1 utility!\n");
    printf("This is a simple C program in the utils folder.\n");
    
    // Print some system information
    printf("Program executed successfully.\n");
    
    // Issue: Unused variable - triggers cppcheck warnings
    int unused_var = 42;
    
    // Issue: Integer overflow potential
    // Static analyzers will warn about potential overflow if these values are very large
    unsigned int val1 = 2147483646; // UINT_MAX - 2
    unsigned int val2 = 5;
    unsigned int overflow_result = val1 + val2; // May trigger warnings
    
    return 0;
}