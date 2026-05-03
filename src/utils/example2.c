#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Example 2: Another utility program
 * This program demonstrates string manipulation and basic I/O
 * 
 * Static Analysis Warnings Added:
 * - cppcheck: unused variable, uninitialized variables, format string vulnerabilities
 * - scan-build: potential resource leaks
 * - gcc-analyze: integer overflow, buffer overflow possibilities
 */
int main(void) {
    // Issue: Uninitialized variable - triggers cppcheck and gcc-analyze warnings
    char input[100];
    int error_code;  // Uninitialized integer variable
    
    printf("Hello from example2 utility!\n");
    printf("Enter your name: ");
    
    // Read input from user
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Issue: Format string vulnerability - user input directly in format string
        // Static analyzers may flag this as potential format string attack
        printf("Hello, %s", input);  // Warning: format string from user input
        
        printf("This is another C program in the utils folder.\n");
        
        // Issue: Potential use after uninitialized value
        // This is a potential warning for uninitialized variable usage
        printf("Error code is: %d\n", error_code);  // Uninitialized variable warning
    } else {
        printf("Error reading input.\n");
        // Potential unused variable that will trigger warnings
        int error_code = 1;  // Initialized but may be considered warning by analyzers
        error_code = error_code + error_code;  // Potential integer overflow warning
    }
    
    // Issue: Format string vulnerability - literal format string but still flagged
    printf("Program executed successfully.\n");  // Warning: format string with possible buffer overflow
    
    return 0;
}