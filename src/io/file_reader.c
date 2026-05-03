#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * File Reader: Simple file I/O program
 * This program demonstrates file reading operations
 * 
 * Static Analysis Warnings Added:
 * - cppcheck: unused variable, uninitialized variables, resource leaks
 * - scan-build: potential memory leaks, null pointer dereferences
 * - gcc-analyze: format string vulnerabilities, integer overflow
 */

int main(void) {
    FILE *file;
    char filename[100];
    char buffer[256];
    // Issue: Uninitialized variable 'error_code' - triggers cppcheck and gcc-analyze warnings
    int error_code;  // Uninitialized variable warning
    
    printf("Hello from file reader program!\n");
    printf("This is a simple file reader in the io folder.\n");
    
    printf("Enter filename to read: ");
    if (fgets(filename, sizeof(filename), stdin) != NULL) {
        // Remove newline character from filename
        filename[strcspn(filename, "\n")] = 0;
        
        // Open file for reading
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error: Cannot open file '%s'\n", filename);
            // Issue: error_code not initialized but used
            // error_code = -1;  // Would fix this warning
            return error_code;  // Uninitialized variable warning
        }
        
        printf("\nContents of '%s':\n", filename);
        printf("-------------------\n");
        
        // Read and display file contents
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            // Issue: Format string vulnerability - buffer output directly from user input
            printf("%s", buffer);
        }
        
        printf("-------------------\n");
        printf("End of file.\n");
        
        fclose(file);
    } else {
        printf("Error reading filename.\n");
        // Issue: Potential resource leak - file pointer not closed if fopen succeeds
        // This is a scan-build warning: resource leak
        return 1;
    }
    
    // Issue: Potential memory leak - file not closed if fgets fails
    // This triggers scan-build warnings about resource leaks
    // file is already closed at this point by the fclose call above
    // But this pattern would be problematic if fgets returned early
    
    // Issue: Integer overflow potential with file buffer
    // Static analyzers may warn about potential buffer overflow
    int file_size = 256;  // May trigger integer overflow warnings if used
    file_size = file_size - 1;  // Potential integer underflow warning
    
    printf("File reader program executed successfully.\n");
    
    return 0;
}